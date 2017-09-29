//LinkedList.h
#ifndef LinkedList_H
#define LinkedList_H
#include <iostream>
#include "ItemType.h"
//Linked List Class
class LinkedList{
  //Public Members and Functions
  public:
    //NodeType Struct
    struct NodeType{
        ItemType info;
        NodeType *next;    
      };  
    LinkedList();
    ~LinkedList();
    int lengthIs() const;
    void retrieveItem(ItemType &item, bool &found);
    void insertItem(ItemType &item);
    void deleteItem(ItemType &item);
    void resetList();
    void getNextItem(ItemType &item);
    void makeEmpty();
    void print();
  //Private Members and Functions  
  private:
    int length;
    NodeType *head;
    NodeType *current;
    NodeType *findNode(ItemType &item);
    void getNextNode();
};
#endif





