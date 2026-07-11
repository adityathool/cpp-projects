#include <iostream>
#include <memory>

int main() {
    int* rawAddress = new int(888);

    // Initializing two separate shared pointers with the raw address
    std::shared_ptr<int> shared1(rawAddress);
    std::shared_ptr<int> shared2(rawAddress);
    // even if pointers are smart, the heap memory is raw, shared1 and shared2 are unknown that they point to same raw heap, 
    // thus us_count show 1 instead of 2
    //when shared1's ref count goes 0, it deletes the heap, 
    // when shared2's count goes 0, it again deletes deleted heap,causing double delete crash

    std::cout << "shared1 count: " << shared1.use_count() << "\n";
    std::cout << "shared2 count: " << shared2.use_count() << "\n";

    return 0;
}
