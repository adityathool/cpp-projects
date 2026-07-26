// BuggGY CODE

// #include <iostream>
// #include <string>

// class Asset {
// protected:
//     std::string m_serial;
// public:
//     Asset(std::string serial) : m_serial(serial) {
//         std::cout << "Asset created: " << m_serial << "\n";
//     }
// };

// class Server : public Asset {
// private:
//     int m_coreCount;
//     int m_ramGB;
// public:
//     // GOAL: Initialize core count, then double it to estimate RAM capacity, 
//     // and pass the serial up to the Asset class.
//     Server(std::string serial, int cores) 
//         : m_coreCount(cores), m_ramGB(m_coreCount * 2) 
//     {
//         std::cout << "Server configured with " << m_ramGB << "GB RAM\n";
//     }
// };

// int main() {
//     Server s("X-990", 16);
// }
//DEBUGGED  CODE>
#include <iostream>
#include <string>

class Asset {
protected:
    std::string m_seria;
public:
    Asset(std::string seria) : m_seria(seria) {
        std::cout << "Asset created: " << m_seria << "\n";
    }
};

class Server : public Asset {
private:
    int m_coreCount;
    int m_ramGB;
public:
    // GOAL: Initialize core count, then double it to estimate RAM capacity, 
    // and pass the serial up to the Asset class.
    Server(std::string serial, int cores) 
        :Asset(serial), m_coreCount(cores), m_ramGB(m_coreCount * 2) 
    {
        std::cout << "Server configured with " << m_ramGB << "GB RAM\n";
    }
};

int main() {
    Server s("X-990", 16);
}
// it is adviced to not make member initialasion dependant on member variable