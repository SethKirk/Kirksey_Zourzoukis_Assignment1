//LinkedList.cpp
#include <cstdlib>
#include <iostream>
#include "LinkedList.h"
#include "ItemType.h"
//Constructor
LinkedList::LinkedList(){
  length = 0;
  head = NULL;
}
//Destructor
LinkedList::~LinkedList(){
  makeEmpty();
  delete head;
  delete current;
}
//Returns the current length of the list
int LinkedList::lengthIs() const{
  return length;
}
//Sets the current pointer to null
void LinkedList::resetList(){
  current = NULL;
}
//Inserts an item into it's correct, ordered place
//*Inspired by the insertItem() function from the slide*
void LinkedList::insertItem(ItemType &item){
  NodeType *newNode = new NodeType();
  newNode->info = item;
  NodeType *prev;
  prev = NULL;
  current = head;
  while(current!=NULL)
  {
    if(current->info.compareTo(newNode->info)==RelationType::LESS)
    {
      prev = current;
      getNextNode();
    }
    else
    {
      goto insert;
    }
  }
  insert:
  if(prev==NULL)
  {
    newNode->next = head;
    head = newNode;
  }
  else
  {
    newNode->next = current;
    prev->next = newNode;
  }
  length++;
}
//Moves current to the next node
void LinkedList::getNextNode(){
  if(current!=NULL)
  {
    current = current->next;
  }
  else
  {
    current = NULL;
  }
}
//Prints out the entire, current list
void LinkedList::print(){
  if(head==NULL)
  {
    std::cout<<"List Is Empty";
  }
  else
  {
    current = head;
    while(current!=NULL)
    {
      current->info.print();
      getNextNode();
    }
  }
  std::cout<<""<<std::endl;
}
//Returns the node that contains the given item
LinkedList::NodeType *LinkedList::findNode(ItemType &item){
  current = head;
  while(current!=NULL && current->info.compareTo(item)!=RelationType::EQUAL)
  {
    getNextNode();
  }
  if(current!=NULL)
  {
    return current;
  } 
  else
  {
    return nullptr;
  }
}
//Deletes the node associated with the given item
void LinkedList::deleteItem(ItemType &item){
  NodeType *find;
  find = findNode(item);
  current = head;
  if(head == find)
  {
    head = current->next;
  } 
  else
  {
    while(current->next != NULL && current->next != find)
    {
      getNextNode(); 
    }
    if(current->next == NULL)
    {
      std::cout<<"The Item You Wanted To Delete Does Not Exist"<<std::endl;
    }
    else
    {
      current->next = current->next->next;
    }
  }
  delete find;
  length--;
}
//Moves the pointer to the next node and prints out said node
void LinkedList::getNextItem(ItemType &item){
  if(length==0)
  {
    std::cout<<"Next Item: List Is Empty"<<std::endl;
  }
  else if(current!=NULL)
  {
    item = current->info;
    std::cout<<"Next Item: "<<item.getValue()<<std::endl;
    getNextNode();
  }
  else
  {
    item = head->info;
    current = head;
    std::cout<<"Next Item: "<<item.getValue()<<std::endl;
    getNextNode();
  }
  
}
//Empties the list
void LinkedList::makeEmpty(){
  if(length>0)
  {
    NodeType *temp;
    while(head!=NULL)
    {
      temp = head;
      head = head->next;
      delete temp;
    }
    length--;
    std::cout<<"List Is Empty"<<std::endl;
  }
  else
  {
    std::cout<<"List Is Already Empty"<<std::endl;
  }
}
//Retreives an item from the link list
void LinkedList::retrieveItem(ItemType &item, bool &found){
  NodeType *find;
  find = findNode(item);
  if(find!=NULL)
  {
    found = true;
    item = find->info;
  }
  else
  {
    found = false;
  }
}