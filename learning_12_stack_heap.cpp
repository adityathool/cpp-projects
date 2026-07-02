#include <iostream>

int main(){
    std::cout<<"stack and heap\n";
    //To request memory from the Heap,
    // C++ provides two specific keywords: new and delete.
    int* ptr = new int;// allocates 4bytes(size of int) into heap memory
    *ptr = 45;//putting value in new heap memory
    std::cout<<"heap value "<< *ptr;

    //stack is where our local variable lives in ram, after work is done, it deletes itself
    //heap is a memory in ram that stays forveer, it doesnt delete itself by its own
    //it is upto us to manually delete heap memory 
    //so code doesnt leak ram
    delete ptr;


    ptr = nullptr;// deletes the pointer itself


    //use stak for: normal small variables(iny, double)
    //and quick math calculations
    //use heap for: massive data assets, arrays, where the final 
    //size is unknown
    int size;
    std::cin>>size;
    int* my_array = new int[size];// creates an integer aaray and allocates
    // 4*size memory in heap ram


    // next session in learning_13_dyna_memo_alloc.cpp
    
    return 0;
}