#pragma once

#include <functional>
#include <memory>

#include "compiler/dialect/ast/types/node.hpp"
#include "compiler/dialect/ast/types/function.hpp"
#include "compiler/dialect/parser/parser.hpp"

namespace P::Dialect::AST {
    class Builder {
      public:
        Builder(P::Dialect::Parser parser) : m_Parser(parser) {}
        bool build(P::Dialect::Parser p) {
            std::vector<P::Dialect::AST::Function> functions;
            return false;
        }
      private:
        P::Dialect::Parser m_Parser;
    };
} /* P::Dialect::AST */
