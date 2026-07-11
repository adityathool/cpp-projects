
// smart pointers include 3 types of pointers built into c++ library <memory>

// 1. std::unique_ptr: (exclusive membership):
// Concept: Exactly one smart pointer can own a given piece of heap memory at any time.
// Behavior: It cannot be copied. If you try to copy it, the code will
// fail to compile. However, ownership can be transferred to a new variable using std::move.
// Best For: Private class arrays, unique resources, or single-owner buffers (like our IntArray).

// 2. std::shared_ptr: (shared membership): 
// Concept: Multiple smart pointers can point to the exact same memory
// location on the heap.
// Behavior: It maintains an internal hidden tracking variable called a Reference Counter.
// Every time you copy a shared_ptr, the counter increases by 1.
// When a shared_ptr goes out of scope, the counter drops by 1.
// The moment the counter reaches 0, the memory is instantly deleted from the heap.

// 3. std::weak_ptr : (temporary observer):
// Concept: Points to memory owned by a shared_ptr, but does not increase the reference counter.
// Best For: Preventing "circular memory leaks" (where Object A points to Object B, and Object B points 
// to Object A, making it impossible for the reference counters to ever drop to zero).
#include <iostream> 
#include <memory>

class SmartArr{
    private:
    int size;
    int capacity;
    std::unique_ptr<int[]>data;
    public:
    SmartArr(int s, int cap, int val): size(s), capacity(cap) {
        data = std::make_unique<int[]>(capacity);
        for(int i =0; i<size;++i){
            data[i] = val;
        }}
    // THE RULE OF ZERO: we dont need any five of those special constructors when making raw pointers
        void print(){
            for(int i=0; i <size;++i){
                std::cout<<data[i]<<" ";
            }
        }
    
};

int main(){
    std::cout<<"smart pointers\n";
    SmartArr a(5,6, 7);
    a.print();

    std::unique_ptr<int> ptr1 = std::make_unique<int>(100);
    std::unique_ptr<int> ptr2 = std::move(ptr1);

    // legit ways to turn nullified smart pointer into raw pointer:
    // ptr1 = std::make_unique<int>(200);
    // ptr1.reset(new int(200));
    // std::unique_ptr<int> ptr2 = std::make_unique<int>(200);
    // ptr1 = std::move(ptr2); 

    return 0;
}