/*
 *  CharLinkedList.cpp
 *  Name: Leo Kim
 *  Date: 2/3/2022
 *
 * Purpose: Implementation of the character linked list class. A 
 *           CharLinkedList is a linked list made up of char variables
 *           that can be altered and accessed by a variety of functions.  
 */

#include "CharLinkedList.h"
#include <iostream>

/*
 * name:      CharLinkedList default constructor
 * purpose:   initialize an empty CharLinkedList
 * arguments: none
 * returns:   none
 * effects:   numItems to 0 (also initializes front and back pointers)
 */
CharLinkedList::CharLinkedList() {
    // initialize all the private member variables
    numItems = 0;
    front = nullptr;
    back = nullptr;
}


/*
 * name:      CharLinkedList single character constructor
 * purpose:   initialize a CharLinkedList with a single character
 * arguments: a single character variable
 * returns:   none
 * effects:   numItems to 1 (also updates front and back pointers)
 */
CharLinkedList::CharLinkedList(char c) {
    // initialize all the private data members
    numItems = 0;
    front = nullptr;
    back = nullptr;
    
    // add the first char to the list
    pushAtBack(c);
}

/*
 * name:      CharLinkedList char array constructor
 * purpose:   initialize an CharLinkedList with an array of chars
 * arguments: a char array and an int var for its size
 * returns:   none
 * effects:   numItems to size (also updates front and back pointers)
 */
CharLinkedList::CharLinkedList(char arr[], int size) {
    // initialize the private data members
    numItems = 0;
    front = nullptr;
    back = nullptr;
    
    // Add each member of the given array to the linked list
    for (int i = 0; i < size; i++){
        pushAtBack(arr[i]);
    }
}

/*
 * name:      CharLinkedList copy constructor
 * purpose:   copy constructor for the CharLinkedList class
 * arguments: Address of another CharLinkedList
 * returns:   none
 * effects:   makes a deep copy of the given CharLinkedList
 */
CharLinkedList::CharLinkedList(const CharLinkedList &other) {
    // initialize the private data members
    numItems = 0;
    front = nullptr;
    back = nullptr;

    // add each member of the given CharLinkedList to the newly created 
    // linked list
    for (int i = 0; i < other.size(); i++) {
        pushAtBack(other.elementAt(i));
    }
}

/*
 * name:      CharLinkedList destructor
 * purpose:   free memory associated with the CharLinkedList
 * arguments: none
 * returns:   none
 * effects:   frees memory allocated by CharLinkedlist instances
 */
CharLinkedList::~CharLinkedList() {
    // Call the recursive destructor helper function
    destructorHelper(front);   
}

/*
 * name:      CharLinkedList assignment operator definition
 * purpose:   used to make a deepcopy when assigning CharLinkedLists to 
 *            eachother
 * arguments: address of the other CharLinkedList
 * returns:   none
 * effects:   makes a deep copy of the given CharLinkedList
 */
CharLinkedList &CharLinkedList::operator=(const CharLinkedList &other) {
    // Check to see if the assignment operator is assigning two equivalent
    // CharLinkedLists. If so return the CharLinkedList
    if (this == &other) {
        return *this;
    }

    // Clear the CharLinkedList being assigned and initialize the private data 
    // members
    clear();
    front = nullptr;
    back = nullptr;
    numItems = 0;
    
    // Add each member of the given CharLinkedList to the newly assigned 
    // linked list
    for (int i = 0; i < other.size(); i++) {
        pushAtBack(other.elementAt(i));
    }
    
    // Return the newly assigned linked list
    return *this;
}

/*
 * name:      isEmpty
 * purpose:   determines if the CharLinkedList is empty or not
 * arguments: none
 * returns:   true if CharLinkedList contains no elements, false otherwise
 * effects:   none
 */
bool CharLinkedList::isEmpty() const {
    return numItems == 0;
}

/*
 * name:      clear
 * purpose:   clears a CharLinkedList
 * arguments: none
 * returns:   none
 * effects:   reverts a CharLinkedList to an empty state
 */
