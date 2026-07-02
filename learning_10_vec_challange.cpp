#include <iostream>
#include <vector>
//major rookie mistakes in this code

//*tracking vectors by indices in unprofessional
// u can clean memory up by doint for (int i : vec)
//
//*passing the vector by its value causes c++ to 
//to build enitre copy of vector into its ram
//if passed by reference, saves much of the memory
//
int maxfinder(std::vector<int> &vec, int size){//updated by &vec to pass by ref
    int max = vec.at(0);
    for(int i : vec){// updating it with straighforward tracking(unlike for (int i = 0; i<size;++i))
        if (max <= i){
            max = i;
        }
    }
    std::cout<<max;

    return 0;
}


int main(){
    std::cout<<"vector challenge\n";
    std::vector<int> entry = {12,32,4,6,5,43,65,783,5};
    int length = entry.size();
    maxfinder(entry, length);


    // next session continues in learning_11_pointers_memaddress.cpp



}