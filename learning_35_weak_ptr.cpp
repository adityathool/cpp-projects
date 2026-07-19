#include <iostream>
#include <memory>
#include <string> 
int main(){
    std::cout<<"waek_ptr\n";
    std::shared_ptr<std::string> shared = std::make_shared<std::string>("hello world");
    std::cout<<shared.use_count()<<"\n";

    //creating a temporary access to shared memory via weak_ptr
    std::weak_ptr<std::string> weak = shared;// a weak pointer pointing to hello world heap
    // since weak cant read data, we temporarily convert it to shared_ptr via .lock() method
    // .lock() method returns a shared ptr if data exists, otherwise, returns a nullptr
    std::cout << "Strong Count: " << shared.use_count() << "\n"; // Prints 1 (Weak didn't increment it!)
    if (std::shared_ptr<std::string> tempshared = weak.lock()){
        std::cout<<"Data is alive: "<< *tempshared<<"\n";
    }

    shared.reset();
    if(weak.expired()){ // returns true if orignal data is deleted
        std::cout<<"data deleted\n";
    }
    if (std::shared_ptr<std::string> tempShared2 = weak.lock()) {
        // This block will be skipped because .lock() returns nullptr when expired!
    } else {
        std::cout << "Lock failed: Resource no longer exists.\n";
    }

    return 0;

}