#include <iostream>

int selling_prize(int prize, int tax){
    int extra = prize*tax/100;
    return prize+extra;
}


#include <iostream>

void calculate_bonus(int base_salary) {
    int bonus = base_salary * 0.10; // Local variable 'bonus' is born in RAM
    std::cout << "Bonus: " << bonus << "\n";
} // <-- 'bonus' is instantly DELETED from RAM here. Memory is freed!



int main(){
    // std::cout<<"functionchallange\n";
    // int cost;
    // std::cout<<"please enter theproduct amount \n";
    // std::cin>>cost;

    // int tax;
    // std::cout<<"whats the tax %?\n";
    // std::cin>>tax;
    // int selling_cost = selling_prize(cost, tax);
    // std::cout<<"the product's factory prize was "<< cost<<" by adding tax of "<<tax<<"% the total prize is "<<selling_cost<<"\n";

    //  memory management using scope of variables

    // local variables die instantly as their use is finished 
    // global variable sits in you memory the entire time running the code
    // it is preffererd to avoid using globals to save memory
    int salary = 5000;
    calculate_bonus(salary); 
    
    // 'bonus' no longer exists. Your computer's RAM is clean.




    return 0;

}