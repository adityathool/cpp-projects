#include <iostream>
class Shape{
    public:
    int* arr;
    
    virtual double area()=0;
    virtual void array_builder(Shape& shape,int len, int val)=0;
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
    void array_builder(Shape& shape,int len, int val) override{
        shape.arr = new int[len];
        for(int i = 0; i< len;++i){
            shape.arr[i] = val;
            std::cout<<shape.arr[i];
        }
    }
    ~Rectangle(){delete[] arr; arr = nullptr;}
    double area() override {
        return l*w;
    }
};
void printarea(Shape& shape){
    std::cout<<shape.area()<<"\n";
    
}
int main(){
    Rectangle r(2,5);
    r.array_builder(r, 6,7);
    printarea(r);


    return 0;
}