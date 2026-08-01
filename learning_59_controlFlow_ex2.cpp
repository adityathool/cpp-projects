#include <iostream>
#include<string>
enum class Operation{Add,Multiply};
int main(){
    Operation state = Operation::Multiply;
    int a,b,result;
    std::cout<<"Enter number a\n:";
    std::cin>>a;
    std::cout<<"Enter number b\n:";
    std::cin>>b;
    
    switch(state){
        case Operation::Add:{
            std::cout<<"Executing addition\n";
            result = a+b;
            break;
        }
        case Operation::Multiply:{
            std::cout<<"Executing Multiplication\n";
            result = a*b;
            break;
        }
    }
    std::cout<<"Result: "<<result<<"\n";

    return 0;
}