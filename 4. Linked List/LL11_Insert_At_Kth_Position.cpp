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

Node* insertatpos(Node* head, int k, int d){
    Node* newnode = new Node(d);
    if (head == nullptr) return newnode;
    if (k == 1){
        newnode->next = head;
        return head;
    }
    Node* temp = head;
    int cnt = 1;
    while (temp != nullptr && cnt < k -1){
        temp = temp->next;
        cnt++;
    }
    if(temp != nullptr){
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head= arrtoll(arr);
    head = insertatpos(head, 3, 100);
    printll(head);
    return 0;
}

