#include <iostream>
#include <string>

int main(){
    std::cout << "hello world"<<std::endl;


    //variables and typecasting
    int score = 14;
    int play = 3;
    int absolute_mean = score/play;
    double acurate_mean = static_cast<double>(score)/play;

    std::cout <<"absolute mean is \n"<<absolute_mean<<std::endl;
    std::cout <<"accurate mean is "<<acurate_mean<<std::endl;

    //string slicing
    std::string product = "nfs most wanted cd";
    int quantity = 4;
    double prize = 499.99;

    std::cout<<"you have ordered "<<quantity <<" "<<product<<"s "<<"for a total prize of "<<quantity*prize<< std::endl;


    //input system(single text or a single number without spaces)
    

    //input system for text with spaces, numbers
    // syntax: getline(source, destination_variable)

    // std::string text;
    // std::cout <<"enter a multidigit number or a text with spaces\n";
    // std::getline(std::cin, text);
    // std::cout <<"your text is "<<text;

    // using cin and getline twice terminates the code
    // before executing getline input(this happens because the
    // cin has an internal [enter ] input, so the getline assumes
    // you enterd enter and terminates the code) to remove the enter input we do:
    int num;
    std::cout <<"enter any number\n";
    std::cin>>num;
    std::cin.ignore();//we use this ignore fuction to bypass the [enter] buffer inside of cin
    std::cout <<"you entered number "<<num<<"\n";

    std::string inp;
    std::cout <<"enter a multiline tex\n";
    std::getline(std::cin, inp);
    std::cout <<"you typed "<<inp;

    //summary:
    // from this code you understood the core fundamentals of c++ programming
    // that includes defining variables, typecasting, slicing a string
    // to put variables in it, the two input taking types, and figured
    // out the [enter] buffer using std::cin.ignore() function. Congratulations, developer!!

    //next sesssion will continue in new file learning_1.cpp







    
    return 0;
}