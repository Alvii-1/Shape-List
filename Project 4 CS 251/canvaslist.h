// 
// Zohaib Alvi, VSCode on MacOS Ventura 
// Professor Adam Koehler
// Spring 2023 Semester
// CS 251 Project 4: CanvasList
//
/* This project involves multiple .h files with testing done using catch testing framework in a separate tests.cpp file. This file contains
the CanvasList and ShapeNode classes used for constructing the Canvas list itself. It has multiple function for adding and removing
elements to the list, copying elements, clearing elements, accessing certain indexes of the list and outputting information such
as the addresses of each node in the list. There is also a default constructor, destructor, copy constructor, and overloaded = 
operator. The list is designed to hold different shape objects in each node in a linked list format, and these shape objects and their
classes are defined in the shape.h file. */
//

#pragma once

#include "shape.h"
#include <iostream>

using namespace std;

class ShapeNode
{
    public:
        Shape *value; // like int Data from other lists i've seen
        ShapeNode *next; // like pNext
};

class CanvasList
{
    private:
        int listSize; // size of the list, each node = 1
        ShapeNode *listFront; // like pHead

    public:
        CanvasList(); 
        CanvasList(const CanvasList &);
        CanvasList operator=(const CanvasList &);
        
        virtual ~CanvasList();
        void clear();           
        
        void insertAfter(int, Shape *); 
        void push_front(Shape *);     
        void push_back(Shape *);       
        
        void removeAt(int); 
        Shape* pop_front(); 
        Shape* pop_back();  

        ShapeNode* front() const;
        bool isempty() const;
        int size() const; 

        int find(int x, int y) const;
        Shape* shapeAt(int) const; 
        
        void draw() const;
        void printAddresses() const;
};

/* CanvasList default constructor, takes no parameters and sets the listSize to zero and
the listFront pointer to NULL, since there are no elements in the list yet. */
CanvasList::CanvasList() {
    listSize = 0;
    listFront = nullptr;
}

/* CanvasList copy constructor, takes another CanvasList object as a parameter. It first sets the listSize  to 0 and listFront 
to NULL, and then uses a temporary ShapeNode pointer to iterate through the contents of the list being copied from. A new node 
is created for each non- NULL node in the copied list, and it is either set as the listFront for the first copied element, or 
is connected as a new node. The listSize of the copy is set equal to the listSize of the copied list. */
CanvasList::CanvasList(const CanvasList &otherList) {
    listSize = 0;
    listFront = NULL;

    ShapeNode *temp = otherList.listFront; // temporary node to iterate through the list being copied from
    while (temp != NULL) {
        ShapeNode* appendNode = new ShapeNode; // new node made in the copy list with value and next pointer set below
        appendNode->value = temp->value->copy();
        appendNode->next = NULL;

        if (listFront == NULL) {
            listFront = appendNode; // if the list is initially empty, the listFront (head) of the list is set to be the node
        }
        else { // if the list is not initially empty, need to find the end and append
            ShapeNode* current = listFront; // node to cycle through each of the nodes in the list to find the final one
            while (current->next != NULL) {
                current = current->next; // finding the last node in the list 
            }
            current->next = appendNode;
        }
        temp = temp->next; // continuing iterating through the list being copied from
    }

    delete temp;
    listSize = otherList.listSize;
}

/* CanvasList operator=() function, it creates a deep copy of a source list into a new CanvasList object. It first creates a node pointer
otherCurrent used to iterate through the source list. It also creates a previousNode pointer. It then clears the destination list to ensure
it is overwritten to make a deep copy, then iterates through the source list, creating a new node in the destination list for each non NULL
node in the source, either adding it as the listFront if the list is empty or appending if its not. The previousNode is used to track whether
the list is empty or not, and if its not, the previousNode's next pointer is set to the new node added. The size is incremented for each node added. */
CanvasList CanvasList::operator=(const CanvasList &otherList) {
    ShapeNode* otherCurrent = otherList.listFront; // iterating pointer
    ShapeNode* previousNode = NULL; // used to track the state of the destination list (NULL if empty, non null if non empty list)
    
    this->clear();

    /* below, iterating through the source list and creating a new node for each non NULL node in the source. the value and next pointer
    are set, and the node is inserted in the destination list as either the head (empty list) or the next node (non empty list) using 
    previousNode to keep track of whether the list is empty or not. */
    while (otherCurrent != NULL) {
        ShapeNode* nodeToAdd = new ShapeNode;
        nodeToAdd->value = otherCurrent->value->copy();
        nodeToAdd->next = NULL;

        if (previousNode == NULL) {
            listFront = nodeToAdd;
        }
        else {
            previousNode->next = nodeToAdd;
        }
        previousNode = nodeToAdd;

        otherCurrent = otherCurrent->next; // moving the while loop along
        listSize += 1; // incrementing the list size for each node added
    }

    delete otherCurrent;
    return *this;
}

