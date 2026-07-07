//the rule of three: if our c++ class contains a either
//  a derstructor, copy constructor, or an ASSIgnment, 
//it certainly should have all the three.

// it becomes heavily significant when our class allocates memory dynamically and contains raw pointers
#include <iostream>
// if a class doesnt have a custom copy constructor, it performs shallw copy
// if we allocate a pointer memor in heap, shallow copy would copy a pointer
// not the heap block allocated
// this crates two pointers point to one heap block, so when aclass destructor(auto method to destroy class to cleam memory)
// it deletes the same heap twice, causing a crash,so custom copy constructor is needed



class Memallocator {
    int* ptr;
    public:
    Memallocator(int val){
        ptr = new int(val);
    }
    ~Memallocator(){delete ptr;ptr = nullptr;}
    //copy constructor, without it the class would double delete heap 
    // syntax:doesnt contain keywords but: requiers a class named method and passing the class object(parameter) by consatant refrence
    // passing parameter by value would create copy of object, so this copy constructor work endlessly
    Memallocator(const Memallocator& obj){
        ptr = new int;
        *ptr = *(obj.ptr);
    }

    void print(){
        std::cout<<"the value in pointer is "<<*ptr<<"\n";
    }

};
class Assignment {
    int* ptr;
    public:
    Assignment(int val){
        ptr = new int(val);
    }
    ~Assignment(){delete ptr;ptr = nullptr;}
    Assignment(const Assignment& obj){
        ptr = new int;
        *ptr = *(obj.ptr);
    }
    //assignment pointer: it executes when wehen two created objects are equalled with = sign
    //syntax: uses keywords: Classname& operator=(const Classname& rhs_obj)
    Assignment& operator=(const Assignment& rhs){ // the parameter hers is the object on rhs of = sign in expression (obj1 = obj2)(it is obj2)
        if(this == &rhs){
            return *this;
        }

        delete ptr;// delete the existing data to create fresh one
        ptr = new int;// allocate fresh data
        *ptr = *(rhs.ptr);
        return *this;// retrun a refrnce to current object
    }
    void print(){
        std::cout<<"the value in asignment pointer is "<<*ptr<<"\n";
    }

};

int main(){
    Memallocator a(14);
    Memallocator b = a;
    a.print();
    b.print();

    Assignment x(11);
    Assignment y(15);
    y = x;// compiler reads it as y.operator=(x)
    x.print();
    y.print();




    return 0;
}