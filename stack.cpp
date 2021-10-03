#include<bits/stdc++.h>
using namespace std;

#define n 100

class stack(){
    int* arr;
    int top;

    public:
    stack(){
        arr=new in[n];
        top=-1;
    }

    void push(int x){
        if(top == n-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop(){
        if(top == -1){
            cout<<"Stack empty"<<endl;
            return;
        }
        top--;
    }

    int topVal(){
        if(top == -1){
            cout<<"Stack empty"<<endl;
            return;
        }
        return arr[top];
    }
    bool empty(){
        return top==-1;
    }
};

int main(){
    MyStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    cout<<st.topVal()<<endl;
    cout<<st.empty()<<endl;
    return 0;
}