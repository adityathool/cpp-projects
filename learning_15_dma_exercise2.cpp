#include <iostream>

void pointer_swapper(int* a, int *b){
    //a holds mem address of num1
    //b holds mem address of num2
    //we create a variable to hold value of num1
    int temp = *a;
    *a = *b;// get value of variable whose address is b and change it with
            // value of variable whose address is in a
    
    *b = temp;// update the value of variable whose address
              // is in b with temp value stored 



}

int main(){
    std::cout<<"dma challange 2\n";
    int num1 = 20, num2 = 10;
    pointer_swapper(&num1, &num2);
    std::cout<<num1<<","<<num2<<"\n";

    // next session in learning_16_oop.cpp




    return 0;
}