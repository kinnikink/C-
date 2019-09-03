#include "kinnikink_LinkedList.h"

kinnikink_LinkedList::kinnikink_LinkedList()
{
 head = NULL;
}

kinnikink_LinkedList::~kinnikink_LinkedList()
{
 head = NULL;
}

void kinnikink_LinkedList::add(int value) { //the function for adding a value to the linked list
    nodePtr n = new node;
    n->num_from_file = value; //reads in the number from the file
    n->next = NULL;
    if (head != NULL) { //insertion sorting algorithm
        curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr -> next = n;
    }
    else {
        head = n;
    }
}

void kinnikink_LinkedList::printlist() {
    curr = head;
    while (curr != NULL) {
        cout << curr->num_from_file << endl;
        curr = curr->next;
    }
}
