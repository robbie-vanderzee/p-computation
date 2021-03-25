#pragma once

#include "compiler/dialect/ast/types/node.hpp"

namespace P::Dialect::AST {
    class Statement : Node {
      public:
        ~Statement() = default;
    };
} /* P::Dialect::AST */