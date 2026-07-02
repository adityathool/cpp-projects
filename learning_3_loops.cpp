#include <iostream>
#include <string>

int main(){
    std::cout<<"checking env....done\n";
    //looops
    for(int i = 1;i<=5; ++i){
        std::cout<<"count "<<i<<"\n";
    }

    //number guesser
    int num = 6;
    int guess = 0;
    std::cout<<"guess the number";
    std::cin>>guess;
    while(guess!=num){
        std::cout<<"wrong number!\n";
        std::cin>>guess;
    }
    std::cout<<"you guessed the right number\n";


    // do-while statment
    int num1;
    int num2;
    int num3;
    std::cout<<"enter a right value or else the code wont stop\n";
    
    std::cout <<"enter a number\n";
    std::cin>>num1;
    std::cout<<"enter second number\n";
    std::cin>>num2;
    
    do {
        
        std::cout<<"guess their sum\n";
        std::cin>>num3;
        if (num1+num2>num3){
            std::cout<<"sum of "<<num1<< " and "<<num2<< " is greater than "<< num3<<"\n";
        }
        else if (num1+num2<num3){
            std::cout<<"sum of "<<num1<< " and "<<num2<< " is smaller than "<<num3<<"\n";
        }




    }
    while(num1+num2!=num3);
    std::cout<<"you added "<<num1<< " and "<<num2<< " right\n";
    //were continuing this session in a exercies project : atm.cpp


    return 0;
}