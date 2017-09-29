//main.cpp
#include <fstream>
#include <iostream>
#include "ItemType.h"
#include "LinkedList.h"
//main function
int main(int argc, char *argv[]){
  bool run = true;
  char cinput;
  LinkedList list;
  ItemType item;
  int input;
  //Open File
  std::fstream fs;
  fs.open(argv[1],std::fstream::in);
  //Read Input From File
  if(fs.is_open())
  {
    fs>>input;
    while(!fs.eof())
    {
      item.initialize(input);
      list.insertItem(item);
      fs>>input;
    } 
  }
  else
  {
    std::cout<<"File could not be opened."<<"Please Try Again"<<std::endl;
    return 0;
  }
  //User Command Input
  std::cout<<"Commands - insert (i), delete (d), make empty (e), length (l), print (p),get next item (g), reset list (r), quit (q)"<<std::endl;
  while(run)
  { 
    std::cout<<"Enter A Command: ";
    std::cin>>cinput;
    switch(cinput)
    {
      //Insert
      case 'i':
        std::cout<<"Number To Insert: ";
        std::cin>>input;
        item.initialize(input);
        list.insertItem(item);
        list.print();
        break;
      //Delete  
      case 'd':
        std::cout<<"Number To Delete: ";
        std::cin>>input;
        item.initialize(input);
        list.deleteItem(item);
        list.print();
        break;
      //Reset
      case 'r':
        list.resetList();
        std::cout<<"List Has Been Reset."<<std::endl;
        break;
      //Quit 
      case 'q':
        std::cout<<"Quiting...."<<std::endl;
        run = false;
        //list.makeEmpty();
        break;
      //Print  
      case 'p':
        list.print();
        break;
      //Length  
      case 'l':
        std::cout<<list.lengthIs()<<std::endl;
        break;  
      case 'e':
        list.makeEmpty();
        //list.print();
        break;
      case 'g':
        list.getNextItem(item);
        break;
      default:
        std::cout<<"User Input Not Recognized. Try Again."<<std::endl;   
    }
  }
  return 0;
}