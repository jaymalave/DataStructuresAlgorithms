#include<bits/stdc++.h>
using namespace std;

class node{
    public: 
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

//inserting an element at the end
void insertAtTail(node* &head, int val){
   node* n = new node(val);

   if(head == NULL){
       head = n;
       return;
   }
   node* temp = head;
   while(temp->next != NULL){
       temp = temp->next;
   }
   temp->next = n;
}

//displaying the linked list
void display(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

//inserting at head
void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

//search an element
bool search(node* &head, int key){
   node* temp = head;
   while(temp != NULL){
       if (temp->data == key){
           return true;
       }
       temp=temp->next;
   }
   return false;
}

//deleting an element at head
void deleteAtHead(node* &head){
   node* toDelete = head;
   head = head->next;
   delete toDelete;
}

//deleting an element at any position
void deletion(node* &head, int val){

    //adding base cases
    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        deleteAtHead(head);
        return;
    }

    node* temp=head;
    while(temp->next->data != val){
        temp=temp->next;
    }
    node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

//reversing a linked list-iterative way
node* reverseIter(node* &head){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

//reversing a linked list-recursive way
node* reverseRecur(node* &head){
   //adding base cases
   if(head == NULL || head->next == NULL){
       return head;
   }
   node* newhead = reverseRecur(head->next);
   head->next->next = head;
   head->next = NULL;
   return newhead;
}

//revering k nodes
node* reversek(node* &head, int k){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    int count = 0;
    while(currptr != NULL && count<k){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }
    if(nextptr != NULL){
        head->next = reversek(nextptr, k);
    }
    return prevptr;
}

int main(){
    cout<<"Linked List Program"<<endl;
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    // deletion(head, 3);
    // reverseIter(head);
    //reverseRecur(head);
    reversek(head, 2);
    display(head);
    if (search(head, 3) == true){
        cout<<'1'<<endl;
    }else {
        cout<<'0'<<endl;
    }
    return 0;
}