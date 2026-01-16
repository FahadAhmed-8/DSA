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

Node* insertBeforeValue(Node* head, int k, int val) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->data == k) {
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        if (temp->next->data == k) {
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head= arrtoll(arr);
    head = insertBeforeValue(head, 3, 2);
    printll(head);
    return 0;
}

