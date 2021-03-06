#include<bits/stdc++.h>
using namespace std;

// #define n 20

class MyQueue{
    int* arr;
    int front;
    int back;
    int n = 20;

public: 
     void queue(){
        arr=new int[n];
        front=-1;
        back=-1;
     }
    void push(int x){
        if(back == n-1){
            cout<<"Queue overflow"<<endl;
            return;
        }
        back++;
        arr[back]=x;
        if(front == -1){
            front++;
        }
    }
    void pop(){
       if(front == -1 || front > back){
           cout<<"No elements in the queue"<<endl;
           return;
       }
       front++;
    }
    int peek(){
        if(front == -1 || front > back){
           cout<<"No elements in the queue"<<endl;
           return -1;
       }
       return arr[front];
    }
    bool empty(){
         if(front == -1 || front > back){
           return true;
       }
       return false;
    }
};

int main(){
    
    MyQueue a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.pop();

    cout<<a.peek()<<endl;
    cout<<a.empty()<<endl;

    return 0;
}