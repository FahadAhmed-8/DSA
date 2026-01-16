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

dll* insertAtKth(dll* head, int k, int val) {
    if (head == nullptr) {
        if (k == 1) return new dll(val);
        return nullptr;
    }
    if (k == 1) {
        dll* newNode = new dll(val, head, nullptr);
        head->prev = newNode;
        return newNode;
    }
    dll* temp = head;
    int cnt = 1;
    while (temp != nullptr && cnt < k) {
        temp = temp->next;
        cnt++;
    }
    if (temp == nullptr) {
        if (cnt == k) {
            dll* last = head;
            while (last->next != nullptr) last = last->next;
            dll* newNode = new dll(val, nullptr, last);
            last->next = newNode;
            return head;
        }
        return head;
    }
    dll* back = temp->prev;
    dll* newNode = new dll(val, temp, back);
    back->next = newNode;
    temp->prev = newNode;
    return head;
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    dll* head = convert(nums);
    head = insertAtKth(head, 2, 100);
    printdll(head);
    return 0;
}