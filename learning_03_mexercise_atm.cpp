#include <iostream>
#include <string>

int main(){
    std::cout<<"welcome to the atm machine!\n";
    int pass = 1234;
    int attempts = 3;
    int input = 0;
    bool access_granted = false;
    
    
    while(1){
        std::cout<<"enter your passcode\n";
        std::cin>>input;
        attempts = attempts - 1;

        if(input==pass){
            access_granted = true;
            break;
        }
        else{
            std::cout<<"password incorrect\n"<<attempts<<" attempts left\n";
        }
        if(attempts==0){
            break;
        }
    }
    if (!access_granted){
        std::cout<<"you entered incorrect password several times, acess denied";

    }
    else{
        std::cout<<"access granted, your acount number is 123456xxx\n total amount is $20000";
    }

        


    
    return 0;

    //next session continues in learning_4.cpp
}