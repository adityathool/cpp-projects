#include <iostream>
#include <string>

class Monster {
protected:
    int health;

public:
    Monster(int hp) : health(hp) {}
};

// FIX THE COMPILATION ERRORS IN THIS CHILD CLASS
class Dragon : Monster {
public:
    int firePower;

    // This constructor causes a compilation error!
    Dragon(int hp, int fp):Monster(hp), firePower(fp) {
        // error>trying to initiate child without parent class
    }

    void breatheFire() {
        std::cout << "Dragon breathes fire! Damage: " << (health + firePower) << "\n";
    }
};

int main() {
    Dragon smaug(500, 150);
    smaug.breatheFire();
    
    // This line causes a secondary compilation error!
    std::cout << "Smaug's custom fire stat is: " << smaug.firePower << "\n";
    // since Dragon's constructor didnt initialised, it raised an error in this line
    return 0;
}