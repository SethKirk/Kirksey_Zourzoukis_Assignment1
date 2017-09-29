//ItemType.cpp
#include <cstdlib>
#include "ItemType.h"
//Constructor
ItemType::ItemType(){
  value  = -1;
}
//Sets the value variable to the number parameter
void ItemType::initialize(int number){
  value = number;
}
//Prints out the value variable
void ItemType::print(){
  if(value != -1)
  {
    std::cout<<value<<" ";
  }
}
//Returns the value variable
int ItemType::getValue() const{
  if(value != -1)
  {
    return value;
  }
  return value;
}
//Comappres two item's value varaibles
RelationType ItemType::compareTo(ItemType &item){
  ItemType i2 = item;
  RelationType relation;
  if(value==i2.value)
  {
    relation = EQUAL;
  }
  else if(value<i2.value)
  {
    relation = LESS;
  }
  else if(value>i2.value)
  {
    relation = GREATER;
  }   
  return relation;
}