#include "compiler/logging/log.hpp"

int main(int argc, char const * argv[]) {
    P::Logging::Log::initialize({
        .name = "P",
        .log_directory = "logging/test.log",
        .max_log_files = 3,
        .max_log_file_size = 5 * 1024 * 1024,
        .threads = 8096,
        .workers = 8,
    });
    P_ASSERT(argc > 1, "No file provided to compilation.");
    P_TRACE("Compiler::Dialect::Parse(.file = {0})", argv[1]);
}
