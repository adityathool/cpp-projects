#include <iostream>
#include<memory>
class IntArr{
    private:
    std::unique_ptr<int[]> data;
    int size;
    int capacity;
    public:
    IntArr(int dat, int s, int c): size(s), capacity(c){
        data = std::make_unique<int[]>(capacity);
        for (int i = 0; i<size;++i){
            data[i] = i*dat;
        }
    }
    void print(){
        for (int i = 0;i<size;i++){
            std::cout<<data[i]<<" ";
        }
    }
};
int main(){
    int num = 5;
    int table = 10;
    IntArr a(num, table, table);
    std::cout<<"Table of "<<num<<" upto "<<table<<" is\n";
    a.print();

    return 0;
}