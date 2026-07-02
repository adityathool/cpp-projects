#include <iostream>
#include <string>

int main(){
    std::cout<<"learning_4";
    //for loops
    for (int i= 0; i<=10; ++i){
        std::cout<<i<<"\n";
    }
    //outputs stream of natural numbers upto 10

    for (int i = 0;i <=20;i += 2){
        std::cout<<i<<"\n";
    }
    //outputs even numbers upto 20

    //quick multiplication table quiz code
    // int num;
    // std::cout<<"Enter a number to calculate thier multiplication table\n ";
    // std::cin>>num;
    // for(int i = 1; i <=10;++i){
    //     std::cout<<num<<" x "<<i<<" = "<<num*i<<"\n";
    // }

    //nested loops(creating a right triangle as output)
    for(int j = 1;j<=10;++j){
        for (int i= 1;i<=j;++i){
            std::cout<<"*";
    }
    std::cout<<"\n";

    }
    return 0;
    //next session continues in learning5functions.cpp
}
