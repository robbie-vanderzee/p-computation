#pragma once

namespace P {
    enum class Symbol {
        /* Element */
        Identifier,
        /* Operator */
        /* Unary */
        Negate,
        Rotate,
        Invert,
        /* Binary */
        Sum,
        Product,
        Quotient,
        Union,
        Intersect,
        Assign,
        /* Ternary */
        /* Variadic */
        /* Control*/
        /* Initial */
        I_Paren,
        I_Brace,
        I_Bracket,
        /* Internal */
        Comma,
        Colon,
        Semicolon,
        /* Terminal */
        T_Paren,
        T_Brace,
        T_Bracket,
        /* Block */
        Do,
        While,
        For,
        If,
        Elif,
        Else,
        Return,
    };
} /* P */