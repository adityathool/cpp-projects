#include <iostream>
class Mobile{
    public:
    Mobile() {std::cout<<"Mobile created\n";}
    ~Mobile(){std::cout<<"Mobile Destroyed\n";}
};
class LcdDisplay{
    public:
    LcdDisplay (){std::cout<<"Lcd Display Created\n";}
    ~LcdDisplay(){std::cout<<"Lcd Display Destroyed\n";}
};
class Device:public Mobile{
    public:
    LcdDisplay screen;
    //Constructor chaining goes here:)
    Device():Mobile(){std::cout<<"Device Constructor Body workd\n";}
    ~Device(){std::cout<<"Device Distructor Workd\n";}
};
int main(){
    std::cout<<"creating device\n";
    Device apple;
    std::cout<<"Destroying everything\n";
    // following the LIFO order, the objects are wiped out of memory
    return 0;
}