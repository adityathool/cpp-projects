#include <iostream>
#include <string>

enum class ProtocolState {
    Handshake,
    Authenticate,
    Connected
};

int main() {
    ProtocolState state = ProtocolState::Authenticate;
    std::string logMsg;
    switch (state) {
        case ProtocolState::Handshake:
            logMsg = "[INIT] Handshake phase matching keys...";
            std::cout << logMsg << "\n";
            [[fallthrough]];

        case ProtocolState::Authenticate:
            // The developer wants to use the message setup in case 1, or print a fallback
            if (logMsg.empty()) { 
                logMsg = "[AUTH] Authenticating session tokens...";
            }
            std::cout << logMsg << "\n";
            break;

        case ProtocolState::Connected:
            std::cout << "[READY] Transmission channel active.\n";
            break;
    }
    return 0;
}
