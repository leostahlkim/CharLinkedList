/*
 *  unit_tests.h
 *  Name: Leo Kim
 *  Date: 2/3/22
 *
 *  Purpose: Unit testing for each function in the implementation
 *           of the CharLinkedList class.
 *
 */

#include "CharLinkedList.h"
#include <cassert>

void Test_Test() {
    assert(1 == 1);
}

// TEST GROUP default constructor

void defConstructor_Test1() {
    CharLinkedList list;
}

void defConstructor_Test2() {
    CharLinkedList list;
    assert(list.isEmpty());
}

void defConstructor_Test3() {
    CharLinkedList list;
    assert(list.size() == 0);
    assert(list.toString() == "[CharLinkedList of size 0 <<>>]");
}

// TEST GROUP single char constructor
void singleCharConstructor_Test1() {
    CharLinkedList list('a');
}

void singleCharConstructor_Test2() {
    CharLinkedList list('a');
    assert(list.size() == 1);
    assert(list.first() == 'a');
    assert(list.last() == 'a');
    assert(not list.isEmpty());
}

void singleCharConstructor_Test3() {
    CharLinkedList list('a');
    list.pushAtBack('b');
    assert(list.size() == 2);
    assert(list.first() == 'a');
    assert(list.last() == 'b');
    assert(not list.isEmpty());
}

void singleCharConstructor_Test4() {
    CharLinkedList list('a');
    assert(list.toString() == "[CharLinkedList of size 1 <<a>>]");
}

// TEST GROUP arr constructor

void ArrConstructor_Test1(){
    char test_arr[0] = {};
    CharLinkedList list(test_arr, 0);
    assert(list.size() == 0);
    assert(list.isEmpty());
}

void ArrConstructor_Test2(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharLinkedList list(test_arr, 5);
    assert(list.size() == 5);
    assert(list.first() == 'a');
    assert(list.last() == 'e');
    assert(not list.isEmpty());
}

void ArrConstructor_Test3(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharLinkedList list(test_arr, 5);
    assert(list.toString() == "[CharLinkedList of size 5 <<abcde>>]");
}

// TEST GROUP copy constructor
void CopyConstructor_Test1(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharLinkedList list1(test_arr, 5);
    CharLinkedList list2(list1);
    list1.popFromBack();
    assert(list1.size() == 4);
    assert(list2.size() == 5);
}

void CopyConstructor_Test2(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharLinkedList list1(test_arr, 5);
    CharLinkedList list2(list1);
    list2.pushAtBack('f');
    list1.removeAt(1);
    assert(list1.toString() == "[CharLinkedList of size 4 <<acde>>]");
    assert(list2.toString() == "[CharLinkedList of size 6 <<abcdef>>]");
}

void CopyConstructor_Test3(){
    CharLinkedList list1;
    CharLinkedList list2(list1);
    list2.pushAtBack('f');
    assert(list1.toString() == "[CharLinkedList of size 0 <<>>]");
    assert(list2.toString() == "[CharLinkedList of size 1 <<f>>]");
}

void CopyConstructor_Test4(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharLinkedList list1(test_arr, 5);
    CharLinkedList list2(list1);
    list2.pushAtBack('f');
    list1.removeAt(1);
    assert(list1.toString() == "[CharLinkedList of size 4 <<acde>>]");
    assert(list2.toString() == "[CharLinkedList of size 6 <<abcdef>>]");
}

// TEST GROUP Overload assignment operator
void AssignOp_Test1(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharLinkedList list1(test_arr, 5);
    CharLinkedList list2;
    list2 = list1;
    //list2 = list1;
    list1.popFromBack();
    assert(list1.size() == 4);
    assert(list2.size() == 5);
}

void AssignOp_Test2(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharLinkedList list1(test_arr, 5);
    CharLinkedList list2;
    list2 = list1;
    list2.pushAtBack('f');
    list1.removeAt(1);
    assert(list1.toString() == "[CharLinkedList of size 4 <<acde>>]");
    assert(list2.toString() == "[CharLinkedList of size 6 <<abcdef>>]");
}


