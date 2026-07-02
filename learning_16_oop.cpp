#include <iostream>
#include <string>

class SmartPhone {
private://trying to modify the values inside this block causes a compiler error
    std::string passcode;
    int storage = 256;
    std::string brand;

public:
    //c++ class initialisation(constructor method(like python"__init__"))
    //the method has to have the same name as class
    SmartPhone(std::string b, int s){
        brand = b;
        storage = s;
        
        std::cout<< brand << " phone created!\n";

    }

    void display_info(){
        std::cout<<brand<<" with "<< storage<<" gigabyte storage\n";
    }

    
    void set_passcode(std::string code){
        if (code.length() >= 4){
            passcode = code;
        }
        else{std::cout<<"failed to set passcode!\n";}
    }

     std::string get_passcode(){
        return passcode;
     }
};
class BankAccount{
    private:
    double balance;
    public:
   // BankAccount(double amnt){//look at this initialisaton, c++ first
    //    balance = amnt;  }    //initialise balance to 0 then assigns to amnt
                            //c++ has a syntax to directly initialise balance with an input var
    
    BankAccount(double amnt) : balance(amnt){}  //does the same job but even quicker
    void deposit(double amnt){
        if (amnt <= 0){
            std::cout<<"please enter a valid amount!\n";
        }
        else{
            balance = balance+amnt;
            std::cout<<"you successfully deposited "<< amnt<<"\n";
        }
        
    }
    double checkbalance(){
        return balance;
    }


};







int main(){
    std::cout<<"oop\n";

    //creating class instance
    SmartPhone adiphone("apple", 256);
    adiphone.set_passcode("2008");

    std::cout<<"password set to "<<adiphone.get_passcode()<<"\n";
    adiphone.display_info();
    
    BankAccount john_account(20000);
    john_account.deposit(3000.5);
    std::cout<<"you current bank balance is "<<john_account.checkbalance()<<"\n";

    //next session in learning_17_oop_destructer.cpp

    return 0;
}