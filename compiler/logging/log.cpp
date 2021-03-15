#include "log.hpp"

#include <vector>

#include <spdlog/async.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>

namespace P::Logging {
    void Log::initialize(Log::Configuration configuration) {
        spdlog::init_thread_pool(configuration.threads, configuration.workers);

        auto color_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        color_sink->set_pattern("%^[%T] %n [%l]: %v%$");

        auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt> (configuration.log_directory, configuration.max_log_file_size, configuration.max_log_files);
        file_sink->set_pattern("[%T] [%l] %n: %v");

        std::vector<spdlog::sink_ptr> sinks = { color_sink, file_sink };

        s_Core = std::make_shared<spdlog::async_logger> (P::Titles::language, std::begin(sinks), std::end(sinks), spdlog::thread_pool(), spdlog::async_overflow_policy::block);
        s_Core->set_level(spdlog::level::trace);
        spdlog::register_logger(s_Core);
        spdlog::set_default_logger(s_Core);
    }
} /* P::Logging */