#include <iostream>
#include <memory>
#include <string>
class GameObj{
    private:
    std::shared_ptr<std::string> texturepath;
    std::string name;
    public:
    GameObj(std::string objname, std::shared_ptr<std::string> tex)
    : name(objname), texturepath(tex){}
    void printstatus(){
        std::cout << name << " using texture. Co-owners: " << texturepath.use_count() << "\n";
    }
};
int main(){
    // master textrue
    std::shared_ptr<std::string>texture = std::make_shared<std::string>("path\to\the\texture.png");
    GameObj player("steve", texture);
    GameObj enemy("ender dragon", texture);
    player.printstatus();


    return 0;
}