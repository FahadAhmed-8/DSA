#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  private:
    void ss(int ind, int sum, vector<int>& ans,vector<int>& arr){
        if(ind == arr.size()) {
            ans.push_back(sum);
            return;
        }
        
        ss(ind + 1, sum + arr[ind], ans, arr);
        ss(ind + 1, sum, ans, arr);
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> ans;
        int sum = 0;
        ss(0, sum, ans, arr);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 3}; 

    vector<int> result = sol.subsetSums(arr);

    sort(result.begin(), result.end());

    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}