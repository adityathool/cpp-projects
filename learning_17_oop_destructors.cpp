#include <iostream>

//when classes are constructed, they automatically allocate memory to stack
//however if we allocate some space in heap with new, we use destructor to delete class manually
class render{
    private:
    int* heap_mem;

    public:
    render(){//contructor
    heap_mem = new int[100];//400 byte allocated to heap
    std::cout<<"memory for rendering allocated\n";
    }

    ~render(){//destructor
        delete[] heap_mem;
        std::cout<<"memory for rendering freed\n";
    }


};
//classes destroys itself the moment it hits the closing brace, 
//creating class inside function shows that when function closes up
//class is explicitely destroyed from memory(we can see text in destructor as output)
void start_render(){
    render ren;
}

int main(){
    std::cout<<"initialised!\n";
    start_render();
    //however if we create instance in main function, it will wait for main to finish
    //(the last line of main will output then we will see code in destructor executing)
    std::cout<<"ended rendering\n";


    //learning_17_oop_destructor_exercise.cpp

    return 0;
}