#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void addNode(int data,Node* &root)
{
    Node *newNode = new Node(data);

    if (root == nullptr)
    {
        root = newNode;
    }
    else
    {
        Node *focusNode = root;
        Node *parent;

        while (true)
        {
            parent = focusNode;

            if (data < focusNode->data)
            {
                focusNode = focusNode->left;
                if (focusNode == nullptr)
                {
                    parent->left = newNode;
                    return;
                }
            }
            else
            {
                focusNode = focusNode->right;
                if (focusNode == nullptr)
                {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }
}

void preOrderTraversal(Node *focusNode)
{
    if (focusNode != nullptr)
    {
        std::cout << focusNode->data << " ";
        preOrderTraversal(focusNode->left);
        preOrderTraversal(focusNode->right);
    }
}

int main()
{
    Node* root=NULL;
    
    addNode(25,root);
    addNode(75,root);
    addNode(12,root);
    addNode(37,root);
    addNode(50,root);
    addNode(43,root);
    addNode(30,root);
    preOrderTraversal(root);

    return 0;
}