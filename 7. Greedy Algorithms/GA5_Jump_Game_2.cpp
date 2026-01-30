#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int left = 0;
        int right= 0;
        int jump = 0;
        int n = nums.size();
        while (right < n - 1){
            int farthest = right;
            for (int i = left; i <= right; i++){
                farthest = max(i + nums[i], farthest);
            }
            left = right + 1;
            jump++;
            right = farthest;
        }
        return jump;
    }
};