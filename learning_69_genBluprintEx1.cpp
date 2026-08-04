#include <iostream>
#include <string>

template <typename T>
void swapValues(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
    std::cout<<a<<" "<<b<<"\n";
}
int main(){
    std::string str1 = "string1";
    std::string str2 = "string2";
    int i = 10;
    int j = 20;
    double pi = 3.14;
    double R = 8.314;
    swapValues(str1, str2);
    
    swapValues(i,j);

    swapValues(pi,R);
    

    return 0;
}