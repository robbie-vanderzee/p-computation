#include "parser.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "compiler/dialect/grammar/literals.inl"

namespace P::Dialect {
    Parser::Parser(std::filesystem::path owner) : m_Owner(owner) {}
    void Parser::load() {
        P_ASSERT_MESSAGE(std::filesystem::exists(m_Owner), "Invalid filepath provided to parser: {0} is empty or corrupt. Location: {1}", m_Owner.filename(), m_Owner);
        std::ifstream source(m_Owner);
        char token;
        int i = 0, j = 0;
        while (source >> std::noskipws >> token) {
            m_Elements.emplace_back(element(token, P::Dialect::Position {i++, j}));
            j += token == P::Literals::Newline[0];
        }
    }

    void Parser::parse() {

    }

    P::Dialect::Element element(char c, P::Dialect::Position position) {
        P::Dialect::Token token {std::string(1, c)};
        switch (c) {
            case '(': {
                return P::Dialect::Element {
                    .category = P::Dialect::Category::Element + P::Dialect::Category::Initial,
                    .type = P::Dialect::Type::Paren,
                    .position = position,
                    .token = token,
                };
            }
            case ')': {
                return P::Dialect::Element {
                    .category = P::Dialect::Category::Element + P::Dialect::Category::Terminal,
                    .type = P::Dialect::Type::Paren,
                    .position = position,
                    .token = token,
                };
            }
            case '{': {
                return P::Dialect::Element {
                    .category = P::Dialect::Category::Element + P::Dialect::Category::Initial,
                    .type = P::Dialect::Type::Brace,
                    .position = position,
                    .token = token,
                };
            }
            case '}': {
                return P::Dialect::Element {
                    .category =  P::Dialect::Category::Element + P::Dialect::Category::Terminal,
                    .type = P::Dialect::Type::Brace,
                    .position = position,
                    .token = token,
                };
            }
            case '[': {
                return P::Dialect::Element {
                    .category =  P::Dialect::Category::Element + P::Dialect::Category::Initial,
                    .type = P::Dialect::Type::Bracket,
                    .position = position,
                    .token = token,
                };
            }
            case ']': {
                return P::Dialect::Element {
                    .category =  P::Dialect::Category::Element + P::Dialect::Category::Terminal,
                    .type = P::Dialect::Type::Bracket,
                    .position = position,
                    .token = token,
                };
            }
            case ',': {
                return P::Dialect::Element {
                    .category = P::Dialect::Category::Element,
                    .type = P::Dialect::Type::Comma,
                    .position = position,
                    .token = token,
                };
            }
            case ':': {
                return P::Dialect::Element {
                    .category = P::Dialect::Category::Element,
                    .type = P::Dialect::Type::Colon,
                    .position = position,
                    .token = token,
                };
            }
            case ';': {
                return P::Dialect::Element {
                    .category = P::Dialect::Category::Element,
                    .type = P::Dialect::Type::Semicolon,
                    .position = position,
                    .token = token,
                };
            }
            case '/': {
                return P::Dialect::Element {
                    .category = P::Dialect::Category::Element,
                    .type = P::Dialect::Type::Slash,
                    .position = position,
                    .token = token,
                };
            }
            case '=' : {
                return P::Dialect::Element {
                    .category = P::Dialect::Category::Element,
                    .type = P::Dialect::Type::Assign,
                    .position = position,
                    .token = token,
                };
            }
            case '+' : {
                return P::Dialect::Element {
                    .category = P::Dialect::Category::Element,
                    .type = P::Dialect::Type::Union,
                    .position = position,
                    .token = token,
                };
            }
            case '-' : {
                return P::Dialect::Element {
                    .category = P::Dialect::Category::Element,
                    .type = P::Dialect::Type::Intersect,
                    .position = position,
                    .token = token,
                };
            }
            case '*' : {
                return P::Dialect::Element {
                    .category = P::Dialect::Category::Element,
                    .type = P::Dialect::Type::Hyperunion,
                    .position = position,
                    .token = token,
                };
            }
            default : {
                return P::Dialect::Element {
                    .category = P::Dialect::Category::Undefined,
                    .type = P::Dialect::Type::Undefined,
                    .position = position,
                    .token = token,
                };
            }
        }
    }
} /* P::Dialect */