#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

// new keyword introduced: protected
//An accress modifier like private and public

// The Rule: Members marked protected cannot be accessed 
// by external code or instances (just like private data).
// However, they can be accessed freely by any Derived classes
// further down the inheritance chain. 


// Syntax layout:Three inheritance modes
// class DerivedClass : visibilityMode BaseClass{body}
// The choice of visibilityMode sets an upper boundary 
// limit on the access levels of inherited elements.

//Mode A: public Inheritance (The Standard "Is-A" Relationship)

//Public members of Base stay public in Derived.
//Protected members of Base stay protected in Derived.
//Private members of Base remain invisible/inaccessible to Derived.

// Mode B: protected Inheritance (Restricted Hierarchy)

//Public members of Base become protected in Derived.
//Protected members of Base stay protected in Derived.
//Private members of Base remain invisible/inaccessible to Derived.

//Mode C: private Inheritance (Implementation Hiding)

//Public members of Base become private in Derived.
//Protected members of Base become private in Derived.
// Private members of Base remain invisible/inaccessible to Derived.
class Character{
    protected:
    std::string name;
    int goldcount = 50;
    int health;
    public:
    Character(const std::string& cName, int cHealth):name(cName), health(cHealth){
        std::cout<<"step 1, parant constructor initialised\n";
    }
};
class Wizard:public Character{
    public:
    int mana;//new attribute fo this class
    //constructing base class first, then child class
    Wizard(const std::string& wName, int wHealth, int wMana):Character(wName, wHealth), mana(wMana){
        std::cout<<"step2, child constructor initialised\n";
    //^^^^^protected variables in bas class is protected in child(accessible to other childs but not main()), and private and public

    }
    int printgold(){
        return goldcount;//allowed since it is protected and childs access it
    }
};
int main(){
    Wizard wiz("Eldin", 100, 150);
    wiz.mana;// is a public access possesor
    // wiz.name// is a protected attribule that cant be accessed in main block
    std::cout<<wiz.printgold()<<"\n";

    return 0;
}