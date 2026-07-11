#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> p1 = std::make_shared<int>(7);
    std::shared_ptr<int> p2 = p1;

    {
        std::shared_ptr<int> p3 = std::move(p1);
        std::cout << "CP 1 Count: " << p3.use_count() << "\n";
    } 

    std::cout << "CP 2 Count: " << p2.use_count() << "\n";

    p2.reset();
    std::cout << "CP 3 Count: " << p2.use_count() << "\n";

    return 0;
}
