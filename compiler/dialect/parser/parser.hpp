#pragma once

#include <filesystem>
#include <map>
#include <string>
#include <vector>

#include "compiler/dialect/grammar/elements.inl"
#include "compiler/utilities/interface/error.hpp"
#include "compiler/logging/log.hpp"

namespace P {
    class Parser {
        class Manager;
      public:
        Parser(std::filesystem::path owner) : m_Owner(owner) {}

        void load() {
            P_ASSERT(!m_Owner.empty(), "Invalid filepath provided to parser: {0} | empty or corrupt.", m_Owner);
        }
      private:
        std::vector<P::Element> m_Elements;
        std::filesystem::path m_Owner;
    };
} /* P */