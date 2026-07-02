#include <iostream>
#include <string>

int main(){
    //session 2 of learning
    std::cout<<"testing env...done\n";

    //conditionals
    // int num1;
    // int num2;
    // int num3;
    // std::cout <<"enter a number\n";
    // std::cin>>num1;
    // std::cin.ignore();
    // std::cout <<"enter another number\n";
    // std::cin >>num2;
    // std::cin.ignore();
    // std::cout << "try to gues the sum of "<<num1<<" and "<<num2<<"\n";
    // std::cin>>num3;

    // if (num3>num1+num2){
    //     std::cout <<num3<< " is greater than sum of "<<num1<< " and "<<num2;
    // }
    // else if (num3<num1+num2){
    //     std::cout <<num3<< " is smaller than the sum of "<<num1<<" and "<<num2;
    // }
    // else{
    //     std::cout<< "you perfectly entered the right sum of "<<num1 <<" and "<<num2;
    // }

    //comparison operators(==, !=, >, <, <=, >=)
    //logical operators(&&(and), ||(or), !(not))

    //using logial operators

    std::string name = "adi";
    bool haskey = false;

    if (name == "andi" && haskey){
        std::cout<<"car statred";

    }
    else if (name == "andi" && !haskey){
        std::cout<<"show ur keys, andi";

    }
    else if (name != "andi" && haskey){
        std::cout<<"ur not andi! howdo u have the keys?";

    }
    else {
        std::cout <<"car wont start for strangers";
    }

    // int age;
    // std::cout <<"enter ur age\n";
    // std::cin>>age;
    // std::cin.ignore();

    // std::string passcode;
    // std::cout <<"enter ur passcode\n";
    // std::cin>>passcode;
    // std::cin.ignore();

    // if(age>= 13){
    //     if (age >= 18 && passcode == "devpass"){
    //         std::cout<<"acess granted for dev tier!";
    //     }
    //     else if (passcode == "publicpass"){
    //         std::cout<<"public access granted";
    //     }
    //     else{
    //         std::cout<<"access denied";
    //     }
        
    // }
    // else {
    //     std::cout << "access denied for under ages";
    // }


    // summary:
    // learnt conditional statments, logial operatoer, comparison operators
    //next session in learning_3.cpp



    return 0;
}