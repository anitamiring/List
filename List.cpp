//
// Created by a27stude on 19.03.19.
//

#include <stdexcept>
#include "List.h"

struct List::List_element {
    List_element(int val) : value(val), next(nullptr) {}

    int value;
    List_element *next;
};

void List::push_back(int element) {
    if (first == nullptr) {
        first = new List_element(element);
    } else {
        List_element *tmp = first;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new List_element(element);
    }
    size++;
}

List::List() {
    first = nullptr;
    size = 0;
}

bool List::empty() {
    return first == nullptr;
}

size_t List::get_size() {
    return size;
}

void List::pop_back() {
    if (first != nullptr) {
        List_element *tmp = first;
        if (first->next != nullptr) {
            List_element *tmp2 = first->next;
            while (tmp2->next != nullptr) {
                tmp = tmp->next;
                tmp2 = tmp2->next;
            }
            delete tmp->next;
            tmp->next = nullptr;
        } else {
            delete first;
            first = nullptr;

        }

        size--;
    } else {
        throw std::runtime_error("empty list");
    }
}

int List::back() {

    if (this->empty()) {
        throw std::runtime_error("empty list");
    }
    List_element *tmp = first;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    return tmp->value;

}

void List::reverse() {
    List newList;
    while (this->size != 0) {
        newList.push_back((*this).back());
        this->pop_back();
    }
    this->size = newList.size;
    this->first = newList.first;

}

void List::sort() {
    int oldListSize = size;
    int *tab = new int[oldListSize];
    for (int i = 0; i < oldListSize; ++i) {
        tab[i] = this->back();
        this->pop_back();
    }
    for (int h = 0; h < oldListSize; h++) {

        for (int i = 0; i < oldListSize - h - 1; i++) {
            if (tab[i] > tab[i + 1]) {
                int a = tab[i + 1];
                tab[i + 1] = tab[i];
                tab[i] = a;
            }
        }
    }

    for (int j = 0; j < oldListSize; ++j) {
        this->push_back(tab[j]);
    }

    delete[] tab;
}

int List::countAllValues() {
    if (this->first == nullptr) {
        return 0;
    } else {
        int sum = 0;
        List_element* tmp = first;
        while (tmp->next != nullptr) {
            sum += tmp->value;
            tmp = tmp->next;
        }
        sum += tmp->value;

        return sum;
    }
}

std::string List::print() {
    std::string output = "Zawartosc listy: ";

    if (this->first == nullptr) {
        output += "PUSTA";
    } else {
        int sum = 0;
        List_element* tmp = first;
        while (tmp->next != nullptr) {
            output += std::to_string(tmp->value);
            output += ", ";
            tmp = tmp->next;
        }
        output += std::to_string(tmp->value);
    }

    return output;
}
