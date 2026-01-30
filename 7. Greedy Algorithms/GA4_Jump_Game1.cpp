#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxjump = 0;
        int currjump = 0;
        for (int i = 0; i < nums.size(); i++){
            if (i > maxjump){
                return false;
            }
            currjump = i + nums[i];
            maxjump = max(maxjump, currjump); 
        }

        return true;
    }
};