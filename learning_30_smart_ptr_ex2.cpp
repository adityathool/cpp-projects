#include <iostream>
#include <memory>
void swapOwnership(std::unique_ptr<int>& d1, std::unique_ptr<int>& d2){
    int temp = *d1;
    d1 = std::move(d2);
    d2 = std::make_unique<int>(temp);
    // this method workss but it bypasses the usefullness of unique_ptr
    // we copied value inside d1 into stack (inside temp)
    // at third line we allocate a new heap memory and storing this temp value init
    //this makes it slow ans inefficient because we had a better approach
    // we should swap heap of d1 to temp via move keyword
    // swap heap of d2 into d1
    // swap heap of temp into d2
    // this workflow requires no new heap allocation, making a method efficient.
}
void newSwapOwnership(std::unique_ptr<int>& d1, std::unique_ptr<int>& d2){
    std::unique_ptr<int> temp = std::move(d1);
    d1 = std::move(d2);
    d2 = std::move(temp);
}
int main(){
    std::unique_ptr<int> data1 = std::make_unique<int> (100);
    std::unique_ptr<int> data2 = std::make_unique<int> (300);
    swapOwnership(data1, data2);
    std::cout<<*data1<<", "<<*data2<<"\n";

    std::unique_ptr<int> data3 = std::make_unique<int> (100);
    std::unique_ptr<int> data4 = std::make_unique<int> (300);
    swapOwnership(data3, data4);
    std::cout<<*data3<<", "<<*data4;
  

    return 0;
}