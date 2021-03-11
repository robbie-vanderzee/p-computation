#pragma once

#include <string>

#include "compiler/dialect/grammar/elements.inl"
#include "compiler/utilities/error.hpp"
#include "compiler/logging/log.hpp"

namespace P {
    class Parser {
        static bool accept(P::Symbol symbol, P::Symbol expect) {
            return symbol == expect;
        };
        static bool expect(P::Symbol symbol, P::Symbol expect, P::Error message) {
            if (accept(symbol, expect)) return true;
            else message.emit();
            return false;
        }
    };
} /* P */