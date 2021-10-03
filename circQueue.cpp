#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define n 25

class CircularQueue{
    int* arr;
    int front;
    int rear;

    public: 
     CircularQueue(){
         arr = new int[n];
         front=-1;
         rear=-1;
     }
     void enqueue(int x){
        if((front == 0 && rear == -1) || (front == rear + 1)){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        if(front == -1){
            front = 0;
            rear = 0;
        }
        else if(rear == n-1){
               rear = 0;
           }
        else{
               rear += 1;
           }
        arr[rear] = x;
        }
     void dequeue(){
         if (front == -1){
             cout<<"Queue empty"<<endl;
             return;
         }
         cout<<"the element deleted is "<<arr[front]<<endl;
         if(front == rear){
             front = -1;
             rear = -1;
         }
         else if(front == n-1){
             front = 0;
         }
         else{
             front += 1;
         }
     }
     bool isEmpty(){
         if (front == -1){
             return true;
         }
         return false;
     }
     };

int main(){
    CircularQueue cq;
    cq.enqueue(2);
    cq.enqueue(4);
    cq.enqueue(6);
    cq.dequeue();
    cout<<cq.isEmpty()<<endl;

    return 0;
}
       

