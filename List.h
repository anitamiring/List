//
// Created by a27stude on 19.03.19.
//

#ifndef CODINGDOJO_LIST_H
#define CODINGDOJO_LIST_H


#include <cstddef>

class List {
public:
    List();
    void push_back (int element);
    void pop_back ();
    int back();
    bool empty();
    void sort();  //od najmniejszego do najwiekszego
    void reverse();
    int countAllValues();
    size_t get_size();

    std::string print();




private:
    struct List_element;
    List_element * first;
    size_t size;
};


#endif //CODINGDOJO_LIST_H
