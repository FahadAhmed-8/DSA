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

int main(){
    vector<int> nums = {0,1,2,3,4};

    node* ans = arrtoll(nums);

    cout << ans << endl;

    return 0;
}