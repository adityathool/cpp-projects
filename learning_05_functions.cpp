#include <iostream>



//types for user functions
    // *no input no output func
    // ex.
void greetuser(){
    std::cout<<"welcome, this is a custom function\n";
}

// function that requires an input, but doesnt have any to return
void summer(int a, int b){
    std::cout<<"this function prints out a sum of input given "<<a<<" and "<<b<<" that is "<< a+b<<"\n";
}

// a function that doesnt expects an input but return a value
double getvalue(){
    return 123456;
}
// a function that expects ofr input and returns the values too
int calculate_mean(int score, int turns){
    return score/turns;
}
// pass by value vs pass by reference
//pass by value does modify a value locally, it doesnt affect the main variable
void modifyvalue(int x){
    x = 100;// x = 100 is only valid inside a function, it doesnt affect te outsidevariable
}

// pass by referance actually modifies the outside fucntion variables
void modifyref(int &x){ //only chang is adding ampersand(&) tells the code to go in a specific memory address
    x = 100;
}
// declearation vs definition
// involves writing a prototype at the start of main funtion
// define the prototype at the end of main function

int getfactorial(int a);
int main(){
    std::cout<<"functions\n";
    

    greetuser();// calling a function to run in main code
    summer(2,3);// calling a summer function
    std::cout<<getvalue();// calling it requires an output like cout, because it returns a value, doesnt print it out
    
    int credits = 24;
    int trys = 4;
    int mean = calculate_mean(credits, trys);
    std::cout<<"the mean of your data is "<<mean<<"\n";

    // pass by value
    int num = 3;
    modifyvalue(num);
    std::cout<<num<<"\n";// num hasnt changed to 100, it is 3

    //pass by referance
    modifyref(num);
    std::cout<<num<<"\n";// num has changed to 100

    std::cout<<getfactorial(5);// implementing the prototype




    return 0;
}
// defining the prototype
int getfactorial(int a){
    if(a == 0||a==1){return 1;}
    return a*getfactorial(a-1);

    // next session continues in learning_6challangefunction.cpp
    
}