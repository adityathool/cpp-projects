#include <iostream>
#include <memory>
class Base{
    public:
    Base(){std::cout<<"Base Constructor\n";}
    // ~Base(){std::cout<<"Base Destructor\n";}//-:previous line
    virtual ~Base(){std::cout<<"Base Destructor\n";}//-:updated line
};
class Derived:public Base{
    int* m_arr;
    public:
    Derived(){
        m_arr = new int[100];
        std::cout<<"Derived Constructor\n";
    }
    ~Derived(){
        delete[] m_arr;//cleanup
        std::cout<<"Derved destructor\n";
        
    }
};
int main(){
    std::unique_ptr<Base>ptr = std::make_unique<Derived>();
    // ptr goes out of scope 
    // {
    // std::shared_ptr<Base> ptr = std::make_shared<Derived>();
    // }


    return 0;
}
/// notice that derived destructor was never called, and m_arr never deleted, this is because
// ptr is upcasted, it is of base type storing a derived object
// as ptr goes out of scope, it triggers the Base destructor(since it is Base type) and ignores Derived destructor
// to solve this, use virtual Base destructor

// Whenever you write an abstract class or any class intended 
// to be used as a base class with virtual functions, you
//  must provide a virtual destructor. Even if it does nothing,
//   you declare it as default:
class Interface {
public:
    virtual void execute() = 0;
    virtual ~Interface() = default; // Absolute Insurance Policy!
};
// TWIST
// if the base destructor is not virtual, but u stored derived object in 
// a base type shared_ptr, the leak does not happen, derived destructor calls, delests heap memory
//this is because unique_ptr relies on the lhs of the pointer declaration, it says that if a pointer is base type, i will destroy the base regardless of whats on right
// but shared_ptr relies on rhs of pointer declaration, it says, even if the pointer is base type, it stores an instance of derved type, when pointer goes out, delete the derived and base too
// when u write std::make_shared<SuperSecureHandler>(), compiler creates 2 seprate heap allocations, one for actual object
// and one for the control block, since control is the main engine for deletionor cleanup, as it is allocated after writing the above line, 
// the block has instructions for the object and its base, so it calls both, the object and bases' destructor

// when a unique_ptr is created, after upcasting it to base, the deleter is static and depends only on the pointer , if the pointer is base type, the deleter is base, ignoring the contents of derived
// when a shared ptr is created,it creates a pointer along with a control block, the control block capturees the exact layout of destructor of derived object
// when it is upcasted to base type, pointer becomes base type, not the control block, thus when pointer goes out of scope, it calls the base destructor, while the control block calls derived class destructor
