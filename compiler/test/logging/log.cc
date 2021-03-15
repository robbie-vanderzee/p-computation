#include "gtest/gtest.h"

#include "compiler/logging/log.hpp"

TEST(Log, Initialize) {
    EXPECT_NO_THROW({
        P::Logging::Log::initialize(
        {
            .name = "Test",
            .log_directory = "logging/test.log",
            .max_log_files = 3,
            .max_log_file_size = 5 * 1024 * 1024,
            .threads = 1,
            .workers = 1,
        });
    });
}

TEST(Log, Basic_Core_Logs) {
    EXPECT_NO_THROW({
        P_CRITICAL("Core Critical");
        P_ERROR("Core Error");
        P_WARN("Core Warn");
        P_INFO("Core Info");
        P_TRACE("Core Trace");
    });
}

TEST(Log, Basic_Assertions) {
    EXPECT_NO_THROW({
        P_ASSERT(false, "Assertion failed.");
    });
}

TEST(Log, Shutdown) {
    EXPECT_NO_THROW({
        P::Logging::Log::shutdown();
    });
}
