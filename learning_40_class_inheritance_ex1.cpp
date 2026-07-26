// Create a base class named InventoryItem.Give it a 
// protected variable: int itemID.Give it a public
// variable: std::string itemName.Create a child class 
// named Weapon that explicitly inherits public from
// InventoryItem.Give Weapon a custom public property:
// int damageValue.Write a proper constructor for Weapon
// utilizing our delivery truck initializer list 
// mechanic to pass the basic properties up to 
// InventoryItem.Write an inspect() method inside
// Weapon that prints out all three attributes 
// cleanly.
#include <iostream>
#include <string>
class InventoryItem{
    protected:
    int itemID;
    public:
    std::string itemName;
    InventoryItem(const std::string& n, int id ):itemName(n), itemID(id){}

};
class Weapon:public InventoryItem{
    public:
    int damageValue;
    Weapon(const std::string& weaponName, int weaponid, int damageweapon):InventoryItem(weaponName, weaponid), damageValue(damageweapon){}
    void inspect(){
        std::cout<<"Item_type:Weapon\nItem_id "<<itemID<<" \nItem_name: "<<itemName<<" \nSpecial flags: damageValue: "<<damageValue<<"\n";
    }

};
int main(){
    Weapon trident("Trident", 12, 444);
    trident.inspect();

    return 0;
}
