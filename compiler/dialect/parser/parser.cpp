#include "parser.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "compiler/dialect/grammar/literals.inl"

namespace P {
    Parser::Parser(std::filesystem::path owner) : m_Owner(owner) {}
    void Parser::load() {
        P_ASSERT(!m_Owner.empty(), "Invalid filepath provided to parser: {0} | empty or corrupt.", m_Owner);
        std::ifstream source(m_Owner);
        std::string line;
        char c;
        int i = 0, j = 0;
        while (source >> std::noskipws >> c) {
            if(c != P::Literals::Whitespace[0]) {
                m_Elements.emplace_back(P::Element {
                    .category = P::Category::Undefined,
                    .type = P::Type::Undefined,
                    .position = {i++, j},
                    .token = {std::string(1, c)},
                });
            }
            if (c == P::Literals::Newline[0]) {
                i = 0;
                j++;
            }
        }
    }
} /* P */