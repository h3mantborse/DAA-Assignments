#include <bits/stdc++.h>
using namespace std;

class QNode {
    public:
	int data;
	QNode* next;
	QNode(int d)
	{
		data = d;
		next = NULL;
	}
};

class Queue {
    public:
	QNode *front, *rear;
	Queue() { front = rear = NULL; }

};

int main()
{
	Queue q;
}