void CharLinkedList::clear() {
    // clear existing heap memory with recursive destructor helper function
    destructorHelper(front);
    
    // reset private member variables
    numItems = 0;
    front = nullptr;
    back = nullptr;
}

/*
 * name:      size
 * purpose:   determine the number of items in the CharLinkedList
 * arguments: none
 * returns:   number of elements currently stored in the CharLinkedList
 * effects:   none
 */
int CharLinkedList::size() const {
    return numItems;
}

/*
 * name:      first
 * purpose:   determines the first element of the CharLinkedList
 * arguments: none
 * returns:   the first element of the CharLinkedList or an error if the list
 *            is empty
 * effects:   none
 */
char CharLinkedList::first() const {
    if (isEmpty()){
        // if the CharLinkedList is empty throw an error message
        throw std::runtime_error("cannot get first of empty LinkedList");
    } else {
        return front->info;
    }
}

/*
 * name:      last
 * purpose:   determines the last element of the CharLinkedList
 * arguments: none
 * returns:   the last element of the CharLinkedList or an error if the list
 *            is empty
 * effects:   none
 */
char CharLinkedList::last() const {
    if (isEmpty()){
        // if the CharLinkedList is empty throw an error message
        throw std::runtime_error("cannot get last of empty LinkedList");
    } else {
        return back->info;
    }
}

/*
 * name:      elementAt
 * purpose:   determines the element at a given index in the CharLinkedList
 * arguments: index of element
 * returns:   the corresponding element of the CharLinkedList or an error if 
 *            the index is out of range
 * effects:   none
 */
char CharLinkedList::elementAt(int index) const {
    if (index >= numItems or index < 0){
        // if the index is out of range of the CharLinkedList, throw an error 
        // message
        throw std::range_error( "index (" + std::to_string(index) + 
        ") not in range [0.." + std::to_string(numItems) + ")" );
    } else {
        // Call recursive helper function to find element at index
        return elementAtHelper(front, index);
    }
}


/*
 * name:      pushAtBack
 * purpose:   push the provided integer into the back of the CharLinkedList
 * arguments: a char to add to the back of the list
 * returns:   none
 * effects:   increases num elements of CharLinkedList by 1,
 *            adds element to list
 */
void CharLinkedList::pushAtBack(char c) {
    // If list is empty, create new node and point front and back pointers
    // at it
    if (isEmpty()) {
        back = new Node;
        *back = newNode(c, nullptr, nullptr);
        front = back;
    } 
    // If list is not empty, create new node and point back pointer and
    // preceeding node at it
    else {
        back->next = new Node;
        *(back->next) = newNode(c, nullptr, back);
        back = back->next;
    }
    // Update the number of items
    numItems++;
}

/*
 * name:      pushAtFront
 * purpose:   push the provided integer into the front of the CharLinkedList
 * arguments: a char to add to the front of the list
 * returns:   none
 * effects:   increases num elements of CharLinkedList by 1,
 *            adds element to list
 */
void CharLinkedList::pushAtFront(char c) {
    // If list is empty, create new node and point front and back pointers
    // at it
    if (isEmpty()) {
        back = new Node;
        *back = newNode(c, nullptr, nullptr);
        front = back;
    } 
    // If list is not empty, create new node and point front pointer and
    // proceeding node at it
    else {
        front->previous = new Node;
        *(front->previous) = newNode(c, front, nullptr);
        front = front->previous;
    }
    // Update the number of items
    numItems++;
}


/*
 * name:      insertAt
 * purpose:   insert an element at a given index
 * arguments: element and its index
 * returns:   none
 * effects:   adds the element at the given index in the CharLinkedList
 */
