//stack implementation using linked list
#include<iostream>
#include<bits/stdc++.h>
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

class stack{
    node* top;

    public: 
     void stack(){
         top=NULL;
     }
     void push(int x){
         node* n = new node(x); 
         if(top==NULL){
             top=n;
             return;
         }
         top->next=n;
         top=n;
     }
     void pop(){}
     int topVal(){
         if(top==NULL){
             cout<<"Stack empty"<<endl;
             return;
         }
         return top->data;
     }
     bool empty(){
         if(top == NULL){
             return true;
         }
         return false;
     }
};

int main(){

    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    cout<<st.topVal()<<endl;
    cout<<st.empty()<<endl;

    return 0;
}