void AssignOp_Test3(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharLinkedList list1(test_arr, 5);
    CharLinkedList list2;
    CharLinkedList list3('r');
    list2 = (list3 = list1);
    list2.pushAtBack('f');
    list1.removeAt(1);
    assert(list1.toString() == "[CharLinkedList of size 4 <<acde>>]");
    assert(list2.toString() == "[CharLinkedList of size 6 <<abcdef>>]");
}

void AssignOp_Test4(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    //CharLinkedList list1(test_arr, 5);
    CharLinkedList list1;
    CharLinkedList list2(test_arr, 5); 
    list2 = list1;
    list2.pushAtBack('f');
    list1.pushAtBack('d');
    list2.pushAtBack('b');
    assert(list1.toString() == "[CharLinkedList of size 1 <<d>>]");
    assert(list2.toString() == "[CharLinkedList of size 2 <<fb>>]");
    //assert(list2.toString() == "[CharLinkedList of size 7 <<abcdefb>>]");
}

void AssignOp_Test5(){
    char test_arr1[5] = { 'a', 'b', 'c', 'd', 'e'};
    char test_arr2[5] = { 'f', 'g', 'h', 'i', 'j'};
    CharLinkedList list1(test_arr1, 5);
    CharLinkedList list2(test_arr2, 5);
    list2 = list1;
    list2.pushAtBack('f');
    list1.removeAt(1);
    assert(list1.toString() == "[CharLinkedList of size 4 <<acde>>]");
    assert(list2.toString() == "[CharLinkedList of size 6 <<abcdef>>]");
}


// TEST GROUP clear

void clear_Test1() {
    CharLinkedList list;
    list.clear();
    //list.clear();
    assert(list.toString() == "[CharLinkedList of size 0 <<>>]");
}

void clear_Test2(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharLinkedList list(test_arr, 5);
    list.clear();
    assert(list.toString() == "[CharLinkedList of size 0 <<>>]");
}

void Clear_Test3(){
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharLinkedList list(test_arr, 5);
    list.clear();
    assert(list.size() == 0);
    assert(list.isEmpty());
}


// TEST GROUP first and last error messages

void first_test() {
    CharLinkedList list;
    bool runtime_error_thrown = false;
    std::string error_message;

    try {
        list.first();
    }
    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }

    assert(runtime_error_thrown);
    assert(error_message == "cannot get first of empty LinkedList");
}

void last_test() {
    CharLinkedList list;
    bool runtime_error_thrown = false;
    std::string error_message;

    try {
        list.last();
    }
    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }

    assert(runtime_error_thrown);
    assert(error_message == "cannot get last of empty LinkedList");
}

//TEST GROUP elementAt

