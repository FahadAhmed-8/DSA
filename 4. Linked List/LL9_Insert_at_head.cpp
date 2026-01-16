#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }

    Node(int d, Node* n){
        data = d;
        next = n;
    }
};

Node* arrtoll(vector<int> arr){
    if(arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* curr = head;

    for (int i= 1; i < arr.size(); i++){
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }

    return head;
}

void printll(Node* head){
    Node* curr = head;
    while(curr != nullptr){
        cout<<curr->data<<" -> ";
        curr = curr->next;
    }
    cout<<"nullptr"<<endl;
}

Node* insertathead(Node* head, int k){
    Node* temp = new Node(k, head);
    head = temp; 
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head= arrtoll(arr);
    head = insertathead(head, 7);
    printll(head);
    return 0;
}

