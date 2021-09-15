#include<iostream>
using namespace std;
    int N = 100;
    int a[N], tree[4*N];
    
    void build(int node, int st, int en){
        if (st == en){
            tree[node] = a[st];
            return;
        }
        int mid = (st + en)/2;
        build(2*node, st, mid);
        build(2*node, mid+1, en);
        
        tree[node] = tree[2*node] + tree[2*node + 1];
    }

int main(){
    int n;
    cout<<"Enter the number of elements in the array"<<endl;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i]<<endl;
    }
    build(1, 0, n-1);
    for(int j = 0; j < 2n-1; j++){
        cout<<tree[i]<<endl;
    }
    return 0;
}
