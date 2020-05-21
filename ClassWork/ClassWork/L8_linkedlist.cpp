//
// Created by user on 14.05.2020.
//

#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node() {}

    Node(int data, Node *next = nullptr) : data(data), next(next) {}

    friend bool operator<(const Node &lhs, const Node &rhs) {
        return lhs.data < rhs.data;
    }

    friend bool operator>(const Node &lhs, const Node &rhs) { return rhs < lhs; }

    friend bool operator<=(const Node &lhs, const Node &rhs) { return !(lhs > rhs); }

    friend bool operator>=(const Node &lhs, const Node &rhs) { return !(lhs < rhs); }
};

struct LinkedIntList {
    Node *head;

    LinkedIntList() : head(nullptr) {}

    LinkedIntList(Node *elem) : head(elem) {}

    void add(int new_data) {
        if (head == nullptr) {
            head = new Node(new_data);
        } else {
//            Node *tmp = (Node *) malloc(sizeof(Node));
//            tmp->data = new_data;
//            tmp->next = nullptr;
            Node *tmp = new Node(new_data);
            Node *current;
            for (current = head; current->next != nullptr; current = current->next);

            current->next = tmp;
        }
    }

    void add_first(int new_data) {
        Node *tmp = new Node(new_data, head);
        head = tmp;
    }

    void remove() {
        Node *current = head;
        for (; current->next->next != nullptr; current = current->next);

        delete current->next;
        current->next = nullptr;
    }

    void remove_first() {
        Node *second = head->next;
        delete head;
        head = second;
    }

    string getString() const {
        Node *current = head;
        string result;
        while (current != nullptr) {
            result += to_string(current->data);
            if (current->next != nullptr) result += +", ";
            current = current->next;
        }
        return result;
    }

    void print() {
        string result = getString();
        cout << result << endl;
    }

    friend ostream &operator<<(ostream &os, LinkedIntList &list) {
        os << "LinkedIntList{" << list.getString() << "}" << endl;
        return os;
    }
};

int main() {
    LinkedIntList *list = new LinkedIntList;
    Node *node2 = new Node(22);
    Node *node = new Node(11, node2);
    cout << (node < node2) << endl;
//    list->head = node;

    list->add(11);
    list->add(22);
    list->add(33);
    list->add(44);

    list->print();

    list->remove();
    list->print();

//    cout.operator<<(123);
//    cout << 123;
    cout << *list;

}