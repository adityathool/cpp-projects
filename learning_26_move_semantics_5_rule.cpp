#include <iostream>

// rule of five adds two more in-built methods to our class 
//1. move constructor
//2. move assignment

//rvalue: a temporary object that we will use to copy our object and destroy(it is passed to method via && operator)
//lvalue: an object that we'll define from rvalue
// exporting previous class 
class IntArray{
    private:
    int* data;
    int size;
    int capacity;

    public:
    IntArray(int dat,int si,int len){
        std::cout<<"regular constructor called\n";
        size = si;
        capacity = len;
        data = new int[capacity];
        for(int i =0; i<size;++i){
            data[i] = dat;
        }
    }
    ~IntArray(){
        std::cout<<"deleting memory\n";
        delete[] data;}
    IntArray(const IntArray& other){
        std::cout<<"initialising copy constructor\n";
        size = other.size;
        capacity = other.capacity;
        data = new int[capacity];
        for(int i = 0; i < size; ++i){
            data[i] = other.data[i];
        }
    }
    IntArray& operator=(const IntArray& rhs){
        std::cout<<"implementing copy assignment\n";
        if (this == &rhs){
            return *this;
        }
        delete[] data;
        size = rhs.size;
        capacity = rhs.capacity;
        data = new int[capacity];
        for(int i=0;i< size; ++i){
            data[i] = rhs.data[i];
        }
        return *this;

    }
    //move constructor here:
    IntArray(IntArray&& other) noexcept { // && operator defines other as a temporary rvalue thats abt to be destroyed, noexcept tells that this func never throw error
        std::cout<<"working on move constructor\n";
        //COPY THE STATUES VALUES
        capacity = other.capacity;
        size = other.size;
        data = other.data;
        // Step 2: DANGEROUS POINTER RESET (Crucial!)
        // We must set the temporary object's pointer to nullptr. 
        // If we don't, when 'other' is destroyed in the next millisecond, 
        // its destructor (~IntArray) will delete the memory we just stole!
        other.data = nullptr;
        other.size = 0;
        other.size =0;
    }
    IntArray& operator=(IntArray&& rhs) noexcept {
        std::cout <<"executing move assignment";
        if(this == &rhs){
            return *this;
        }
        delete[] data;
        data = rhs.data;
        capacity = rhs.capacity;
        size = rhs.size;
        // delete or destroy our rhs object
        rhs.data = nullptr;
        rhs.capacity=0;
        rhs.size = 0;
        return *this;
    }
    void print(){
        for(int i =0; i< size;++i){
            std::cout<<data[i]<<" ";
        }
    }
};


int main(){
    // now our class has full fledged rule of 5 applied, lets explore where it calls:
    //copy constructor
    //copy assignment
    //move constructor
    //move assignment
    std::cout<<"step uno\n";
    IntArray arr1(2,4,4);
    std::cout<<"step dos\n";
    IntArray arr2 = arr1;//copy constructor works
    IntArray arr3(3,6,6);
    std::cout<<"step tres\n";
    arr3=arr1;// copy assignment works, deletes arr3's properties, pastes arr1's values
    std::cout<<"step quatro\n";
    IntArray arr4 = std::move(arr1);// move constructor calls, treats arr1 temp, and deletes it, pasting its props to arr4
    IntArray arr5(5,7,7);
    arr5 = std::move(arr2);// move assignment works, deletes arr2, pasts its values to arr5
    








    











    return 0;
}