// Justin Drouin
// CPSC 131
// Professor Allen Holliday
// 02/14/2019

#pragma once
#include <vector>
#include <string>
using std::string;
using std::vector;
// This is already done for you...
class Item {
public:
    string name;
    int sellIn;
    int quality;
    Item(string, int, int);
  //  Item();
};

Item::Item(string new_name, int new_sellIn, int new_quality)
: name(new_name), sellIn(new_sellIn), quality(new_quality) {
}


// This class is incomplete...
class GildedRose {
private:
vector<Item> inventory;
public:

    GildedRose();
    ~GildedRose();

    size_t size() const;
    Item& get(size_t);
    void add(const Item&);

    Item& operator[](size_t);

};
GildedRose::GildedRose(){
//  Item val = Item("", 0, 0); // not necessary
}
GildedRose::~GildedRose(){}
void GildedRose::add(const Item& val){
inventory.push_back(val);
}
//Item::Item():name(""), sellIn(0), quality(0){} // not necessary
size_t GildedRose::size() const{
  int counter = inventory.size();
  return counter;
}
Item& GildedRose::operator[](size_t num){
  return inventory[num];
}
Item& GildedRose::get(size_t num){
  return inventory.at(num);
}
