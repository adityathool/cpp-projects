// bugged CODE

// ----packet_encoder.h------ //
// #pragma once

// template <typename T>
// class PacketEncoder {
// public:
//     void encodePayload(T data); // Signature declaration
// };

// //------packet_encoder.cpp--------- //
// #include "packet_encoder.h"
// #include <iostream>

// template <typename T>
// void PacketEncoder<T>::encodePayload(T data) {
//     std::cout << "[ENCODE] Processing multi-byte payload stream: " << data << "\n";
// }

// //  --------main---------//
// #include "packet_encoder.h"

// int main() {
//     PacketEncoder<int> encoder;
//     encoder.encodePayload(42); // TRAP LINE: This triggers the Linker Error!
//     return 0;
// }

// CORRECT CODE-------------------
// place packet_encoder.cppp inside packet_incoder.h
// learning_68_enc.cpp works as packet_encoder.h
#include "learning_68_enc.h"

int main() {
    PacketEncoder<int> encoder;
    encoder.encodePayload(42); // TRAP LINE: This triggers the Linker Error!
    return 0;
}
