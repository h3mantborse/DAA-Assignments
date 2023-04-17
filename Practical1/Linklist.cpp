#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* next;
};

class LinkedList {
   private:
    Node* head;

   public:
    LinkedList() { head = NULL; }
    void append(int data);
    void prepend(int data);
    void printList();
};

void LinkedList::append(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}

void LinkedList::prepend(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void LinkedList::printList() {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    LinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.prepend(5);
    list.printList();
    return 0;
}