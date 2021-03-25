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
        char c;
        int i = 0, j = 0;
        while (source >> c) {
            m_Elements.emplace_back(P::Dialect::Element {
                .category = P::Dialect::Category::Undefined,
                .type = P::Dialect::Type::Undefined,
                .position = {i++, j},
                .token = {std::string(1, c)},
            });
            if (c == P::Literals::Newline[0]) {
                i = 0;
                j++;
            }
        }
    }

    void Parser::parse() {

    }
} /* P::Dialect */