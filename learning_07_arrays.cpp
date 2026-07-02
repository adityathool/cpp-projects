#include <iostream>

void printarray(int arr[], int size){
    for (int i =0;i<size;++i){
        std::cout<<arr[i]<<" ";
    }
}


int main(){
    // std::cout<<"arrays\n";
    // // creating array
    // int grades[] = {10,20,30,40,50};// method 1
    // int classes[4] = {5,6,7,8};// method 2(stating size of array)
    // int years[100];// method 3(initialising a blank array)
    // std::cout<< grades[2]<<"\n"<<classes[1]<<"\n";

    // // changing or adding elements to blank array
    // grades[0] = 1020;
    // years[1] = 2026;
    // std::cout<<grades[0]<<"\n";
    // std::cout<<years[1]<<"\n";
    
    // // for (int i=0;i<=std::size(years); ++i){
    // //     years[i] = i+2026;
    // //     std::cout<<years[i]<<" ";
    // // }
    
    // int time = 0;
    // int l[4];
    // int x= 0;
    // builiding up an array with for loop and 
    // constanatly updating its indices by one and 
    // updating the next index with increment of 100
    // while(time<=10){
    //     l[0]=x;
    //     for (int i=1; i<=std::size(l); ++i){
    //         l[i]=l[i-1]+100;
    //         std::cout<<l[i-1]<<" ";
    //     }
    //     x=x+1;
    //     ++time;
    //     std::cout<<"\n";

    // }
    // int marks[]={20,30,20,60};
    // int total = std::size(marks);
    // printarray(marks,total);


    // next session in leanig_8_arraychallange.cpp
    
    






    return 0;
}