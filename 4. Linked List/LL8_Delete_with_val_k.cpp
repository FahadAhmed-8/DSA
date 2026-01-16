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

Node* deletenodewithval(Node*head, int k){
    if (head == nullptr) return nullptr;
    Node* temp = head;
    if (head->data==k){
        head = head->next;
        delete temp;
        return head;
    }
    Node* prev = nullptr;
    while (temp != nullptr){
        if (temp->data == k){
            prev->next = prev->next->next;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    Node* head= arrtoll(arr);
    head = deletenodewithval(head, 7);
    printll(head);
    return 0;
}

