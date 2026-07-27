// BUGGED CODE
// #include <iostream>
// #include <memory>

// class AudioBuffer {
// public:
//     AudioBuffer() { std::cout << "Base Hardware Context Hooked.\n"; }
//     ~AudioBuffer() { std::cout << "Base Hardware Context Released.\n"; } // Bug Location?
// };

// class LowLatencyBuffer : public AudioBuffer {
// private:
//     float* m_samples;
// public:
//     LowLatencyBuffer() {
//         m_samples = new float[44100]; // Massive 176KB allocation per second!
//         std::cout << "Allocated 44.1kHz Audio Sample Frame Stream.\n";
//     }
//     ~LowLatencyBuffer() {
//         delete[] m_samples;
//         std::cout << "Freed Audio Sample Frame Stream from Heap.\n";
//     }
// };

// int main() {
//     // Allocation tracking
//     std::unique_ptr<AudioBuffer> engine = std::make_unique<LowLatencyBuffer>();
    
//     std::cout << "Processing active hardware stream...\n";
// } // 'engine' goes out of scope here!


// FIXED CODE
#include <iostream>
#include <memory>

class AudioBuffer {
public:
    AudioBuffer() { std::cout << "Base Hardware Context Hooked.\n"; }
    ~AudioBuffer() { std::cout << "Base Hardware Context Released.\n"; } // Bug Location?
};

class LowLatencyBuffer : public AudioBuffer {
private:
    float* m_samples;
public:
    LowLatencyBuffer() {
        m_samples = new float[44100]; // Massive 176KB allocation per second!
        std::cout << "Allocated 44.1kHz Audio Sample Frame Stream.\n";
    }
    ~LowLatencyBuffer() {
        delete[] m_samples;
        std::cout << "Freed Audio Sample Frame Stream from Heap.\n";
    }
};

int main() {
    // Allocation tracking
    std::shared_ptr<AudioBuffer> engine = std::make_unique<LowLatencyBuffer>();
    
    std::cout << "Processing active hardware stream...\n";
} // 'engine' goes out of scope here!
