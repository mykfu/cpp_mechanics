//
// Created by user on 14.05.2020.
//

#include <iostream>
#include <string>
using namespace std;

struct Element {
    int data;
    Element *next;
};

struct LinkedIntList {
    Element *head;
    void print() {
        Element *current = head;
        string result;
        while (current->next != NULL) {
            result += current->data;
            if (current->next != NULL) result +=  + ", ";
            current = current->next;
        }
        cout << result << endl;
    }
};

int main() {
    LinkedIntList *list;
    Element *elem2 = NULL;
    elem2->data = 2;
    elem2->next = NULL;
    Element *elem1 = NULL;
    elem1->data = 1;
    elem1->next = elem2;

    list->head = elem1;

    list->print();


}