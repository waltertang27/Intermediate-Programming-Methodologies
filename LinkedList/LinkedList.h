// Specification file for the LinkedList class
// Written By: A. Student
// Changed By: Walter Tang
// IDE: Xcode

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Patient.h"

class LinkedList
{
private:
    struct Node
    {
        Patient data;
        Node *next;
    };

    Node *head;
    int length;

public:
    LinkedList();   // constructor
    ~LinkedList();  // destructor

    // Linked list operations
    int getLength() const {return length;}
    void insertNode(Patient);
    bool deleteNode(string);
    void displayList() const;
    void displayList(string) const;
    bool searchList(string target, Patient &p) const;
};

#endif
