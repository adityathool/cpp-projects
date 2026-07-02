#include <iostream>

int main(){
    std::cout<<"dynamic memory allocation\n";
    int size;
    std::cout << "Enter array size: ";
    std::cin>>size;
    int* arr = new int[size];
    // this has created an array of desired size 
    //and arr is the pointer for its mem address
    //(also allocated sufficient space for array in heap)

    //use like normal array
    for (int i = 0; i<size;++i){
        arr[i]= i*5;// the reason we dont write * over arr is
                    //because arr[i] doesnt point to mem address
                    //it is saying go to the  ith element of array
                    //and modify it. it is different than integer case.
                    //see if we print a pointer of array, it will show mem address
                    //of index 0, to print it we write std::cout<<*arr, but it is array
                    // writing arr[any] without asterix just tells the compiler to go to mem address of 
                    // that element(these [] contain secret asterix !!!)
    }
    //time to delete array form heap so no mem is leaked
    delete[] arr;// note square brackets
    // in int num*= new int;, u allocate 4 byte space
    //deleting it doesnt require box bracket
    //but deleting array requires
    // delete the pointer so it doesnt point deleted mem
    arr = nullptr;


    //next session in learning_14_dma_exercise.cpp



    return 0;
}