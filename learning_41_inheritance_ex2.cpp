#include <iostream>
class V8Engine{
    public:
    void igniteCylinders(){
        std::cout<<"engine sparked and cylinders ignited\n";
    }
};
class HyperCar:private V8Engine{
    //class uses private inheritance, public in parent downgrades to private in child(protected in praent-> private in child)
    // igniteEngine method is forbidden in main() since it is private class method
    public:
    void pressGasPedals(){
        std::cout<<"Presses gas pedals\n";
        igniteCylinders();// valid since parent inherited
    }

    
};
int main(){
    std::cout<<"ex2";
    HyperCar ferr;
    ferr.pressGasPedals();

    //error line:
    // ferr.igniteCylinders();
    // bacause of private inheritance, arrtibutes and methods from base class
    // is set private, so they remain inaccessible in main() block

}