#include <iostream>
//creating a class that can a derived classes
class Animal {
    public:
    //creating a virtual function(method) that can be overriden for different derived classes
    virtual void speak(){
        std::cout<<"an animal sound\n";
    }
    virtual ~Animal(){}
};

// creating a derived class
class Dog : public Animal{
    void speak() override{
        std::cout<<"Woof\n";

    }
};

class Cat : public Animal{
    void speak() override{
        std::cout<<"Meow\n";

    }
};
int main(){
    Animal* pet; // a pointer to Animal class that stores address of Animal type objects
    
    Dog doom;// instance of the derived class:Dog
    Cat growl;// instance of the derived class:Cat
    pet = &doom;// initialising the pet pointer to &classinstance(that contains address of derived class Dog)
    pet->speak();// this line : take address in pet, derefrence it, and treat as an obj, call speak for thwt obj

    pet = &growl;
    pet->speak();

    //next session in learning_23_poly_ex1.cpp
    return 0;
}