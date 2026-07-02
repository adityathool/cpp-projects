#include <iostream>
#include <vector>


// passing vector from function to function by reference
void print_data(std::vector<int> &vec){
    for(int i : vec){
        std::cout<< i << " ";
    }
    std::cout<<'\n';
}

int main(){
    std::cout<<"vectors\n";
    // empty vector of integers
    std::vector<int> numbers;
    // non empty vector
    std::vector<int> grades = {10, 20,20, 40, 40};
    // vector allocated with n items all initialised to 0
    std::vector<int> zeros(10);// vector including 10 zeros
    // a vector of 5 elements initialised to 100
    std::vector<int> hundreds(5,100);


    std::cout<<"vector\n"<<grades[4]<<"\n";


    // adding elements
    std::vector<int> items;
    items.push_back(19);// items is now [19]
    items.push_back(23);// items is now [19,23]
    items.push_back(30);
    // deleting elements
    items.pop_back();// items is now [19,23]
    items.clear();// items cleared and its size is zero

    std::vector<int> gifts = {4,4,5};
    int length = gifts.size();
    std::cout<<length<<"\n";

    bool is_empty = gifts.empty();// checks if a vec is blank or not
    std::cout<<is_empty<<"\n";
    // accessing elements
    std::vector<int> entry = {5,6,5,3,2,1,12};
    for(int i = 0;i<entry.size();++i){
        std::cout<<"element no. "<<i<<" is "<<entry[i]<<"\n";
    }

    for(int i = 0;i<entry.size();++i){
        std::cout<<"entry no. "<<i<<" is "<<entry.at(i)<<"\n";
        
    }
    std::cout<<entry.front()<<"\n";//returns fiest elemnt
    std::cout<<entry.back()<<"\n";//returns seocnd element
    
    // for printing every element of vector without caring indices
    // Reads as: "For every integer 'grade' inside the 'grades' vector"
    for (int ent : entry) {
        std::cout << ent << " ";

    }
    std::cout<<"\n";

    std::vector<int> data = {1,3,3,5,5,6,7,7};
    print_data(data);

    // next session continues in learning_10_vec_challange.cpp









    return 0;
}