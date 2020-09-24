// Implementation file for the LinkedList class
// Written By: A. Student
// Changed By: Walter Tang
// IDE: Xcode

#include <iostream>
#include "LinkedList.h"
#include <iomanip>

using namespace std;

//**************************************************
// Constructor
// This function allocates and initializes a sentinel node
//      A sentinel (or dummy) node is an extra node added before the first data record.
//      This convention simplifies and accelerates some list-manipulation algorithms,
//      by making sure that all links can be safely dereferenced and that every list
//      (even one that contains no data elements) always has a "first" node.
//**************************************************
LinkedList::LinkedList()
{
    head = new Node; // head points to the sentinel node
    head->next = NULL;
    length = 0;
}

//**************************************************
// The insertNode function inserts a new node in a
// sorted linked list
//**************************************************
void LinkedList::insertNode(Patient dataIn)
{
    Node *newNode;
    Node *pCur;
    Node *pPre;

    newNode = new Node;
    newNode->data = dataIn;

    pPre = head;
    pCur = head->next;

    while(pCur != NULL && pCur->data.getName() < dataIn.getName()) {
        pPre = pCur;
        pCur = pCur->next;
    }

    pPre->next = newNode;
    newNode->next = pCur;
    length++;
}


//**************************************************
// The deleteNode function searches for a node
// in a sorted linked list; if found, the node is
// deleted from the list and from memory.
//**************************************************
bool LinkedList::deleteNode(string target)
{
    Node *pCur;       // To traverse the list
    Node *pPre;        // To point to the previous node
    bool deleted = false;

    pPre = head;
    pCur = head->next;

    while(pCur != NULL && pCur->data.getName() < target) {
        pPre = pCur;
        pCur = pCur->next;
    }
    if(pCur != NULL && pCur->data.getName() == target) {
        pPre->next = pCur->next;
        delete pCur;
        deleted = true;
        length--;
    }
    return deleted;

}


//**************************************************
// displayList shows the value
// stored in each node of the linked list
// pointed to by head, except the sentinel node
//**************************************************
void LinkedList::displayList() const
{
    Node *pCur;
    pCur = head->next;
    while(pCur) {
      /*  cout << setfill(' ') << setw(9) << "Name: " << pCur->data.getName() << endl;
        cout << setw(10) << "Age: " << pCur->data.getAge() << endl;
        cout << setw(7) << "Height: " << pCur->data.getHeight() << endl;
        cout << setw(7) << "Weight: " << pCur->data.getWeight() << endl;
        cout << "Weight Status: " << pCur->data.weightStatus() << endl;
        */
        setfill(' ');
        cout << pCur->data.getName() << setw(24 - pCur->data.getName().length()) << right;

        cout << pCur->data.getAge() << " years  ";
        cout << pCur->data.getHeight() << ".00 inches  ";
        cout << pCur->data.getWeight() << " pounds ";
        cout << pCur->data.weightStatus() << endl;
        pCur = pCur->next;
    }
}
//**************************************************
// displayList shows the value
// stored in each node of the linked list with the same weight status
// as the argument pointed to by head, except the sentinel node
//**************************************************
void LinkedList::displayList(string status) const
{
    int count = 0;
    Node *pCur;
    pCur = head->next;
    while(pCur) {
        if(pCur->data.weightStatus() == status) {
          /*  cout << "         Name: " << pCur->data.getName() << endl;
            cout << "          Age: "<< pCur->data.getAge() << endl;
            cout << "       Height: " << pCur->data.getHeight() << endl;
            cout << "       Weight: " << pCur->data.getWeight() << endl;
            cout << "Weight Status: " << pCur->data.weightStatus() << endl;
            */
            setfill(' ');
            cout << pCur->data.getName() << setw(24 - pCur->data.getName().length()) << right;
            cout << pCur->data.getAge() << " years  ";
            cout << pCur->data.getHeight() << ".00 inches  ";
            cout << pCur->data.getWeight() << " pounds ";
            cout << pCur->data.weightStatus() << endl;
            count++;
        }
        pCur = pCur->next;
    }
    if(count == 0) {
        cout << "None";
    }
}

//**************************************************
// The searchList function looks for a target 
// in the sorted linked list: if found, returns true
// and copies the data in that node to the output parameter
//**************************************************
bool LinkedList::searchList(string target, Patient &p) const
{
   bool found = false;
   Node *pCur;
   pCur = head->next;
   while(pCur != NULL && pCur->data.getName() < target) {
       pCur = pCur->next;
   }
   if(pCur != NULL && pCur->data.getName() == target) {
       found = true;
       p = pCur->data;
   }
    return found;
}

//**************************************************
// Destructor
// This function deletes every node in the list.
//**************************************************
LinkedList::~LinkedList()
{
    Node *pCur;     // To traverse the list
    Node *pNext;    // To hold the address of the next node
    
    // Position nodePtr: skip the head of the list
    pCur = head->next;
    // While pCur is not at the end of the list...
    while(pCur != NULL)
    {
        // Save a pointer to the next node.
        pNext = pCur->next;
        
        // Delete the current node.
        delete pCur;
        
         // Position pCur at the next node.
        pCur = pNext;
    }
    
    delete head; // delete the sentinel node
}



