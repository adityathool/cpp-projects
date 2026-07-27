// MESSY CODE

// #include <iostream>
// #include <memory>

// class SecurityPlugin {
// public:
//     virtual void initialize() = 0;
//     virtual void scan() = 0;
// };

// class FirewallPlugin : public SecurityPlugin {
// public:
//     void initialize() override {
//         std::cout << "Firewall rules loaded.\n";
//     }
//     // The developer forgot to implement scan() here!
// };

// int main() {
//     // The developer wants to use dynamic allocation for the plugin
//     std::unique_ptr<SecurityPlugin> plugin = std::make_unique<FirewallPlugin>();
    
//     plugin->initialize();
// }

// FIXED CODE

#include <iostream>
#include <memory>

class SecurityPlugin {
public:
    virtual void initialize() = 0;
    virtual void scan() = 0;
};

class FirewallPlugin : public SecurityPlugin {
public:
    void initialize() override {
        std::cout << "Firewall rules loaded.\n";
    }
    // The developer forgot to implement scan() here!
    void scan() override{
        std::cout<<"SCANNING...   Done.\nb";
    }
};

int main() {
    // The developer wants to use dynamic allocation for the plugin
    std::unique_ptr<SecurityPlugin> plugin = std::make_unique<FirewallPlugin>();
    
    plugin->initialize();
}
