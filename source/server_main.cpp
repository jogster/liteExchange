#include <core/compiler/ignored_warnings.h>
// COMPILE TIME CHECKS
#include <core/compiler/cpp_version_check.h> // C++11 and later supported
#include <core/compiler/os_version_check.h>  // Linux and Windows supported

// RUNTIME CHECKS
#include <core/memory/cpu_memory.h>                      // To see if cache line we are running on
                                                    // matches the compiled one
#include <core/os_utility.h>                     // To check whether we are root/admin or not

#include <iostream>

#include <boost/format.hpp>

#include <core/single_instance.h>
#include <core/logger/logger.h>
#include <core/file_utility.h>

#include <server/server.h>
#include <server/server_configuration.h>
#include <server/server_error.h>
#include <server/server_constants.h>

using namespace std;

int main ()
{
    // Initial checks
    if (core::getCPUCacheLineSize() != CACHE_LINE_SIZE)
    {
        auto message = boost::str(boost::format("This executable compiled for cache line size %d ,\
                                                 but you are running on a CPU with a cache line of %d")
                                                 % CACHE_LINE_SIZE % core::getCPUCacheLineSize()
                                                );
        Server::onError(message, ServerError::NON_SUPPORTED_EXECUTION);
    }

    if (core::amIAdmin() == false)
    {
        // Mainly needed for ability to set thread priorities
        core::consoleOutputWithColor(core::ConsoleColor::FG_RED, " WARNING : Program didn`t start with admin/root rights. Therefore will not be able to modify thread priorities.\n");
        cin;
    }

    // Set current working directory as current executable`s directory
    core::setCurrentWorkingDirectory( core::getCurrentExecutableDirectory() );

    // Load configuration file
    ServerConfiguration serverConfiguration;
    try
    {
        serverConfiguration.load(server_constants::CONFIGURATION_FILE);
    }
    catch (const std::invalid_argument & e)
    {
        Server::onError(e.what(), ServerError::INVALID_CONFIG_FILE);
    }
    catch (const std::runtime_error & e)
    {
        Server::onError(e.what(), ServerError::INVALID_CONFIG_FILE);
    }
    catch (const std::bad_alloc &)
    {
        Server::onError("Insufficient memory", ServerError::INSUFFICIENT_MEMORY);
    }
    catch (...)
    {
        Server::onError("Unknown exception occured", ServerError::UNKNOWN_PROBLEM);
    }

    // Single instance protection
    core::SingleInstance singleton(serverConfiguration.getSingleInstancePortNumber());

    if ( !singleton() )
    {
        Server::onError("Ome process is running already.", ServerError::ALREADY_RUNNING);
    }

    // Start and run the server
    try
    {
        // Start logger
        core::Logger::getInstance()->start();
        LOG_INFO("Main thread", "starting")

        Server application(server_constants::FIX_ENGINE_CONFIG_FILE, serverConfiguration);

        // Run the server
        application.run();
    }
    catch (const std::invalid_argument & e)
    {
        Server::onError(e.what(), ServerError::RUNTIME_ERROR);
    }
    catch (const std::runtime_error & e)
    {
        Server::onError(e.what(), ServerError::RUNTIME_ERROR);
    }
    catch (const std::bad_alloc & )
    {
        Server::onError("Insufficient memory", ServerError::INSUFFICIENT_MEMORY);
    }
    catch (...)
    {
        Server::onError("Unknown exception occured", ServerError::UNKNOWN_PROBLEM);
    }
    //////////////////////////////////////////
    // Application exit
    LOG_INFO("Main thread", "Ending")
    core::Logger::getInstance()->shutdown();
    return 0;
}