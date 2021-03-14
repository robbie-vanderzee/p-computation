#pragma once

#include <string>

#include "compiler/logging/log.hpp"

namespace P {
    class Error {
      public:
        Error(const std::string message) : m_Message(message) {

        }
        void emit() {
            P_ERROR("{0}", m_Message);
        }
      private:
        const std::string m_Message;
    };
}