//ItemType.h
#ifndef ITEMTYPE_H
#define ITEMTYPE_H
#include <iostream>
//enumeration
enum RelationType {GREATER, LESS, EQUAL};
//ItemType Class
class ItemType {
  //Public Members and Variables
  public:
    ItemType();
    RelationType compareTo(ItemType &item);
    void print();
    void initialize(int number);
    int getValue() const;
  //Private Members  
  private:
    int value;
};
#endif