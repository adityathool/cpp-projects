#include <iostream>
// the rule of three: class must contain a constructor, destructor, and a copy constructor

class Nocopy{
    public :
    int* ptr;

    Nocopy(int val){             // in this class there is no copy constructor
        ptr = new int(val);      //so compiler's shallow copy works when we create new copy of class
    }                            //using Nocopy b = a;, here a.ptr holds address of heap(stored 10)
                                 //b.ptr also holds address of that heap block(stored 10)
                                 // when destructor of b works-->deletes the heap block, then a's destructor work
                                 // tries to delete that heap(deleted by b's destructor), causes an error

    ~Nocopy(){
        delete ptr;
        
    }
};

class Copyclass {
    public:
    int* ptr;

    Copyclass(int val): ptr(new int(val)){}
    //copy constructor here
    Copyclass(const Copyclass& x): ptr(new int(*x.ptr)){}  
    //we are creating new heap block whenever class is copied, assign its address to ptr 
    //and storing the value of previous class instance to a new one
    // when we created new object of rhis class as j, assigned as j =i, copy construcotr runs
    //Copyclass& x stores our previous object(i) in x, then *x.ptr returns the value in heap block of i
    //new int(value) creates new heap block and stores value(i.e value in previos heap). 
    //now destructor doesnt override delete on the same heap block, preventing error


    // when getting an object we wanna copy via value(not by ref), compiler
    //  itself creates a copy of the object-->the copy constructor
    //   that is being written runs over and over, infinitely

    ~Copyclass(){delete ptr;}
};
//the Copyclass wont work if we create 2 distinct object and assigned their values to each other
//Copyclass a(10);
//Copyclass b(29);
//b = a;
//tis will cause leakage and double delete(like previous discussion)
// to solve this, we use copy assignment method(function)used in our new Wrapper class
class Wrapper {
    public:
    int* ptr;
    Wrapper(int val):ptr(new int(val)){}
    ~Wrapper(){delete ptr;}

    //copy constructor
    Wrapper(const Wrapper& z): ptr(new int(*z.ptr)){}

    //copy assignment
    // it is dedicated method in c++
    Wrapper& operator=(const Wrapper& rhs)
    //step by step breakdown of this line:
    //Wrapper& operator= tells compiler that a given method is a from Wrapper class and should returntype classname&
    //const Wrapper& rhs returns the value of object on the rhs of (b=a)i.e a
    {
        if (this == &rhs){
            return *this;
        }
        delete ptr;
        ptr = new int(*rhs.ptr);
        return *this;
    }




};


int main(){
    Nocopy a(10);
    // Nocopy b = a;// error pops up as we discussed
    Copyclass i(10);
    Copyclass j = i;
    
    Wrapper w1(10);
    Wrapper w2(20);
    w2 =w1;
    std::cout<<*w2.ptr;
    
    // Copyclass x(29);
    // x = i;

    //when we write x = i, compiler again runs shallow copy, thus x.ptr = i.ptr
    //both poineters of x and i point to one heap block, thus double delete error occurs
    //also x.ptr was meant to point heap(stored 29), but is points to heap that i's ptr also points
    //that heap(29) is lost forever
    //we do class asignment
    


    //exercise in learning_20_copy construcotr_ex.cpp

    return 0;
}