/* the CanvasList destructor, it calls the clear function to remove all nodes in a list. */
CanvasList::~CanvasList() {
   this->clear();
}

/* CanvasList clear() function, it first checks to ensure the list isnt empty, if it is it simply does nothing. Otherwise, it iterates
through the list being cleared, setting the node to be deleted as delNode, incrementing current so as to keep the loop moving, and
then finally deletes the node to be deleted as the last action of the while loop. */
void CanvasList::clear() {
    if (listFront == NULL) {
        return; // ensuring the list isnt empty already
    }

    ShapeNode* current = listFront; // current pointer iterates through the list
    while (current != NULL) {
        ShapeNode* delNode = current; // pointer to the node to be deleted
        current = current->next; // moving the current along so as to not delete it first, it should increment first and delNode deleted as done here 
        if (delNode->value != NULL) {
            delete delNode->value;
            delete delNode;
        }
    }
    delete current;

    listFront = NULL; // resetting the listFront pointer to NULL and the size to 0
    listSize = 0;
}

/* CanvasList insertAfter() function, takes the index to insert after and a shape object to insert as parameters. It first ensures the
index is valid (between and inclusive of 0 and size-1). It then creates a current pointer to iterate through the list using a for loop, when
the loop is done, we are at the index we want to insert after. A new node is then made, the shape object is set as its value, and its next
pointer is set to that of the node it is inserted after. The listSize is also incremented. */
void CanvasList::insertAfter(int index, Shape *shapeToInsert) {
    if (index >= listSize || index < 0) {
        return;
    }
    ShapeNode* current = listFront;

    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    ShapeNode* newNode = new ShapeNode;
    newNode->value = shapeToInsert;
    newNode->next = current->next;
    current->next = newNode;

    listSize += 1;
}

/* CanvasList push_front() function, takes a shape object as a parameter. It creates a new node with the value of the shape object 
parameter, sets this new nodes next pointer to the old listFront head, then sets that node as the new listFront head. listSize increments. */
void CanvasList::push_front(Shape* shapeToInsert) {
    ShapeNode* newNode = new ShapeNode;
    newNode->value = shapeToInsert;
    newNode->next = listFront;
    listFront = newNode;
    
    listSize += 1;
}

