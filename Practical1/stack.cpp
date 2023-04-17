#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
//typedef __int128 ell;
#define MOD 1000000007;

//  STATIC USING STATIC ARRAY
class StackUsingArray{
    int *data;
    int nextInd;
    int capacity;
     
    public:

    StackUsingArray(int totalSize){
        data  = new int[totalSize];
        nextInd = 0;
        capacity = totalSize;

    }

    int size(){
        return nextInd;
    }

    bool isEmpty(){
       return nextInd==0;
    }

    void push(int element){
        if(nextInd == capacity){
            cout<<"Stack is full. ";
        }else{
        data[nextInd] =  element;
        cout<<data[nextInd]<<endl;
        nextInd++;
        
        }
    }

    int pop(){
        if(nextInd!=0){
        nextInd--;
        return data[nextInd];
        }else{
            cout<<"Stack is Empty ";
            return INT_MIN; 
        }

    }
    
    int top(){
        if(!isEmpty()){
        return data[nextInd-1];
        }else{
            cout<<"Stack is empty ";
            return INT_MIN;
        }
    }
};

// STACK USING DYNAMIC ARRAY

class stackUsingDynamicArray{
    int *data; 
    int nextInd;
    int capacity;

    public:

    stackUsingDynamicArray(){
        data  = new int[2];
        nextInd = 0;
        capacity = 5;

    }

    int size(){
        return nextInd;
    }

    bool isEmpty(){
       return nextInd==0;
    }

    void push(int element){
        if(nextInd == capacity){
            int *newData = new int[2*capacity];
            for(int i = 0; i<capacity; i++){
                newData[i] = data[i];
            }
            capacity*=2;
            delete data;
            data = newData;
        }else{
        data[nextInd] =  element;
        cout<<data[nextInd]<<endl;
        nextInd++;
        
        }
    }

    int pop(){
        if(nextInd!=0){
        nextInd--;
        return data[nextInd];
        }else{
            cout<<"Stack is Empty ";
            return INT_MIN; 
        }
    }

     int top(){
        if(!isEmpty()){
        return data[nextInd-1];
        }else{
            cout<<"Stack is empty ";
            return INT_MIN;
        }
    }
};

template <typename T>
class stackUsingDynamicArrayTemp{
    T *data; 
    int nextInd;
    int capacity;

    public:

    stackUsingDynamicArrayTemp(){
        data  = new T[2];
        nextInd = 0;
        capacity = 5;

    }

    int size(){
        return nextInd;
    }

    bool isEmpty(){
       return nextInd==0;
    }

    void push(T element){
        if(nextInd == capacity){
            T *newData = new T[2*capacity];
            for(int i = 0; i<capacity; i++){
                newData[i] = data[i];
            }
            capacity*=2;
            delete data;
            data = newData;
        }else{
        data[nextInd] =  element;
        cout<<data[nextInd]<<endl;
        nextInd++;
        
        }
    }

    T pop(){
        if(nextInd!=0){
        nextInd--;
        return data[nextInd];
        }else{
            cout<<"Stack is Empty ";
            return INT_MIN; 
        }
    }

     int top(){
        if(!isEmpty()){
        return data[nextInd-1];
        }else{
            cout<<"Stack is empty ";
            return INT_MIN;
        }
    }

};


//  STACK USING LINKED LIST

class Node{
    public:
        int data;
        Node *next;

        Node(int data){
            this->data = data;
            next = NULL;
        }
};


class stackUsingNode{
    Node*head;
    int size;

    public:
        stackUsingNode(){
            head  = NULL;
            size=0;
        }

        int getSize(){
            return size;
        }

        void push(int element){
            Node  *newNode=new Node(element);
            newNode->next  = head;
            head = newNode;
            cout<<newNode->data<<endl;
            size++;
        }

        int  pop(){
            int ans = head->data;
            Node*temp = head;
            head = head->next;
            delete temp;
            size--;
            return ans;
        }

        int top(){
            return head->data;

        }

        bool isEmpty(){
            return head==NULL;
        }

};

int main(){

    // stackUsingDynamicArray s;
    // s.push(5);
    // s.push(10);
    // s.push(15);
    // s.push(20);
    // s.push(25);
    // cout<<s.pop()<<endl;
    // cout<<s.isEmpty()<<endl;
    // cout<<s.size()<<endl;

    // cout<<endl;

    // stackUsingDynamicArrayTemp<char> t;
    // t.push('r');
    // t.push('a');
    // t.push('m');
    // t.push('a');
    // t.push('a');
    // cout<<t.pop()<<endl;
    // cout<<t.isEmpty()<<endl;
    // cout<<t.size()<<endl;




    stackUsingNode l;
    l.push(5);
    l.push(10);
    l.push(15);
    l.push(20);
    l.push(25);
    cout<<l.pop()<<endl;
    cout<<l.isEmpty()<<endl;
    cout<<l.getSize()<<endl;


}