//LinkedList.h
#ifndef LinkedList_H
#define LinkedList_H
#include <iostream>
#include "ItemType.h"
//Linked List Class
class DoublyLinkedList{
  //Public Members and Functions
  public:
    //NodeType Struct
    struct NodeType{
        ItemType info;
        NodeType *next;
        NodeType *back;
      };  
    DoublyLinkedList();
    ~DoublyLinkedList();
    int lengthIs() const;
    void retrieveItem(ItemType &item, bool &found);
    void insertItem(ItemType &item);
    void deleteItem(ItemType &item);
    void resetList();
    void getNextItem(ItemType &item);
    void getPrevItem(ItemType &item);
    void makeEmpty();
    void print();
  //Private Members and Functions  
  private:
    int length;
    NodeType *head;
    NodeType *current;
    NodeType *prev;
    NodeType *findNode(ItemType &item);
    void getNextNode();
    void getPrevNode();
};
#endif





