#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;

    node (int d, node* n){
        data = d;
        next = n;
    }

    node (int d){
        data = d;
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

bool search(node *head, int k){
    node* temp = head;
    while (temp != nullptr){
        if (temp->data == k) return true;
        temp = temp->next;
    }
    return false;
}

int main(){
    vector<int> nums = {0,1,2,3,4};

    node* ans = arrtoll(nums);

    bool pre = search(ans, 8);

    cout << pre;

    return 0;
}