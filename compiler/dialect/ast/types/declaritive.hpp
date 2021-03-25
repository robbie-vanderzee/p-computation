#pragma once

#include <functional>

#include "compiler/dialect/ast/types/node.hpp"

namespace P::Dialect::AST {
    class Declaritive : Node {
      public:
        struct Identifier {
            std::string name;
            std::size_t hash;
        };
      public:
        Declaritive(std::string name) : m_Identifier{.name = name, .hash = std::hash<std::string>{}(name) } {}
      private:
        Identifier m_Identifier;
    };
} /* P::Dialect::AST */
