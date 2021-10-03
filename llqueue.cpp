#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class node{
  public:
  int data;
  node* next;

  node(int val){
      data=val;
      next=NULL;
  }
};

class queue{
    node* front;
    node* back;

    public: 
    void queue(){
        front=NULL;
        back=NULL;
    }
    void push(int x){
        node* n = new node(x);
        if(front==NULL){
            back=n;
            front=n;
            return;
        }
        back->next=n;
        back=n;
    }
    void pop(){
        if(front==NULL){
            cout<<"Queue empty"<<endl;
            return;
        }
        node* toDelete = front;
        front=front->next;
        
        delete toDelete;
    }

    int peek(){
        if(front==NULL){
            cout<<"Queue empty"<<endl;
            return;  
        }
        return front->data;
    }
    bool empty(){
        if(front==NULL){
            return true;  
        }
        return false;
    }
};
int main(){
    queue a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.pop();

    cout<<a.peek()<<endl;
    cout<<a.empty()<<endl;
    return 0;
}