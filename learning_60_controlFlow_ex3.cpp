#include<iostream>
enum class ImageFormat {RAW,BMP,PNG};
int main(){
    ImageFormat format = ImageFormat::PNG;
    switch(format){
        case ImageFormat::RAW:std::cout<<"Parsing raw sensor data...\n";
        [[fallthrough]];
        case ImageFormat::BMP:std::cout<<"Processing uncompressed bitmap vectors...\n";
        break;
        case ImageFormat::PNG:
        std::cout<<"Decoding compressed streams...\n";
        break;
    }

    return 0;
}