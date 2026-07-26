# include <iostream>
// POINTER UPCASTING: Base class pointer can point to directly to derived class object
class Animal{
    public:
    virtual void makeNoise(){std::cout<<"Animal Sound\n";}
};
class Dog: public Animal{
    void makeNoise() override {std::cout<<"Woof\n";}// override saves life: it tells the compiler that this functipon is modified from preexisting one in base
    //if u make a type mistake in exact name of function, it will be treated as new function for this class
};
int main(){
    std::cout<<"PolyMorphism\n";
    Dog mydog;
    Animal* ptr = &mydog;//upcasting!
    ptr->makeNoise();// print: Animal Sound(without virtual function)
    // even though ptr points to Dog, prints Animal sound
    //compiler looks at pointer type and locks into Animal::makeNoise()
    // this can be resolved by using virtual keyword
    return 0;
}

// VIRTUAL TABLE<vtable>:
// every class that has anyone virtual function has vtable
// vtable is an array of pointers to these virtual functions built into a class
// there is only one vtable per class not per object
// 

// VIRTUAL POINTERS<vptr>:
// class containing vtable automatically consists of a vptr
// every instance of a polymorphic class grows by a size of a pointer(4 byte in 32 and 8 byte in 64 bit sys)

// The Runtime Lookup Mechanics (Step-by-Step)When you write 
// ptr->makeNoise(); where makeNoise is virtual, the CPU performs
// an indirect memory lookup at runtime instead of jumping straight
// to a hardcoded function block:Step

// 1: The program dereferences the object to find its hidden
// vptr.Step

// 2: It follows the vptr to open up the class's static 
// vtable.Step 

// 3: It looks up the pre-indexed slot for makeNoise().Step 
// 4: It fetches the resolved function address from that slot and executes it.
// This indirect path adds a minor execution cost, which is the tradeoff for achieving dynamic, runtime flexibility!
