#pragma once

#include "compiler/dialect/ast/types/statement.hpp"

namespace P::Dialect::AST {
    class Block : Statement {
      public:
        Block(std::vector<std::unique_ptr<P::Dialect::AST::Statement>> statements) : m_Statements(statements) {}
      private:
        std::vector<std::unique_ptr<P::Dialect::AST::Statement>> m_Statements;
    };
} /* P::Dialect::AST */