#pragma once

template <typename T>
class PacketEncoder {
public:
    void encodePayload(T data); // Signature declaration
};

#include <iostream>

template <typename T>
void PacketEncoder<T>::encodePayload(T data) {
    std::cout << "[ENCODE] Processing multi-byte payload stream: " << data << "\n";
}
