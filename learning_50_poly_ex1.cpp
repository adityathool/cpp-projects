#include <iostream>
#include <memory>
#include <vector>
class AudioEffect{
    public:
    virtual void process(float* buffer, int samplecount){
        std::cout<<"bypassed effect\n";
    }
};
class DistortionEffect:public AudioEffect{
    public:
    void process(float* buffer, int samplecount) override{
        std::cout<<"applying soft clipping distortion\n";
    }
};
class EchoEffect:public AudioEffect{
    public:
    void process(float* buffer, int samplecount) override{
        std::cout<<"applying 500ms dealyed echo";
    }
};
int main(){
    std::vector<std::unique_ptr<AudioEffect>> sptrs;
    sptrs.push_back(std::make_unique<DistortionEffect>());
    sptrs.push_back(std::make_unique<EchoEffect>());
    float* buffer;
    for(auto& audiomods : sptrs){
        audiomods->process(buffer, 10);
    }


    return 0;
}