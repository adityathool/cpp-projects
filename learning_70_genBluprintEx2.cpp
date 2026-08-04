#include <iostream>
#include<string>
template <typename T>
class DataPair{
    T pair[2];
    public:
    DataPair(T a, T b):pair{a,b}{
        
    }
    T getFirst(){
        return pair[0];
    }
    T getSecond(){
        return pair[1];
    }
};
template<typename F>
void print(F& duple){
    std::cout<<duple.getFirst()<<" "<<duple.getSecond()<<"\n";
}
int main(){
    
    DataPair stringPair("f", "b");
    DataPair intPair(1,2);
    DataPair doublePair(10.3, 10.5);

    
    print(stringPair);
    print(intPair);
    print(doublePair);
    
    return 0;
}