void elementAt_Test1() {
    CharLinkedList list;
    bool range_error_thrown = false;
    std::string error_message;

    try {
        list.elementAt(0);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (0) not in range [0..0)");
}

void elementAt_Test2() {
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharLinkedList list(test_arr, 5);
    bool range_error_thrown = false;
    std::string error_message;

    try {
        list.elementAt(5);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (5) not in range [0..5)");
}

void elementAt_Test3() {
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharLinkedList list(test_arr, 5);
    bool range_error_thrown = false;
    std::string error_message;

    try {
        list.elementAt(-1);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (-1) not in range [0..5)");
}

void elementAt_Test4() {
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharLinkedList list(test_arr, 5);
    bool range_error_thrown = false;
    std::string error_message;

    try {
        list.elementAt(54);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (54) not in range [0..5)");
}

void elementAt_Test5() {
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharLinkedList list(test_arr, 5);
    assert(list.elementAt(0) == 'a');
    assert(list.elementAt(4) == 'e');
    assert(list.elementAt(2) == 'c');
}

void elementAt_Test6() {
    CharLinkedList list;
    for (int i = 0; i < 101; i++){
        list.pushAtBack('d');
    }

    assert(list.elementAt(76) == 'd');
    assert(list.elementAt(0) == 'd');
    assert(list.elementAt(99) == 'd');
}


// TEST GROUP pushAtBack

void pushAtBack_Test1() {
    CharLinkedList list;
    list.pushAtBack('a');
}

void pushAtBack_Test2() {
    CharLinkedList list;
    list.pushAtBack('a');
    assert(not list.isEmpty());
    assert(list.size() == 1);
    assert(list.first() == 'a');
    assert(list.last() == 'a');
}

void pushAtBack_Test3() {
    CharLinkedList list;
    list.pushAtBack('a');
    list.pushAtBack('b');
    list.pushAtBack('c');
    list.pushAtBack('d');
    list.pushAtBack('e');
    list.pushAtBack('f');
    list.pushAtBack('g');
}

void pushAtBack_Test4() {
    CharLinkedList list;
    list.pushAtBack('a');
    list.pushAtBack('b');
    list.pushAtBack('c');
    list.pushAtBack('d');
    list.pushAtBack('e');
    list.pushAtBack('f');
    list.pushAtBack('g');
    assert(not list.isEmpty());
    assert(list.size() == 7);
    assert(list.first() == 'a');
    assert(list.last() == 'g');
}

void pushAtBack_Test5() {
    CharLinkedList list;
    list.pushAtBack('a');
    list.pushAtBack('b');
    list.pushAtBack('c');
    list.pushAtBack('d');
    list.pushAtBack('e');
    list.pushAtBack('f');
    list.pushAtBack('g');
    assert(list.toString() == "[CharLinkedList of size 7 <<abcdefg>>]");
}

// TEST GROUP pushAtFront

void pushAtFront_Test1() {
    CharLinkedList list;
    list.pushAtFront('a');
}

void pushAtFront_Test2() {
    CharLinkedList list;
    list.pushAtFront('a');
    assert(not list.isEmpty());
    assert(list.size() == 1);
    assert(list.first() == 'a');
    assert(list.last() == 'a');
}

void pushAtFront_Test3() {
    CharLinkedList list;
    list.pushAtFront('a');
    list.pushAtFront('b');
    list.pushAtFront('c');
    list.pushAtFront('d');
    list.pushAtFront('e');
    list.pushAtFront('f');
    list.pushAtFront('g');
}

void pushAtFront_Test4() {
    CharLinkedList list;
    list.pushAtFront('a');
    list.pushAtFront('b');
    list.pushAtFront('c');
    list.pushAtFront('d');
    list.pushAtFront('e');
    list.pushAtFront('f');
    list.pushAtFront('g');
    assert(not list.isEmpty());
    assert(list.size() == 7);
    assert(list.first() == 'g');
    assert(list.last() == 'a');
}

void pushAtFront_Test5() {
    CharLinkedList list;
    list.pushAtFront('a');
    list.pushAtFront('b');
    list.pushAtFront('c');
    list.pushAtFront('d');
    list.pushAtFront('e');
    list.pushAtFront('f');
    list.pushAtFront('g');
    assert(list.toString() == "[CharLinkedList of size 7 <<gfedcba>>]");
}

void pushAtFront_Test6() {
    CharLinkedList list;
    list.pushAtFront('a');
    list.pushAtBack('b');
    list.pushAtFront('c');
    list.pushAtBack('d');
    list.pushAtFront('e');
    list.pushAtBack('f');
    list.pushAtFront('g');
    assert(list.toString() == "[CharLinkedList of size 7 <<gecabdf>>]");
}

// TEST GROUP insertAt

void insertAt_empty_correct() { 
    CharLinkedList test_list;
    test_list.insertAt('a', 0);
    assert(test_list.size() == 1);
    assert(test_list.elementAt(0) == 'a');
                               
}

void insertAt_empty_incorrect() {
    bool range_error_thrown = false;
    std::string error_message = "";

    CharLinkedList test_list;
    try {
        test_list.insertAt('a', 42);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..0]");
    
}

void insertAt_front_singleton_list() {
    CharLinkedList test_list('a');

    test_list.insertAt('b', 0);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'b');
    assert(test_list.elementAt(1) == 'a');
    
}

void insertAt_back_singleton_list() {
    CharLinkedList test_list('a');
    test_list.insertAt('b', 1);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'a');
    assert(test_list.elementAt(1) == 'b');
    
}

void insertAt_many_elements() {
    CharLinkedList test_list;

    for (int i = 0; i < 1000; i++) {
        test_list.insertAt('a', i);
    }

    assert(test_list.size() == 1000);

    for (int i = 0; i < 1000; i++) {
        assert(test_list.elementAt(i) == 'a');
    }
    
}

void insertAt_front_back_middle() {
        char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
        CharLinkedList test_list(test_arr, 8);

        test_list.insertAt('z', 3);

        assert(test_list.size() == 9);
        assert(test_list.elementAt(3) == 'z');
        assert(test_list.toString() == 
        "[CharLinkedList of size 9 <<abczdefgh>>]");

        test_list.insertAt('y', 0);

        assert(test_list.size() == 10);
        assert(test_list.elementAt(0) == 'y');
        assert(test_list.toString() == 
        "[CharLinkedList of size 10 <<yabczdefgh>>]");

        test_list.insertAt('x', 10);

        assert(test_list.size() == 11);
        assert(test_list.elementAt(10) == 'x');
        assert(test_list.toString() 
        == "[CharLinkedList of size 11 <<yabczdefghx>>]");
}

void insertAt_nonempty_incorrect() {
    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharLinkedList test_list(test_arr, 8);

    bool range_error_thrown = false;

    std::string error_message = "";

    try {
        test_list.insertAt('a', 42);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..8]");
}


// TEST GROUP insertInOrder

void insertInOrder_Test1(){
    CharLinkedList list;
    list.insertInOrder('d');
    assert(list.toString() == "[CharLinkedList of size 1 <<d>>]");
}

void insertInOrder_Test2(){
    CharLinkedList list;
    list.pushAtBack('A');
    list.pushAtBack('B');
    list.pushAtBack('C');
    list.pushAtBack('E');
    list.pushAtBack('F');
    list.pushAtBack('G');
    list.insertInOrder('D');
    assert(list.toString() == "[CharLinkedList of size 7 <<ABCDEFG>>]");
}

void insertInOrder_Test3(){
    CharLinkedList list;
    list.pushAtBack('B');
    list.pushAtBack('C');
    list.pushAtBack('C');
    list.pushAtBack('C');
    list.pushAtBack('F');
    list.pushAtBack('G');
    list.insertInOrder('C');
    assert(list.toString() == "[CharLinkedList of size 7 <<BCCCCFG>>]");
}

void insertInOrder_Test4(){
    CharLinkedList list;
    list.pushAtBack('b');
    list.pushAtBack('c');
    list.pushAtBack('c');
    list.pushAtBack('c');
    list.pushAtBack('f');
    list.pushAtBack('g');
    list.insertInOrder('z');
    assert(list.toString() == "[CharLinkedList of size 7 <<bcccfgz>>]");
}

void insertInOrder_Test5(){
    CharLinkedList list;
    list.insertInOrder('a');
    list.insertInOrder('d');
    list.insertInOrder('e');
    list.insertInOrder('g');
    list.insertInOrder('f');
    list.insertInOrder('b');
    list.insertInOrder('c');
    assert(list.toString() == "[CharLinkedList of size 7 <<abcdefg>>]");
}

void insertInOrder_Test6() {
    CharLinkedList list;
    for (char c = 122; c > 96; c--) {
        list.insertInOrder(c);
    }
    //assert(list.toString() == "[CharLinkedList of size 26 
    //<<abcdefghijklmnopqrstuvwxyz>>]");
}

// TEST GROUP toReverseString

void toReverseString_Test1() {
    CharLinkedList list;
    assert(list.toReverseString() == "[CharLinkedList of size 0 <<>>]");
}

void toReverseString_Test2() {
    char test_arr[5] = { 'a', 'b', 'c', 'd', 'e'};
    CharLinkedList list(test_arr, 5);
    assert(list.toReverseString() == "[CharLinkedList of size 5 <<edcba>>]");
}


// TEST GROUP popFromFront

void popFromFront_Test1(){
    CharLinkedList list;
    list.pushAtBack('b');
    list.pushAtBack('a');
    list.pushAtBack('n');
    list.pushAtBack('a');
    list.pushAtBack('n');
    list.pushAtBack('a');
    list.pushAtBack('s');
    list.pushAtBack('s');
    list.popFromFront();
    list.popFromFront();
    assert(list.toString() == "[CharLinkedList of size 6 <<nanass>>]");
}

void popFromFront_Test2(){
    CharLinkedList list;
    bool runtime_error_thrown = false;
    std::string error_message;

    try {
        list.popFromFront();
    }
    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }

    assert(error_message == "cannot pop from empty LinkedList");
}

void popFromFront_Test3() {
    CharLinkedList list('a');
    list.popFromFront();
    assert(list.toString() == "[CharLinkedList of size 0 <<>>]");
}

void popFromFront_Test4() {
    CharLinkedList list;

    for (char c = 122; c > 96; c--) {
        list.insertInOrder(c);
    }

    for (int i = 0; i < 25; i++) {
        list.popFromFront();
    }
    std::cerr << list.toString();
    assert(list.toString() == "[CharLinkedList of size 1 <<z>>]");
}

// TEST GROUP popFromBack

void popFromBack_Test1(){
    CharLinkedList list;
    list.pushAtFront('b');
    list.pushAtFront('a');
    list.pushAtFront('n');
    list.pushAtFront('a');
    list.pushAtFront('n');
    list.pushAtFront('a');
    list.pushAtFront('s');
    list.pushAtFront('s');
    list.popFromBack();
    list.popFromBack();
    assert(list.toString() == "[CharLinkedList of size 6 <<ssanan>>]");
}

void popFromBack_Test2(){
    CharLinkedList list;
    bool runtime_error_thrown = false;
    std::string error_message;

    try {
        list.popFromBack();
    }
    catch (const std::runtime_error &e) {
        runtime_error_thrown = true;
        error_message = e.what();
    }

    assert(error_message == "cannot pop from empty LinkedList");
}

void popFromBack_Test3() {
    CharLinkedList list('a');
    list.popFromBack();
    assert(list.toString() == "[CharLinkedList of size 0 <<>>]");
}

void popFromBack_Test4() {
    CharLinkedList list;

    for (char c = 122; c > 96; c--) {
        list.insertInOrder(c);
    }

    for (int i = 0; i < 25; i++) {
        list.popFromBack();
    }
    std::cerr << list.toString();
    assert(list.toString() == "[CharLinkedList of size 1 <<a>>]");
}

// TEST GROUP removeAt

void removeAt_empty_correct() { 
    CharLinkedList test_list;
    test_list.insertAt('a', 0);
    test_list.removeAt(0);
    assert(test_list.size() == 0);
}

void removeAt_empty_incorrect() {
    bool range_error_thrown = false;
    std::string error_message = "";

    CharLinkedList test_list;
    try {
        test_list.removeAt(3);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (3) not in range [0..0)");    
}

void removeAt_front_singleton_list() {
    CharLinkedList test_list('a');

    test_list.pushAtBack('b');
    test_list.removeAt(0);

    assert(test_list.size() == 1);
    assert(test_list.elementAt(0) == 'b');
}

void removeAt_back_singleton_list() {
    CharLinkedList test_list('a');

    test_list.insertAt('b', 1);
    //std::cerr << "here";
    test_list.removeAt(1);

    assert(test_list.size() == 1);
    assert(test_list.elementAt(0) == 'a');
    
}

void removeAt_many_elements() {
    CharLinkedList test_list;

    for (int i = 0; i < 1000; i++) {
        test_list.insertAt('a', i);
    }

    for (int i = 0; i < 998; i++) {
        test_list.removeAt(1);
    }

    assert(test_list.size() == 2);    
}

void removeAt_front_back_middle() {
        char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
        CharLinkedList test_list(test_arr, 8);

        test_list.removeAt(3);

        assert(test_list.size() == 7);
        assert(test_list.elementAt(3) == 'e');
        assert(test_list.toString() == 
        "[CharLinkedList of size 7 <<abcefgh>>]");

        test_list.removeAt(0);

        assert(test_list.size() == 6);
        assert(test_list.elementAt(0) == 'b');
        assert(test_list.toString() == 
        "[CharLinkedList of size 6 <<bcefgh>>]");

        test_list.removeAt(5);

        assert(test_list.size() == 5);
        assert(test_list.elementAt(4) == 'g');
        assert(test_list.toString() 
        == "[CharLinkedList of size 5 <<bcefg>>]");
}

void removeAt_nonempty_incorrect() {
    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharLinkedList test_list(test_arr, 8);

    bool range_error_thrown = false;

    std::string error_message = "";

    try {
        test_list.removeAt(42);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..8)");
}

// TEST GROUP replaceAt
void replaceAt_Test1(){
    CharLinkedList list;
    list.pushAtBack('b');
    list.pushAtBack('a');
    list.pushAtBack('n');
    list.pushAtBack('a');
    list.pushAtBack('n');
    list.pushAtBack('a');
    list.pushAtBack('s');
    list.pushAtBack('s');
    list.replaceAt('t', 2);
    list.replaceAt('i', 5);
    list.replaceAt('c', 0);
    list.replaceAt('t', 7);
    //list.replaceAt('t',-1);
    assert(list.toString() == "[CharLinkedList of size 8 <<catanist>>]");
}

void replaceAt_Test2(){
    CharLinkedList list('a');
    list.replaceAt('t', 0);
}

void replaceAt_Test3(){
    CharLinkedList list;
    list.pushAtBack('b');
    list.pushAtBack('a');
    list.replaceAt('o', 1);
    assert(list.last() == 'o');
}

void replaceAt_Test4() {
    CharLinkedList list;
    bool range_error_thrown = false;
    std::string error_message;

    try {
        list.replaceAt('d', 0);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (0) not in range [0..0)");
}

void replaceAt_Test5() {
    CharLinkedList list;
    for (int i = 0; i < 15; i++) {
        list.pushAtBack('a');
    }

    bool range_error_thrown = false;
    std::string error_message;

    try {
        list.replaceAt('d', -2);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (-2) not in range [0..15)");
    //std::cout << error_message;
    //assert(1==0);
}

// TEST GROUP concatenate

void concatenate_Test1() {
    CharLinkedList list1('f');
    CharLinkedList list2('o');
    list1.concatenate(&list2);
    assert(list1.toString() == "[CharLinkedList of size 2 <<fo>>]");
}

void concatenate_Test2() {
    CharLinkedList list1;
    CharLinkedList list2;
    list1.pushAtBack('b');
    list1.pushAtBack('a');
    list1.pushAtBack('n');
    list1.pushAtBack('a');
    list1.pushAtBack('n');
    list2.pushAtBack('a');
    list2.pushAtBack('s');
    list2.pushAtBack('s');
    list1.concatenate(&list2);
    assert(list1.toString() == "[CharLinkedList of size 8 <<bananass>>]");
    assert(list2.toString() == "[CharLinkedList of size 3 <<ass>>]");
}


void concatenate_Test3() {
    CharLinkedList list1;
    CharLinkedList list2;
    list2.pushAtBack('b');
    list2.pushAtBack('a');
    list2.pushAtBack('n');
    list2.pushAtBack('a');
    list2.pushAtBack('n');
    list2.pushAtBack('a');
    list2.pushAtBack('s');
    list2.pushAtBack('s');
    list1.concatenate(&list2);
    assert(list1.toString() == "[CharLinkedList of size 8 <<bananass>>]");
}

void concatenate_Test4() {
    CharLinkedList list1;
    list1.pushAtBack('b');
    list1.pushAtBack('a');
    list1.pushAtBack('n');
    list1.pushAtBack('a');
    list1.pushAtBack('n');
    list1.pushAtBack('a');
    list1.pushAtBack('s');
    list1.pushAtBack('s');
    list1.concatenate(&list1);
    assert(list1.toString() == 
    "[CharLinkedList of size 16 <<bananassbananass>>]");
}

void concatenate_Test5() {
    CharLinkedList list1;
    CharLinkedList list2;
    list2.pushAtBack('b');
    list2.pushAtBack('a');
    list2.pushAtBack('n');
    list2.pushAtBack('a');
    list2.pushAtBack('n');
    list2.pushAtBack('a');
    list2.pushAtBack('s');
    list2.pushAtBack('s');
    list2.concatenate(&list1);
    assert(list2.toString() == "[CharLinkedList of size 8 <<bananass>>]");
}

void concatenate_Test6() {
    CharLinkedList list1;
    CharLinkedList list2;
    list2.concatenate(&list1);
    assert(list2.toString() == "[CharLinkedList of size 0 <<>>]");
}