#pragma once

#include <functional>
#include <string>

namespace P {
    namespace Titles {
        const std::string language = "P";
    }  /* Titles */
    namespace Numerics {
        constexpr unsigned int Bit(unsigned int x) {
            return 1 << x;
        }
    }  /* Numerics */
}  /* P */