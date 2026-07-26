#include <iostream>
class LowLevelDevice {
    int m_deviceId; // 4 bytes
public:
    virtual void connect() { }
};

class MicroController : public LowLevelDevice {
    int m_gpioPins; // 4 bytes
public:
    void connect() override { }
};
int main(){
    std::cout<<sizeof(LowLevelDevice);
    

}
// the size of Microcontorller goes like this:
// it doesnt contain a vtable itself, it only containsa hidden vptr pointing to vtable
// in 64 bit system: pointers are 8 bytes for presision
// thus 8byte(vptr)+4byte(gpio)+4byte (mdeviceid)
//neither bases, childs nor instances contain a vtable, it lives in rodata(read only data) section of memory
// if we measure the size of base, it isnt as expected:12 bytes, its 16
// extra 4 bytes are padding garbage so the cpu can read continuose data stream and reduce load of reading twice
// the 64 wire data buses of cpu that connects to ram can transfer exactly 64 bits data(8 bytes)
//if an object with odd size like 12 has to travel, it would break out, andthe bytes of any integer or pointer can cut mid,
// thus cpu will do extra work to pull missing bytes again, strip and glu them to read one pointer
// by adding extra 4 bytes or makng data objects the exact multiples of 8, cpu pulls data deccretely without stripping(8 bytes>vptr, 8byte>4byte m_deviceid, 4 byte junk)
