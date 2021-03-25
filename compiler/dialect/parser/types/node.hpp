#pragma once

#include <memory>

#include "compiler/dialect/grammar/elements.inl"

namespace P::Dialect::Type {
    struct Node {
        std::unique_ptr<P::Dialect::Type::Node> parent;
        std::vector<std::unique_ptr<P::Dialect::Type::Node>> children;
    };
} /* P::Dialect::Type */