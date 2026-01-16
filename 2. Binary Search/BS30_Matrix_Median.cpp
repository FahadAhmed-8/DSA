#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int f(int mid, int n, vector<vector<int>> &mat){
        int cnt = 0;
        for (int i = 0; i < n; i++){
            cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
        }
        return cnt;
    }
  
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
       
        int minVal = INT_MAX, maxVal = INT_MIN;
       
        for (int i = 0; i < n; i++) {
            if (mat[i][0] < minVal)
                minVal = mat[i][0];
            if (mat[i][m - 1] > maxVal)
                maxVal = mat[i][m - 1];
        }
        int low = minVal, high = maxVal;
        int req = (n * m) / 2;
       
        while (low <= high){
            int mid = low + (high - low) / 2;
            int smallerEqual = f(mid, n, mat);
            if (smallerEqual <= req){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    int result = sol.median(mat);
    cout << result << endl;

    return 0;
}