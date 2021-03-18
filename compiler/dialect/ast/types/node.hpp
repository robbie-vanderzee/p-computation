#pragma once

#include <memory>

#include "compiler/dialect/grammar/elements.inl"
#include "compiler/dialect/ast/visitor.hpp"

namespace P::Dialect::AST {
    class Node {
      public:
        virtual ~Node() = default;

        virtual void accept(std::shared_ptr<P::Dialect::AST::Visitor> visitor) {

        }

        P::Dialect::Position position() {
            return m_Position;
        }

      private:
        P::Dialect::Position m_Position;
    };
} // namespace P::Dialect::AST
