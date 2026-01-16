#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void cs2(int ind, int k, vector<int>& curr, vector<vector<int>>& ans, vector<int>& can){
        if (k == 0){
            ans.push_back(curr);
            return;
        }

        if (ind == can.size()) return;

        for(int i = ind; i < can.size(); i++){
            if(i > ind && can[i] == can[i-1]) continue;
            if(can[i] > k) break;
            curr.push_back(can[i]);
            cs2(i+1,k-can[i],curr,ans,can);
            curr.pop_back();
        }

    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        vector<vector<int>> ans;

        cs2(0, target, curr, ans, candidates);

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> result = sol.combinationSum2(candidates, target);

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