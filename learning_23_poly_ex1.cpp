#include <iostream>
//exercise: shape hiarchy
class Shape{
    public:
    virtual double area()=0;

    
    virtual ~Shape(){}


};

class Rectangle: public Shape{
    int l;
    int w;
    public:
    Rectangle(int len, int bre){
        l = len;
        w = bre;

        
    }
    double area() override {
        return l*w;
    }
    

};

class Circle : public Shape{
    double pie = 3.14;
    double rad;
    public:
    Circle(int r): rad(r){};


    
    double area() override {
        return pie*rad;

    }
};

void printarea(Shape& shape){
    std::cout<<shape.area()<<"\n";
}
int main(){
    Rectangle r(9,5);
    printarea(r);
    Circle c(10);
    printarea(c);
    // next exercise learning_24_poly_ex2.cpp
    return 0;
}