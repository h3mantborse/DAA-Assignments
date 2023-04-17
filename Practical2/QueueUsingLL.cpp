#include <iostream>
using namespcae std;
struct Node {
    int data;
    Node *next;
};

class Queue {
private:
    Node *front;
    Node *rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int data) {
        Node *temp = new Node;
        temp->data = data;
        temp->next = nullptr;
        if (rear == nullptr) {
            front = temp;
            rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if (front == nullptr) {
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    int peek() {
        if (front == nullptr) {
            return -1;
        }
        return front->data;
    }

    bool is_empty() {
        return front == nullptr;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    while (!q.is_empty()) {
        cout << q.peek() << " ";
        q.dequeue();
    }
    return 0;
}