void CharLinkedList::insertAt(char c, int index) {
    // if the index is out of range of the CharLinkedList, throw an error 
    // message
    if (index > numItems or index < 0){
        throw std::range_error( "index (" + std::to_string(index) + 
        ") not in range [0.." + std::to_string(numItems) + "]" );
    } 
    // If inserting at the front of list, call pushAtFront
    if (index == 0) {
        pushAtFront(c);
    } 
    // If inserting at the back of list, call pushAtBack
    else if (index == numItems) {
        pushAtBack(c);
    } else {
        // Variables to track movement through the list
        int count = 0;
        Node *curr = front;
        // Move through the list until desired index is reached
        while (count < index - 1) {
            curr = curr->next;
            count++;
        }
        // Add a new node at the desired index and update the node pointers on
        // either side
        Node *temp = new Node;
        *temp = newNode(c, curr->next, curr);
        curr->next = temp;
        temp->next->previous = temp;
        // Update the number of items
        numItems++;
    }
}

/*
 * name:      insertInOrder
 * purpose:   insert an element in the CharLinkedList in alphabetical order
 * arguments: element
 * returns:   none
 * effects:   adds the element in order in the CharLinkedList
 */
void CharLinkedList::insertInOrder(char c) {
    // Variables to track movement through list
    Node *curr = front;
    int count = 0;
    // Move through the list until the right place to add the new element
    // is found 
    while (curr != nullptr) {
        if (c <= curr->info){
            insertAt(c, count);
            return;
        } else {
            curr = curr->next;
            count++;
        }
    }
    // If no place is found to add the element in order, add it at back
    pushAtBack(c);
}

/*
 * name:      toString
 * purpose:   Express a CharLinkedList in a string
 * arguments: none
 * returns:   A string representing the CharLinkedList
 * effects:   none
 */
std::string CharLinkedList::toString() const {
    // string statement framework
    std::string s = "[CharLinkedList of size " + std::to_string(numItems) 
                    + " <<";

    // add each element to the string
    Node *temp = front;
    while (temp != nullptr){
        s += temp->info;
        temp = temp->next;
    }

    s += ">>]";

    return s;
}

/*
 * name:      toReverseString
 * purpose:   Express a CharLinkedList in a reverse string
 * arguments: none
 * returns:   A reverse string representing the CharLinkedList
 * effects:   none
 */
std::string CharLinkedList:: toReverseString() const {
    // string statement framework
    std::string s = "[CharLinkedList of size " + std::to_string(numItems) 
                    + " <<";

    // add each element to the string in reverse order
    Node *temp = back;
    while (temp != nullptr){
        s += temp->info;
        temp = temp->previous;
    }

    s += ">>]";

    return s;
}

/*
 * name:      popFromFront
 * purpose:   remove the first element of the CharLinkedList
 * arguments: none
 * returns:   error message if the list is empty
 * effects:   removes the first element in the CharLinkedList
 */
void CharLinkedList::popFromFront() {
    // if the CharLinkedList is empty throw an error message
    if (isEmpty()){
        throw std::runtime_error("cannot pop from empty LinkedList");
    } 
    // Deallocate the first Node from the heap and update front pointer
    Node *temp = front;
    front = temp->next;
    delete temp;
    // If it was the only node in the list, also update the back pointer
    if (numItems == 1) {
        back = nullptr;
    } 
    // If not, update the new first node in the list
    else {
        front->previous = nullptr;
    }
    // Update the number of items in the list
    numItems--;
}

/*
 * name:      popFromBack
 * purpose:   remove the last element of the CharLinkedList
 * arguments: none
 * returns:   error message if the list is empty
 * effects:   removes the last element in the CharLinkedList
 */
void CharLinkedList::popFromBack() {
    // if the CharLinkedList is empty throw an error message
    if (isEmpty()){
        throw std::runtime_error("cannot pop from empty LinkedList");
    } 
    // Deallocate the last Node from the heap and update the back pointer
    Node *temp = back;
    back = temp->previous;
    delete temp;
    // If it was the only node in the list, also update the front pointer
    if (numItems == 1) {
        front = nullptr;
    } 
    // If not, update the new last node in the list
    else {
        back->next = nullptr;
    }
    // Update the number of items in the list
    numItems--;
}

/*
 * name:      removeAt
 * purpose:   remove the element at a given index in the CharLinkedList
 * arguments: the element index
 * returns:   error message if the index is out of range
 * effects:   removes given element in the CharLinkedList
 */
