#include <iostream>
//pure VIRTUAL FUNCTION: a function defined by a base class that is completely blank
// this blank function exists in base to be modified by derived classes
// virtual void method()=0 is the syntax in base class
class DatabaseConnector {
public:
    // Syntax Layout: virtual return_type func_name() = 0;
    virtual void connect() = 0; 
    virtual void disconnect() = 0;};
// this class that contains atleat one virtual(pure) is callled an abstract base class(ABS)
// it is strictly forbidden to instantiate an ABS class since it contians undefined methods meant to be overriden by childs

// Any derived class (e.g., class PostgresConnector : public DatabaseConnector) will also become
//  abstract and locked out from instantiation unless it overrides and implements every single pure
//   virtual function inherited from the parent.
class PostgresConnector : public DatabaseConnector {
public:
    void connect() override {
        // Concrete implementation details here
    }
    // DANGER: If disconnect() is left unimplemented, PostgresConnector remains abstract!
};
class Interface {
public:
    virtual void logError() = 0;
};

// Valid C++!
void Interface::logError() {
    std::cout << "System Log: ";
}
// even if we made a body to a pure virtual method, its is still an ABS class