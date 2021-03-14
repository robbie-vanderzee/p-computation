#pragma once

#include "compiler/utilities/structure/bitmask.inl"

namespace P {
    enum class Type : unsigned int {
        Undefined = 0,
        Native = 1,

        Identifier, Number,
        Assign, Equality,
        Brace, Bracket, Paren,
        Colon, Comma, Semicolon, Slash,
        Union, Intersect, Hyperunion, Hyperintersect,
        Functional,
    };

    enum class Category : unsigned int {
        Undefined = 0,
        Native = P::Numerics::Bit(1),

        Semantic = P::Numerics::Bit(2),

        Element = P::Numerics::Bit(3),

        Operator = P::Numerics::Bit(4),
        Unary = P::Numerics::Bit(5),
        Binary = P::Numerics::Bit(6),
        Ternary = P::Numerics::Bit(7),

        Control = P::Numerics::Bit(8),
        Initial = P::Numerics::Bit(9),
        Internal = P::Numerics::Bit(10),
        Terminal = P::Numerics::Bit(11),
        Block = P::Numerics::Bit(12),
        Forward = P::Numerics::Bit(13),
        Backward = P::Numerics::Bit(14),
    };

    P::Structure::Concept::Tag as_bitmask(Category);

    struct Position {
        int i, j;
    };

    struct Token {
        std::string source;
    };

    struct Element {
        P::Category category;
        P::Type type;
        P::Position position;
        P::Token token;
    };
} /* P */