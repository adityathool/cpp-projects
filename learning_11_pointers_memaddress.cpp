#include <iostream>

int func(int &val){
    val = 0;
    return 0;
    
}

int main(){
    std::cout<<"pointers and mem address\n";
    int ral = 3;
    func(ral);
    std::cout<<ral<<"\n";
    //the function explicitely changes the 
    //value of variable inside of main func
    //because & operator finds the physical address 
    //where variable ral resides, actively allowing 
    //the func to change the value

    //what are pointers?
    //ans. every variable has a value and a mem address 
    //in the ram, so pointer is a variable specialised
    //to store a memaddess of a variable

    //how to create pointers?
    //ans. to create pointer(a specialised var) we use asterix
    //over the datatype(int* ptr = __). pointers refer to memaddress
    //so we use ampersand and var name to fetch its mem address
    //and asign in to pointer
    //for ex.->
    int salary = 20000;
    int* ptr_salary = &salary;
//     ^this          ^this
//      asigns        fetches
//      pointer      memaddress

    std::cout<<"value of salary is "<<salary<<"\n";
    std::cout<<"memaddress of salary is "<<&salary<<"\n";
    std::cout<<"value stored in ptr_salary "<<ptr_salary<<"\n";

    *ptr_salary = 40000;
    //this and previus aastrix are different.
    //this astrix gives command: go to the address
    //in this pointer and change the value of it to 40000
    //while first asterix was for declaring a integer memaddress pointer

    // as we asigned salary address to ptr_salary
    // asterix on ptr_salary goes to memaddress in it
    // which is of salary and therby changes salary by given vlaue
    //the asterix over ptr var also let u read value of memaddress
    //in it
    std::cout<<*ptr_salary<<"\n";//it prints 40000 instead of memaddress
    std::cout<<"new salary is "<<salary<<"\n";

    int values[] = {1,2,3,4};
    int* ptr = values;
    ptr = ptr+2;
    *ptr = 44;
    std::cout<<values[2]<<"\n";
    //here c++ set the value[2] with 44
    //whts the reason:
    //when we create pointer ptr, it stores memaddress of array
    //that is basically memaddress of index 0(1), we shifted ptr to 2 steps
    //since it stores memaddress they do allow integer math instead:
    //shifts memaddress of ptr by 2 step, but the std value of index in array 
    // is 4 byte(every index has value 4byte) it deos math:
    // new memaddress= olod address + steps moves*size of datatype
    // suppose the address in ptr is 0x0000, ptr updates to 
    // 0x0000 + 2*4 = 0x0008
    //if every index of array has 4 byte size, and index 0 address is 0x0000
    //then the index 2(3rd element) has address 0x0008

    //since *ptr modifies the variable whose address in it, 
    //it modified 3 to 44



//next session in learning_12_stack_heap.cpp

}