/* CanvasList push_front function, takes the shape object to insert as a parameter. it creates a new node with the value of the shape object
parameter to be inserted, a next pointer of NULL, and increments the size of the list. if the listFront is NULL, the list is empty so the node
is set as the listFront head. Otherwise, the function uses a while lopp to iterate to the end of the list and then insert the node at the very
end. */
void CanvasList::push_back(Shape* shapeToInsert) {
    ShapeNode* newNode = new ShapeNode;
    newNode->value = shapeToInsert;
    newNode->next = NULL;
    listSize += 1;

    if (listFront == NULL) {
        listFront = newNode; // if the listFront is NULL, the list is empty so this new node must be set as the head.
        return;
    }

    ShapeNode* current = listFront;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

/* CanvasList removeAt() function takes the index integer value to remove as a parameter. It first checks the validity of the index. Then, it
checks to see if the index is 0, if it is, the listFront node is removed, listFront is set as the second node, and the nodeToRemove is the current
old listFront. If the index is not zero, a while loop iterates until the index is found  and sets that index as the node to remove. After that,
the current nodes next value is set as the nodeToRemove's next value, to ensure the list is reorganized to its final state before the node
is removed. Then, the node is removed and the listSize is decremented. */
void CanvasList::removeAt(int index) {
    if (index >= listSize || index < 0) {
        return; // checking index validity
    }
    int i = 0;
    ShapeNode* current = listFront; // iterating pointer, begins at listFront
    ShapeNode* nodeToRemove = NULL; // points to the node to remove

    if (index == i) {
        listFront = listFront->next; // if the index is 0, we need to remove listFront, which is also set as the current pointer
        nodeToRemove = current;
    }
    else {
       
        while (i != index - 1) { // this while loop finds the index which must be removed
            current = current->next;
            i += 1;
        }
        nodeToRemove = current->next;
        
    }
    current->next = nodeToRemove->next;

    if (nodeToRemove != NULL) {
        delete nodeToRemove->value;
        delete nodeToRemove;

        listSize -= 1;
    }
}

/* CanvasList pop_front() function, it first checks if the list is empty, if it is, theres nothing to remove so we return NULL. Otherwise, 
we create a current pointer pointing to the listfront, move the listFront pointer to point to the second node in the list, and set the removedShape
pointer to point to the current's shape value. At this point, the listFront is now the second node, current is the old listFront, and we've isolated
the shape to remove, so the listSize is decremented and we return the shape of the node which was removed. */
Shape* CanvasList::pop_front() {
    if (listFront == NULL) {
        return NULL;
    }
    ShapeNode* current = listFront;
 
    listFront = listFront->next; // updating listFront to point to second node
    Shape* removedShape = current->value;
    
    delete current;

    listSize -= 1;
    return removedShape;
}

/* CanvasList pop_back() function, it first ensures the list is populated, if its not, theres nothing to remove so return NULL. Otherwise, 
we create a pointer current pointing to the listFront, and create a shape pointer removedShape which will point to the shape needing to be returned. 
We then check if the second node is NULL, if it is, we only need to delete the first node. Otherwise, we iterate through the list until the node
ahead of the one we're looking at is NULL, meaning the NEXT node is the one to remove. We can set a shapeNode pointer to the node needing to
be removed, make the current node's Next value NULL, and assign the shape value to return from the function*/
Shape* CanvasList::pop_back() {
    if (listFront == NULL) {
        return NULL;
    }
    ShapeNode* current = listFront;
    Shape* removedShape;

    if (current->next == NULL) { // if there is only one node, its all we need to remove
        removedShape = current->value;
        listFront = NULL;
        
        delete current;

        listSize = 0;
        return removedShape;
    }

    while (current->next->next != NULL) { // finding the node when the NEXT node is the final one, the one to be removed
        current = current->next;
    }

    ShapeNode* nodeToRemove = current->next; // the node to remove is the NEXT node
    current->next = NULL; // setting our current node's next value to NULL since we're removing the next ndoe
    removedShape = nodeToRemove->value; // isolating the shape value to return
 
    delete nodeToRemove;

    listSize -= 1; // decrementing list size
    return removedShape;
}

/* CanvasList front() function, it simply returns listFront if the list is non empty. if the list is empty, return NULL */
ShapeNode* CanvasList::front() const {
    if (listFront == NULL) {
        return NULL;
    }
    return listFront;
}

/* CanvasList isempty() function. If the listFront is NULL and the size is 0, the list is empty, so return true. Otherwise return false */
bool CanvasList::isempty() const {
    if (listFront == NULL && listSize == 0) {
        return true;
    }
    return false;
}

/* CanvasList size() function, simply returns the listSize integer value private data member */
int CanvasList::size() const {
    return listSize;
}

/* CanvasList find() function, takes the x and y coordinates as parameters. It iterates through the list using a current pointer, using a
for loop to iterate for the listSize. It then checks the x and y data members of each current node's shape value using the getX and getY
functions. it returns the index of the first match to both the x and y values. Otherwise, it continues iterating in the list. If it never
finds a match, it returns -1. */
int CanvasList::find(int x, int y) const {

    ShapeNode* current = listFront;
    for (int i = 0; i < listSize; i++) {
        if (current->value->getX() == x && current->value->getY() == y) {
            return i;
        }
        current = current->next;
    }

    return -1;
}

/* CanvasList shapeAt function, takes the index of the node's whose shape we want to find. it first checks to ensure the index is valid
and within the bounds of 0 to listSize - 1. Then, it uses a current pointer to iterate through the list until i matches the index parameter
using a while loop. Once the match is found, we return that index's shape value. */
Shape* CanvasList::shapeAt(int index) const {
    if (index >= listSize || index < 0) {
        return nullptr; // return null if the index is invalid or out of reach
    }
    ShapeNode* current = listFront;

    int i = 0;
    while (i != index) {
        current = current->next;
        i++;
    }

    return current->value;
}

/* CanvasList draw() function. It simply iterates through the list and calls the printShape() function for each node's shape value, which
will output the x and y coordinates of the shape object, plus the radius for Circle, width and height for Rectangle, and base and height
for Right Triangle shape values. */
void CanvasList::draw() const {
    ShapeNode* current = listFront;

    while (current != NULL) {
        current->value->printShape();
        current = current->next;
    }

    delete current; 
}

/* CanvasList printAddresses() function. It simply iterates through the list using a current pointer, then outputs a message with
the node address given by the variable current, and the shape address given by current->value. It separates these two messages with 
a tab character. It iterates through the list and does this for each element. */
void CanvasList::printAddresses() const {
    ShapeNode* current = listFront;

    while (current != NULL) {
        cout << "Node Address: " << current << "\t" << "Shape Address: " << (current->value) << endl;
        current = current->next;
    }

    delete current; 
}