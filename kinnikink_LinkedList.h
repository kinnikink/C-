#ifndef KINNIKINK_LINKEDLIST_H_INCLUDED
#define KINNIKINK_LINKEDLIST_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <windows.h>

using namespace std;

class kinnikink_LinkedList
{
    public:
        kinnikink_LinkedList();
       ~kinnikink_LinkedList();
           typedef struct node{
                int num_from_file;
                node* next;
           }*nodePtr;


       nodePtr head; // beginning of linked list
       nodePtr curr;
       nodePtr temp;

       void add(int value);
       void printlist();
};

#endif // KINNIKINK_LINKEDLIST_H_INCLUDED
