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

node* arrtoll(vector<int>& nums){
    node* head = new node(nums[0]);
    node* mover = head;
    for (int i = 1; i < nums.size(); i++){
        node* temp = new node(nums[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traverse(node* head){
    node* temp = head;
    while (temp != nullptr){
        cout << temp->data;
        if (temp->next != nullptr) { 
            cout << " -> ";
        }
        temp = temp->next;
    }
    return;
}

int main(){
    vector<int> nums = {0,1,2,3,4};

    node* ans = arrtoll(nums);

    traverse(ans);

    return 0;
}