#include <iostream>
#include <cstddef>   // for size_t

class IntArray {
    int* data;    // pointer to the heap array
    int size;   // number of elements
    int val;
public:
    // 1. Constructor: allocate array and fill with val
    IntArray(int sz, int val = 0){
        size = sz;
        
        data = new int[size];
        for (int i = 0; i<size; i++){
            data[i] = val;
        
        } 

    }

    // 2. Destructor: free the array
    ~IntArray(){delete[] data;}

    // // 3. Deep copy constructor (you write this)
    IntArray(const IntArray& other){
        size = other.size;  
        
        data = new int[other.size];
        for (size_t i = 0; i<other.size; ++i){
            data[i] = other.data[i];
        }
    }

    // 4. Print helper
    void print() {
        for(int j = 0; j<size;++j){
            std::cout<< data[j];
            if (j==size-1){
            std::cout<<"\n";
            }
            else{std::cout<<", ";}
            
        }
        
    }
};

int main(){
    IntArray arr(9, 9);
    IntArray arr2 = arr;
    arr2.print();
    //next exercise in  learning_21_copy_constructor_ex2.cpp
    return 0;
}