void CharLinkedList::removeAt(int index) {
    // if the index is out of range of the CharLinkedList, throw an error 
    // message
    if (index >= numItems or index < 0){
        throw std::range_error( "index (" + std::to_string(index) + 
        ") not in range [0.." + std::to_string(numItems) + ")" );
    }
    // If the element being removed is at the front, call popFromFront
    if (index == 0) {
        popFromFront();
    } 
    // If the element being removed is at the back, call popFromBack
    else if (index == numItems - 1) {
        popFromBack();
    } else {
        // Variables to track movement through list
        int count = 0;
        Node *curr = front;
        // Move to desired index in list
        while (count < index) {
            curr = curr->next;
            count++;
        }
        // Remove element and update nodes on either side
        curr->previous->next = curr->next;
        curr->next->previous = curr->previous;
        delete curr;
        // Update number of items in list
        numItems--;
    }
}

/*
 * name:      replaceAt
 * purpose:   replace the element at the given index in the CharLinkedList
 * arguments: the element being added
 * returns:   error message if the index is out of range
 * effects:   replaces given element in the CharLinkedList
 */
void CharLinkedList::replaceAt(char c, int index) {
    // if the index is out of range of the CharLinkedList, throw an error 
    // message
    if (index >= numItems or index < 0){
        throw std::range_error( "index (" + std::to_string(index) + 
        ") not in range [0.." + std::to_string(numItems) + ")" );
    }
    // Call the recursive replace at helper function
    replaceAtHelper(c, front, index);
}

/*
 * name:      concatenate
 * purpose:   concatenates two CharLinkedLists together
 * arguments: pointer to the CharLinkedList being added
 * returns:   none
 * effects:   concatenates the given CharLinkedList on the end of the original
 */
void CharLinkedList::concatenate(CharLinkedList *other) {
    // Temp variable to store copy of the list being added
    CharLinkedList temp = *other;

    // Add each element of the provided list at the end of the original list
    for (int i = 0; i < temp.size(); i++) {
        pushAtBack(temp.elementAt(i));
    }
}

/*
 * name:      newNode
 * purpose:   create a newNode variable
 * arguments: a char and next pointer for the node
 * returns:   the newly created node
 * effects:   none
 */
CharLinkedList::Node CharLinkedList::newNode(char c, Node *n, Node *p) {
    // Initializes a new node to all the given variables
    Node newN;
    newN.info = c;
    newN.next = n;
    newN.previous = p;
    // Return this new node
    return newN;
}

/*
 * name:      destructorHelper
 * purpose:   recursively move through a CharLinkedList and deallocate the 
 *            memory
 * arguments: pointer to the current node
 * returns:   none
 * effects:   deallocates the memory for a CharLinkedList
 */
void CharLinkedList::destructorHelper(Node *curr) {
    // Recursively move through the list and deallocate the heap memory
    // of every node
    if (curr != nullptr) {
        destructorHelper(curr->next);
        delete curr;
    }
}

/*
 * name:      elementAtHelper
 * purpose:   recursively move through a CharLinkedList to find the element at
 *            a specific index
 * arguments: index of element
 * returns:   the char element at the given index
 * effects:   none
 */
char CharLinkedList::elementAtHelper(Node *curr, int index) const {
    // Recursively move through the list until the desired index is reached
    if (index == 0) {
        // Return the element at that index
        return curr->info;
    }
    return elementAtHelper(curr->next, index - 1);
}

/*
 * name:      replaceAtHelper
 * purpose:   recursively move through a CharLinkedList to find the element at
 *            a specific index and replace it
 * arguments: index of element, char to replace with
 * returns:   none
 * effects:   replaces the char element at the given index
 */
void CharLinkedList::replaceAtHelper(char c, Node *curr, int index) {
    // Recursively move through the list until the desired index is reached
    if (index == 0) {
        // Replace element at given index
        curr->info = c;
        return;
    }

    return replaceAtHelper(c, curr->next, index - 1);
}