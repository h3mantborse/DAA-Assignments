#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define MOD 1000000007;

template<typename T>
class queueUsingArray{
    
    T *data;
    int nextIdx;
    int firstIdx;
    int size;
    int totalSize;

public:
    queueUsingArray(int s){
        data = new T[s];
        nextIdx =  0;
        firstIdx = -1;
        size  = 0;
        totalSize=s;
        
    }


    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size==0;
    }

    // insert an element

    void enqueue(T ele){
        if(size!=totalSize){
        data[nextIdx] = ele;
        cout<<data[nextIdx]<<" ";
        nextIdx =( nextIdx+1) % totalSize;
        if(firstIdx==-1)
            firstIdx=0;
        size++;}
        else{
            cout<<"Queue is full";
            return;
        }
    }

    T front(){
    
        if(isEmpty()){
            cout<<"Queue is empty";
            return 0;
        }
        else{
        return data[firstIdx];
        }
    }
    

    T dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty";
            return 0;
        }else{
            T ans = data[firstIdx];
            firstIdx=(firstIdx+1)%totalSize;
            size--;
            return ans;
        }
        if(size==0){
            firstIdx=-1;
            nextIdx=0;
        }
    }

};


// DYNAMIC QUEUE

template<typename V>
class queueUsingArrayDy{
    
    V *data;
    int nextIdx;
    int firstIdx;
    int size;
    int totalSize;

public:
    queueUsingArrayDy(int s){
        data = new V[s];
        nextIdx =  0;
        firstIdx = -1;
        size  = 0;
        totalSize=s;
        
    }


    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size==0;
    }

    // insert an element

    void enqueue(V ele){
        if(size!=totalSize){
        data[nextIdx] = ele;
        cout<<data[nextIdx]<<" ";
        nextIdx =( nextIdx+1) % totalSize;
        if(firstIdx==-1)
            firstIdx=0;
        size++;}
        else{
            V *newData = new V[2*totalSize];
            int j = 0;
            for(int i = firstIdx; i<totalSize; i++){
                newData[j]=data[i];
                j++;
            }
            for(int i = 0; i<firstIdx; i++){
                newData[j]=data[i];
                j++;
            }
            delete [] data;
            data= newData;
            firstIdx=0;
            nextIdx=totalSize;
        }
    }

    V front(){
    
        if(isEmpty()){
            cout<<"Queue is empty";
            return 0;
        }
        else{
        return data[firstIdx];
        }
    }
    

    V dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty";
            return 0;
        }else{
            V ans = data[firstIdx];
            firstIdx=(firstIdx+1)%totalSize;
            size--;
            return ans;
        }
        if(size==0){
            firstIdx=-1;
            nextIdx=0;
        }
    }

};

int main(){
    queueUsingArrayDy<int> q(1);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(73);
    q.enqueue(5);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(8);
    q.enqueue(65);
    cout<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.front()<<endl;
    cout<<q.isEmpty()<<endl;

}