#include<iostream>
#include<memory>
#include<unordered_map>
#include<string>
class Image{
    public:
    std::string path;
    Image(std::string& p):path(p){
        std::cout<<"Loaded a new image from "<<path<<"\n";
    }
    ~Image(){std::cout<<"Image memory freed up";}
};
class ImageCache{
    public:
    std::unordered_map<std::string, std::weak_ptr<Image>> cache;
    std::shared_ptr<Image> fetchImage(std::string& filepath){
        auto it  = cache.find(filepath);
        if (it!=cache.end()){
            std::cout<<"image found\n\n";
            if (!it->second.expired()){
                std::shared_ptr<Image> imgptr = it->second.lock();
                return imgptr;}
            else { std::cout<<"image pointer null, creating new pointer\n\n";
                auto newimg = std::make_shared<Image>(filepath);
                cache[filepath] = newimg;
                return newimg;}
        }
        else{std::cout<<"Image doesnt exist, creating new one...\n\n";
            auto newimg = std::make_shared<Image>(filepath);
            cache[filepath] = newimg;
            return newimg;}

        }
};
int main(){
    ImageCache a;
    std::string pat = "is/that/u/obito.png";
    a.fetchImage(pat);
    a.fetchImage(pat);
    return 0;
}