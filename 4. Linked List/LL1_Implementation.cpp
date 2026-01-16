#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;

    node (int data1, node* next1){
        data = data1;
        next = next1;
    }

    node (int data1){
        data = data1;
        next = nullptr;
    }
};

int main(){
    node* y = new node(4, nullptr);

    cout << y << " "<< y->data; 

    return 0;
}
