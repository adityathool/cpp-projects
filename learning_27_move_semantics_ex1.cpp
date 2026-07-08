#include <iostream>

// objective: create a safe pop_back method that will clear out last array element and is safe to apply on hollowed object
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
    void popback(){
        if (size!=0){
            size = size-1;
        }
        else{std::cout<<"error:invalid array\n";}
    }
    void print(){
        for(int i =0; i< size;++i){
            std::cout<<data[i]<<" ";
        }
        std::cout<<"\n";
    }
};

int main(){
    IntArray a(4,5,5);
    IntArray b = std::move(a);
    a.print();
    a.popback();
    a.print();

    return 0;
}