#pragma once

#include <map>

#include "compiler/dialect/ast/types/node.hpp"

namespace P::Dialect::AST {
    class Number : Node {
      public:
      private:
        struct Element {
            std::map<int, Element *> children;
        };
        Element m_Elements;
    };
} /* P::Dialect::AST */
