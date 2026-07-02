#include <iostream>
#include <string>
class Player{
    private:
    std::string name;
    public:
    Player(std::string playername): name(playername){
        std::cout<<"Player "<<name<<" entered!\n";
    }
    ~Player(){
        std::cout<<"player "<<name<<" disconnected\n";
    }

};

class Dev {
private:
    std::string name; // Class variable

public:
    // Parameter name clashes with class variable name!
    Dev(std::string name) {
        // name = name; // ERROR: This just assigns the parameter to itself!
        
        // RIGHT: "Go to the memory address of THIS object, and set its name variable"
        this->name = name; // this keyword stores the mem address of an instance on class
    }//see our class var name and parameter name clashes, we can not write(name = name)
};// so the class var is paired with this->name that tells compiler it is a class var

void spawn_player(){
    Player andrew("andrew");
}

int main(){
    std::cout<<"---game started---\n";

    spawn_player();

     std::cout<<"---game ended---\n";

    return 0;//next seesion in learning_19_three/five.cpp
}