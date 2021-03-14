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
      public:
        class Manager;
      public:
        Parser(std::filesystem::path owner);
        void load();

      private:
        std::vector<P::Element> m_Elements;
        std::filesystem::path m_Owner;
    };
} /* P */