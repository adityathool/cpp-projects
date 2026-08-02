#include <iostream>
#include <memory>
#include<stdexcept>

void connectToServer(){
    throw std::runtime_error("Connection failed");
}
void loadGameData(){
    auto particles = std::make_unique<int[]>(1000);
    connectToServer();
}
int main(){
    try {
        loadGameData();
    } catch (const std::exception& e) {
        std::cout << "Game data loading aborted safely: " << e.what() << "\n";
    }
    return 0;
}