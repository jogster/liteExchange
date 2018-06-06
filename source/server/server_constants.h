#ifndef _SERVER_CONSTANTS_H_
#define _SERVER_CONSTANTS_H_

#include <cstddef>
namespace server_constants
{
// Configuration file
static constexpr char* CONFIGURATION_FILE = "liteExchange.ini";
// Configuration - General process related
static constexpr char* CONFIGURATION_FILE_PROCESS_PRIORITY = "PROCESS_PRIORITY";
// Configuration - Order entry mode
static constexpr char* CONFIGURATION_FILE_ORDER_ENTRY_MODE = "ORDER_ENTRY_MODE";
// Configuration - FIX Server
static constexpr char* CONFIGURATION_FILE_TCP_DISABLE_NAGLE = "TCP_DISABLE_NAGLE";
static constexpr char* CONFIGURATION_FILE_TCP_QUICK_ACK = "TCP_QUICK_ACK";
static constexpr char* CONFIGURATION_FILE_TCP_PENDING_CONNECTION_SIZE = "TCP_PENDING_CONNECTION_SIZE";
static constexpr char* CONFIGURATION_FILE_TCP_SOCKET_OPTION_SEND_BUFFER_SIZE = "TCP_SOCKET_OPTION_SEND_BUFFER_SIZE";
static constexpr char* CONFIGURATION_FILE_TCP_SOCKET_OPTION_RECEIVE_BUFFER_SIZE = "TCP_SOCKET_OPTION_RECV_BUFFER_SIZE";
static constexpr char* CONFIGURATION_FILE_TCP_POLL_TIMEOUT_MICROSECONDS = "TCP_POLL_TIMEOUT_MICROSECONDS";
static constexpr char* CONFIGURATION_FILE_TCP_POLL_MAX_EVENTS = "TCP_POLL_MAX_EVENTS";
static constexpr char* CONFIGURATION_FILE_REACTOR_THREAD_CPU_ID = "REACTOR_THREAD_CPU_ID";
static constexpr char* CONFIGURATION_FILE_REACTOR_THREAD_PRIORITY = "REACTOR_THREAD_PRIORITY";
static constexpr char* CONFIGURATION_FILE_REACTOR_THREAD_STACK_SIZE = "REACTOR_THREAD_STACK_SIZE";
static constexpr char* CONFIGURATION_FILE_FIX_SERVER_COMP_ID = "FIX_SERVER_COMP_ID";
static constexpr char* CONFIGURATION_FILE_FIX_SERVER_PORT = "FIX_SERVER_PORT";
static constexpr char* CONFIGURATION_FILE_FIX_SERVER_ADDRESS = "FIX_SERVER_ADDRESS";
static constexpr char* CONFIGURATION_FILE_FIX_SERVER_TIME_PRECISION = "FIX_SERVER_TIME_PRECISION";
static constexpr char* CONFIGURATION_FILE_FIX_SERVER_RECEIVE_CACHE_SIZE = "FIX_RECEIVE_CACHE_SIZE";
static constexpr char* CONFIGURATION_FILE_FIX_SERVER_SEQUENCE_NUMBER_VALIDATION = "FIX_SERVER_SEQUENCE_NUMBER_VALIDATION";
// Offline order entry mode related
static constexpr char* CONFIGURATION_FILE_OFFLINE_ORDER_ENTRY_FILE = "OFFLINE_ORDER_ENTRY_FILE";
static constexpr char*   CONFIGURATION_FILE_OFFLINE_ORDER_ENTRY_OUTPUT_FILE = "OFFLINE_ORDER_ENTRY_OUTPUT_FILE";
// Configuration - Central order book related
static constexpr char* CONFIGURATION_FILE_CENTRAL_ORDER_BOOK_MULTITHREADED_ORDER_MATCHING = "CENTRAL_ORDER_BOOK_MULTITHREADED_ORDER_MATCHING";
static constexpr char* CONFIGURATION_FILE_CENTRAL_ORDER_BOOK_PIN_THREADS_TO_CORES = "CENTRAL_ORDER_BOOK_PIN_THREADS_TO_CORES";
static constexpr char* CONFIGURATION_FILE_CENTRAL_ORDER_BOOK_WORK_QUEUE_SIZE_PER_THREAD = "CENTRAL_ORDER_BOOK_WORK_QUEUE_SIZE_PER_THREAD";
static constexpr char* CONFIGURATION_FILE_CENTRAL_ORDER_BOOK_THREAD_STACK_SIZE = "CENTRAL_ORDER_BOOK_THREAD_STACK_SIZE";
static constexpr char* CONFIGURATION_FILE_CENTRAL_ORDER_BOOK_THREAD_PRIORITY = "CENTRAL_ORDER_BOOK_THREAD_PRIORITY";
static constexpr char* CONFIGURATION_FILE_CENTRAL_ORDER_BOOK_HYPER_THREADING = "CENTRAL_ORDER_BOOK_HYPER_THREADING";
static constexpr char* CONFIGURATION_FILE_SYMBOL_ARRAY = "SYMBOL";
// Configuration - Outgoing message processor related
static constexpr char* CONFIGURATION_FILE_OUTGOING_MESSAGE_QUEUE_SIZE_PER_THREAD = "OUTGOING_MESSAGE_QUEUE_SIZE_PER_THREAD";
static constexpr char* CONFIGURATION_FILE_OUTGOING_MESSAGE_QUEUE_THREAD_STACK_SIZE = "OUTGOING_MESSAGE_PROCESSOR_THREAD_STACK_SIZE";
static constexpr char* CONFIGURATION_FILE_OUTGOING_MESSAGE_QUEUE_THREAD_PRIORITY = "OUTGOING_MESSAGE_PROCESSOR_THREAD_PRIORITY";
static constexpr char* CONFIGURATION_FILE_OUTGOING_MESSAGE_QUEUE_THREAD_CPU_ID = "OUTGOING_MESSAGE_PROCESSOR_CPU_ID";
// Configuration - Logger
static constexpr char* CONFIGURATION_FILE_LOGGER_COPY_TO_STDOUT = "LOGGER_COPY_TO_STDOUT";
static constexpr char* CONFIGURATION_FILE_LOGGER_BUFFER_SIZE = "LOGGER_BUFFER_SIZE";
static constexpr char* CONFIGURATION_FILE_LOGGER_WRITE_PERIOD_MILLISECONDS = "LOGGER_WRITE_PERIOD_MILLISECONDS";
static constexpr char* CONFIGURATION_FILE_LOGGER_ROTATION_SIZE_IN_BYTES = "LOGGER_ROTATION_SIZE_IN_BYTES";
static constexpr char* CONFIGURATION_FILE_LOGGER_MEMORY_MAPPED_FILE = "LOGGER_MEMORY_MAPPED_FILE";
static constexpr char* CONFIGURATION_FILE_LOGGER_LOG_LEVEL = "LOGGER_LOG_LEVEL";
// Configuration Defaults
static constexpr char*    CONFIGURATION_DEFAULT_PROCESS_PRIORITY = "NORMAL";
static constexpr bool            CONFIGURATION_DEFAULT_CENTRAL_ORDER_BOOK_MULTITHREADED_ORDER_MATCHING_ENGINE = true;
static constexpr bool            CONFIGURATION_DEFAULT_CENTRAL_ORDER_BOOK_PIN_THREADS_TO_CORES = true;
static constexpr bool            CONFIGURATION_DEFAULT_CENTRAL_ORDER_BOOK_HYPER_THREADING = true;
static constexpr int            CONFIGURATION_DEFAULT_CENTRAL_ORDER_BOOK_WORK_QUEUE_SIZE_PER_THREAD = 128;
static constexpr char*    CONFIGURATION_DEFAULT_CENTRAL_ORDER_BOOK_THREAD_PRIORITY = "NORMAL";
static constexpr int            CONFIGURATION_DEFAULT_CENTRAL_ORDER_BOOK_THREAD_STACK_SIZE = 0;
static constexpr int              CONFIGURATION_DEFAULT_OUTGOING_MESSAGE_QUEUE_SIZE_PER_THREAD = 128;
// Others
static constexpr std::size_t SERVER_THREAD_SLEEP_DURATION_MICROSECONDS = 1000;
}

#endif