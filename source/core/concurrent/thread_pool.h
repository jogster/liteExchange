#ifndef _THREAD_POOL_H_
#define _THREAD_POOL_H_

#include <cstddef>
#include <atomic>
#include <vector>
#include <memory>
#include <thread>
#include <vector>

#include <boost/noncopyable.hpp>

#include <core/concurrent/task.h>
#include <core/concurrent/thread.h>
#include <core/concurrent/thread_pool_arguments.h>
#include <core/design_patterns/observer.hpp>
#include <core/concurrent/ring_buffer_spsc_lockfree.hpp>

namespace core
{

using ThreadPoolQueue = core::RingBufferSPSCLockFree<core::Task>;
using ThreadPoolQueuePtr = std::unique_ptr<ThreadPoolQueue>;

class ThreadPool : public boost::noncopyable, public core::Observable<core::ThreadPool>
{
    public :
        ThreadPool() : m_numOfThreads(0) { m_isShuttingDown.store(false); }
        ~ThreadPool() { shutdown(); }
        void initialise(const ThreadPoolArguments& args);
        void submitTask(const Task& task, std::size_t queueID);
        void shutdown();

    private:
        struct ThreadArgument
        {
            ThreadPool* m_threadPool = nullptr;
            unsigned int m_queueIndex = -1;
            ThreadArgument(ThreadPool* pool, unsigned int queueIndex) : m_threadPool(pool), m_queueIndex(queueIndex) {}
        };

        // Move ctor deletion
        ThreadPool(ThreadPool&& other) = delete;
        // Move assignment operator deletion
        ThreadPool& operator=(ThreadPool&& other) = delete;

        std::vector<ThreadPtr> m_threads;
        std::vector<ThreadArgument> m_threadArguments;
        std::vector<ThreadPoolQueuePtr>  m_threadQueues;

        unsigned int m_numOfThreads;
        std::atomic<bool> m_isShuttingDown;
        static void* workerThreadFunction(void* argument);
};

}//namespace
#endif