#include <iostream>

// when managing array dynamically, we need three private vars
// int* data- points to the array first element
// int size- initial size of an array we will use
// int capacity- tracks how much space is allocated on heap in total
class IntArray{
    private:
    int* data;
    int size;
    int capacity;

    public:
    IntArray(int dat,int si,int len){
        size = si;
        capacity = len;
        data = new int[capacity];
        for(int i =0; i<size;++i){
            data[i] = dat;
        }
    }
    ~IntArray(){delete[] data;}
    IntArray(const IntArray& other){
        size = other.size;
        capacity = other.capacity;
        data = new int[capacity];
        for(int i = 0; i < size; ++i){
            data[i] = other.data[i];
        }

    }
    IntArray& operator=(const IntArray& rhs){
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
    void print(){
        for(int i =0; i< size;++i){
            std::cout<<data[i]<<" ";
        }
    }
};

int main(){
    IntArray a(6,7, 7);
    IntArray b = a;
    a.print();
    b.print();
    IntArray c(2, 5,7);
    a = c;
    c.print();
    IntArray arrayA(6,5,5);
    IntArray arrayB(7,7,100);
    arrayA = arrayB;




    return 0;
}