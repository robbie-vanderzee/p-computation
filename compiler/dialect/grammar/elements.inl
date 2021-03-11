namespace Symbol {
    namespace Operator {
        enum class Unary {
            Negate,
            Rotate,
            Invert,
            Union,
            Intersect,
        };
        enum class Binary {
            Sum,
            Product,
            Quotient,
        };
        enum class Ternary {

        };
        enum class Variadic {

        };
    } /* Operator */
    namespace Control {
        enum class Initial {
            Paren,
            Brace,
            Bracket,
        };
        enum class Seperator {
            Comma,
            Colon,
            Semicolon,
        };
        enum class Terminal {
            Paren,
            Brace,
            Bracket,
        };
        enum class Block {
            Do,
            While,
            For,
            If,
            Elif,
            Else,
            Return,
        };
    }; /* Control */
} /* Symbol */