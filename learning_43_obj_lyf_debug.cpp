#include <iostream>

class ResourceTracker {
private:
    int activeSockets;   // Declared 1st
    int managedThreads;  // Declared 2nd
    int totalResources;  // Declared 3rd
    // change thw oreder or declarations by our needs to output desired answer 

public:
    // Look closely at the order here versus the declarations above
    ResourceTracker(int baseline) 
        : totalResources(baseline * 10),
          managedThreads(totalResources / 2),
          activeSockets(managedThreads + 5) 
    {
        std::cout << "Initialization completed successfully!\n";
    }

    void printStatus() const {
        std::cout << "Sockets: " << activeSockets << "\n";
        std::cout << "Threads: " << managedThreads << "\n";
        std::cout << "Total: " << totalResources << "\n";
    }
};

int main() {
    ResourceTracker tracker(4);
    tracker.printStatus();
    // it prints garbage because compiler initialises the variables in idfferent order, 
    // it initialises the variables in the order there created in class defination, 
    // activesockets initiales first, with garbage in managedthreads, causing garbage prints
    return 0;
}
