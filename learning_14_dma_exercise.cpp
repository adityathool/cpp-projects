#include <iostream>


int main(){
    std::cout<<"dma challenge\n";
    // //remember
    // int* arr = new int[3];//creating array of 3 elements
    // arr[0] = 404;//does the same work as
    // *arr = 404;

    // continue
    int size;
    std::cout<<"enter the desired number of multiples of half(1/2) : \n";
    std::cin>>size;

    double* l = new double[size];
    for(int i = 0;i<size;++i){
        l[i] = 0.5*i;
        if(i >= size-1){
            std::cout<<l[i]<<"";
        }
        else{
            std::cout<<l[i]<<", ";
        }
    }

    delete[] l;

    // l = nullptr;
    std::cout<<*l;
    // forgetting to nullify l will make code unstable, 
    //delete commands frees up the heap memory form the ram
    // if pointer still exists, it has the address of that freed mem block
    // if other tihngs get stored in that block, l can interfere with it, and access it

    // next exercise learning_15_dma_exercise2.cpp









    return 0;
}