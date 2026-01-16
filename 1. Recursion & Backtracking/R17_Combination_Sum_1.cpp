#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void combination_sum(int ind, int k, vector<int>& curr, vector<vector<int>>& ans, vector<int>& can){
        if (k == 0) {
            ans.push_back(curr);
            return;
        }

        if (ind == can.size()) {
            return;
        }

        if (can[ind] <= k) {
            curr.push_back(can[ind]);
            combination_sum(ind, k - can[ind], curr, ans, can);
            curr.pop_back();
        }
        combination_sum(ind + 1, k, curr, ans, can);
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> current;

        combination_sum(0, target, current, answer, candidates);

        return answer;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> candidates(n);
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }

    int target;
    cin >> target;

    Solution sol;
    vector<vector<int>> result = sol.combinationSum(candidates, target);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j < result[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}