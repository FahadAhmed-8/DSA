#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findmaxelement(int mid, vector<vector<int>>& mat) {
        int maxVal = -1;
        int maxRow = -1;
        for (int i = 0; i < mat.size(); i++) {
            if (mat[i][mid] > maxVal) {
                maxVal = mat[i][mid];
                maxRow = i;
            }
        }
        return maxRow;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int row = findmaxelement(mid, mat);
            int leftIsSmaller = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
            int rightIsSmaller = (mid + 1 < m) ? mat[row][mid + 1] : -1;
            int currentVal = mat[row][mid];
            if (currentVal > leftIsSmaller && currentVal > rightIsSmaller) {
                return {row, mid};
            } else if (leftIsSmaller > currentVal) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };

    vector<int> result = sol.findPeakGrid(mat);
    
    if (result[0] != -1) {
        cout << result[0] << " " << result[1] << endl;
    } else {
        cout << "No peak found" << endl;
    }

    return 0;
}