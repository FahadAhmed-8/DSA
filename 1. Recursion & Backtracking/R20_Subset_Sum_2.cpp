#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void ss2(int ind, vector<int>& curr, vector<vector<int>>& ans, vector<int>& can){
        ans.push_back(curr);

        for(int i = ind; i < can.size(); i++){
            if(i > ind && can[i] == can[i-1]) continue;
            curr.push_back(can[i]);
            ss2(i+1,curr,ans,can);
            curr.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        vector<int> current;

        ss2(0, current, answer, nums);

        return answer;        
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};
    
    vector<vector<int>> result = sol.subsetsWithDup(nums);

    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}