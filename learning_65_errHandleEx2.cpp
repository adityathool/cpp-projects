#include <iostream>
#include <stdexcept>
class Vector2D{
    public:
    int x,y;
    Vector2D(int xc,int yc):x(xc), y(yc){}
    Vector2D(Vector2D&& other) noexcept{
        x=other.x;
        y = other.y;
        other.x = 0;
        other.y = 0;
    }
};
int main(){
    Vector2D playerCoordinates(15,250);
    std::cout<<"Player spawned at x:"<<playerCoordinates.x<<", y:"<<playerCoordinates.y<<"\n";
    Vector2D mapPlayerCoordinates = std::move(playerCoordinates);
    std::cout<<"Player Coordinates become x:"<<playerCoordinates.x<<", y:"<<playerCoordinates.y<<"\n";
    std::cout<<"Player on map spawned at x:"<<mapPlayerCoordinates.x<<", y:"<<mapPlayerCoordinates.y<<"\n";
    return 0;
}