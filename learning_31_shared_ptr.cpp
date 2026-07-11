#include <iostream>
#include <memory>
int main(){
    std::shared_ptr<int> ptr1 = std::make_shared<int>(99);
    std::cout<<"the refrenace counter is: "<<ptr1.use_count()<<"\n";
    {
    std::shared_ptr<int> ptr2 = ptr1;// copying is valid and serves its purpose
    
    std::cout<<"the refrenace counter is: "<<ptr1.use_count()<<"\n";
    std::cout<<"is ptr1 owned by no one?: "<<ptr1.unique()<<"\n";
    }
    // after getting ptr2 out of scope, referance count drops by 1
    std::cout<<"the refrenace counter is: "<<ptr1.use_count()<<"\n";
    std::cout<<"is ptr1 owned by no one?: "<<ptr1.unique()<<"\n";// .unique() returns true if ref counter is 1(no other pointer to point at this heap)
    
    std::shared_ptr<int> p1 = std::make_shared<int>(500);
    p1.reset();// resets the p1 to null, ref count to 0, therby deleteing heap(only if p1 only owns it!)
    std::shared_ptr<int> p2 = std::make_shared<int>(500);
    std::shared_ptr<int> p3 = p2;
    p2.reset(); // olny drops ref count by 1, nulls p2, p3 is now the new heap owner

    std::shared_ptr<int> a = std::make_shared<int>(500);
    std::shared_ptr<int> b = a;
    a= std::move(b);
    b= nullptr;
    std::shared_ptr<int> c = std::make_unique<int>(500);// unique_ptr is converted to shared ptr, this is allowed in c++ but if you try to 
                                                        // convert shard ptr to unique, it gets error, it is a one way transfer
    std::shared_ptr<int> d = c;

    
    
    return 0;
}