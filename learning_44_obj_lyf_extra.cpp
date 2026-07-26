#include <iostream>

class Component {
public:
    Component() { std::cout << "Component\n"; }
};

class Base {
public:
    Base() { std::cout << "Base\n"; }
};

class Derived : public Base {
private:
    Component m_comp;
public:
    Derived() : m_comp(), Base() { // even if the member is first declared in class,
        // compiler wont read the derivedclass insides without constructoing the base first, thus Base constructor works before m_comp
        std::cout << "Derived\n"; 
    }
};

int main() {
    Derived d;
}
