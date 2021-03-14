#pragma once

#include <filesystem>

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

#include "compiler/core.hpp"

namespace P::Logging {
    class Log {
      public:
        struct Configuration {
            const std::string name;
            const std::filesystem::path log_directory;
            const std::size_t max_log_files;
            const std::size_t max_log_file_size;
            const std::size_t threads;
            const std::size_t workers;
        };
      public:
        Log() = delete;
        static void initialize(Log::Configuration configuration);
        static void shutdown() {
            spdlog::shutdown();
        }
        static std::shared_ptr<spdlog::logger> & core() {
            return s_Core;
        }
      private:
        inline static std::shared_ptr<spdlog::logger> s_Core = nullptr;
    };
} /* P::Logging */

#define LOG_LEVEL_NONE     0
#define LOG_LEVEL_CRITICAL 1
#define LOG_LEVEL_ERROR    2
#define LOG_LEVEL_WARN     3
#define LOG_LEVEL_INFO     4
#define LOG_LEVEL_DEBUG    5
#define LOG_LEVEL_TRACE    6

#ifndef LOG_LEVEL
#define LOG_LEVEL LOG_LEVEL_NONE
#endif

#if LOG_LEVEL == LOG_LEVEL_DEBUG
#undef LOG_LEVEL
#define LOG_LEVEL LOG_LEVEL_TRACE
#endif

#define P_CRITICAL(...)
#define P_ERROR(...)
#define P_ASSERT(x, ...)
#define P_WARN(...)
#define P_INFO(...)
#define P_TRACE(...)

#if LOG_LEVEL >= LOG_LEVEL_CRITICAL
#undef P_CRITICAL
#define P_CRITICAL(...)         ::P::Logging::Log::core()->critical(__VA_ARGS__)

#if LOG_LEVEL >= LOG_LEVEL_ERROR
#undef P_ERROR
#define P_ERROR(...)            ::P::Logging::Log::core()->error(__VA_ARGS__)
#endif

#ifdef LOG_ASSERTIONS
#undef P_ASSERT
#define P_ASSERT(x, ...) { if(!(x)) { P_ERROR("Assertion Failure: {0}", __VA_ARGS__); }}
#endif

#if LOG_LEVEL >= LOG_LEVEL_WARN
#undef P_WARN
#define P_WARN(...)         ::P::Logging::Log::core()->warn(__VA_ARGS__)
#endif

#if LOG_LEVEL >= LOG_LEVEL_INFO
#undef P_INFO
#define P_INFO(...)         ::P::Logging::Log::core()->info(__VA_ARGS__)
#endif

#if LOG_LEVEL >= LOG_LEVEL_TRACE
#undef P_TRACE
#define P_TRACE(...)         ::P::Logging::Log::core()->trace(__VA_ARGS__)
#endif
#endif