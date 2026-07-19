#include<iostream>
#include<memory>
// challange fix the given code snippet for an error
struct Gadget{
    void activate(){std::cout<<"Gadget activated";}
};
int main(){
    std::weak_ptr<Gadget> observer;
    {
        auto shared = std::make_shared<Gadget>();
        observer = shared;
    }// data on heap deleted
    if (observer.expired()){std::cout<<"Sorry, the result was expired\n";}
    else{Gadget* rawPtr = observer.lock().get();
         rawPtr->activate();}

    return 0;
}