# include <iostream>
# include <string>
class Entity{
    protected:
    int m_id;
    public:
    Entity(int id):m_id(id){std::cout<<"Entity made\n";}
};
class Renderable{
    private:
    std::string texture;
    public:
    Renderable(std::string tex):texture(tex){std::cout<<"TextureRender Created\n";
    }

};

class Player: public Entity{
    Renderable m_sprite;
    public:
    Player(int id, std::string tex):Entity(id), m_sprite(tex){
        std::cout<<"Player created. #entity_id: "<<id<<" #renderable_texture: "<<tex<<"\n";
    }
};
int main(){
    std::cout<<"ex2\n";
    Player me(1234, "path/to/the/texture.tiff");
    
}