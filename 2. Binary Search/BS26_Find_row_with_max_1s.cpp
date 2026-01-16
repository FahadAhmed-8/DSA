#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int f(vector<int>& nums){
        int n = nums.size();
        int x = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        return n - x;
    }

    int rowWithMax1s(vector<vector<int>> &arr) {
        int maxCount = 0;
        int rowIndex = -1;

        for (int i = 0; i < arr.size(); i++){
            int count = f(arr[i]);
            if (count > maxCount){
                maxCount = count;
                rowIndex = i;
            }
        }
        return rowIndex;
    }
};

int main() {
    Solution s;
    vector<vector<int>> arr = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    cout << s.rowWithMax1s(arr) << endl;

    return 0;
}