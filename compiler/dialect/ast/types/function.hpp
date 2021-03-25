#pragma once

#include <memory>
#include <vector>

#include "compiler/dialect/ast/types/node.hpp"
#include "compiler/dialect/ast/types/declaritive.hpp"
#include "compiler/dialect/ast/types/statement.hpp"

namespace P::Dialect::AST {
    class Function : Node {
      public:

      private:
        std::vector<std::unique_ptr<P::Dialect::AST::Declaritive>> m_Inherited;
        std::vector<std::unique_ptr<P::Dialect::AST::Statement>> m_Statements;
        std::vector<std::unique_ptr<P::Dialect::AST::Declaritive>> m_Locals;
        std::unique_ptr<P::Dialect::AST::Declaritive> m_Declaration;
    };
} /* P::Dialect::AST */
