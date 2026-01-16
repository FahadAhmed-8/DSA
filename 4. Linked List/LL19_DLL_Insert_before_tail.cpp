#include<bits/stdc++.h>
using namespace std;

struct dll{
    int data;
    dll* next;
    dll* prev;

    dll(int k){
        data = k;
        next = nullptr;
        prev = nullptr;
    }

    dll(int k, dll* n, dll* p){
        data = k;
        next = n;
        prev = p;

    }

    dll(int k, dll* p){
        data = k;
        next = nullptr;
        prev = p;
    }
};

dll* convert(vector<int> arr){
    dll* head = new dll(arr[0]);
    dll* mover = head;
    for (int i = 1; i < arr.size(); i++){
        dll* curr = new dll(arr[i],mover);
        mover->next = curr;
        mover = mover->next;
    }
    return head;
}

void printdll(dll* head){
    dll* temp = head;
    while (temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp -> next;
    }
    cout << "nullptr.";
}

dll* insertAtTail(dll* head, int k) {
    dll* newnode = new dll(k);
    if (head == nullptr) {
        return newnode;
    }
    dll* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }    
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    dll* head = convert(nums);
    head = insertAtTail(head, 100);
    printdll(head);
    return 0;
}