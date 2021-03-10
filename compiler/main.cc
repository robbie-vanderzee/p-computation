#include "compiler/logging/log.hpp"

int main(int, char const *[]) {
    P::Logging::Log::initialize({
        .name = "P",
        .log_directory = "logging/test.log",
        .max_log_files = 3,
        .max_log_file_size = 5 * 1024 * 1024,
        .threads = 8096,
        .workers = 8,
    });
}
