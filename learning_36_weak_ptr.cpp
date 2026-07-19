#include <iostream>
#include <memory>
#include <string>
class Node{
    public:
    std::string name;
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;
    
    Node(const std::string& id):name(id){}
    ~Node(){std::cout<<name<<" has been destroyed\n";}

};


int main(){
    auto head = std::make_shared<Node>("Head");// head points to heap allocated insttance Node "head"
    auto tail = std::make_shared<Node>("Tail");// tail points to heap allocated instance Node "tail"
    head->next = tail;//inside Node "head" thers a pointer that points to heap instance tail
    tail->prev = head;// inside Node "tail" thers a weak pointer that observes heap allocated Node"head"
    //Node "head" is pointed by stack var head, and pointer inside tail(prev), note that prev is weak
    //Node "tail" is pointed by stack var tail, and pointer inisde head(next), it is a shared ptr
    //Node"head" ref count is 1 since stack var head points it, but var inside tail(prev) is weak, in addition its weak ref count is 1
    //Node"tail" ref count is 2 since both stack var tail and var inside head node are shard_ptr, their ref count is now 2
    //Node"tail"-->strong count=2
    //Node"head"-->strong count =1, weak count =1
    
    //when stack var head goes out of scope, Node "head" is deleted instantly since its strong ocunt is 0
    //when Node "head" deletes, its pointer to tail also delets, so tail's count drops to 1
    // when stack var tail goes out of scope, Node "tail" deletes, no leak, safe cleans

    //clash: if prev was shared
    //Node "head" has 2 owenrs, stack var head and this prev, when head goes out of scope, its ref count drops to 1, 
    //Node "head" is not deleted, so Node"tail" also is kept alive
    // both instances are in heap, but their access is gone, leaking the memory
    return 0;
}