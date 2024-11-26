/*
 *  CharLinkedList.h
 *  Name: Leo Kim
 *  Date: 2/3/22
 *
 *  Purpose: Class declaration for the CharLinkedList class. A CharLinkedList is
 *           a doubly linked list made up of char variables that can be altered 
 *           and accessed by a variety of functions.
 */

#ifndef CHAR_LINKED_LIST_H
#define CHAR_LINKED_LIST_H

#include <string>

class CharLinkedList {
public:
    CharLinkedList(); // Default Constructor
    CharLinkedList(char c); // Single Character Constructor
    CharLinkedList(char arr[], int size); // Char Array Constructor
    CharLinkedList(const CharLinkedList &other); // Copy Constructor
    ~CharLinkedList(); // Destructor
    CharLinkedList &operator=(const CharLinkedList &other);   // Deepcopy
    // assignent operator

    // Other Member functions
    bool isEmpty() const;
    void clear();
    int size() const;
    char first() const;
    char last() const;
    char elementAt(int index) const;
    void pushAtBack(char c);
    void pushAtFront(char c);
    void insertAt(char c, int index);
    void insertInOrder(char c);
    std::string toString() const;
    std::string toReverseString() const;
    void popFromFront();
    void popFromBack();
    void removeAt(int index);
    void replaceAt(char c, int index);
    void concatenate(CharLinkedList *other);

private:
    // Private Node struct definition
    struct Node {
        char      info;
        Node       *next;
        Node      *previous;
    };

    // Private data members
    Node *front;
    Node *back;
    int numItems;

    // Private Helper Functions
    Node newNode(char c, Node *n, Node *p);
    void destructorHelper(Node *curr);
    char elementAtHelper(Node *curr, int index) const;
    void replaceAtHelper(char c, Node *curr, int index);
};

#endif
