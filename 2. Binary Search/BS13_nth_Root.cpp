#include <iostream>

using namespace std;

class Solution {
public:
    int compare(int mid, int n, int m) {
        long long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = ans * mid;
            if (ans > m) return 2;
        }
        if (ans == m) return 1;
        return 0;
    }

    int nthRoot(int n, int m) {
        if (m == 0) return 0;
        if (m == 1) return 1;

        int low = 1;
        int high = m;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int check = compare(mid, n, m);

            if (check == 1) {
                return mid;
            } else if (check == 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    
    cout << sol.nthRoot(3, 27) << endl; 
    cout << sol.nthRoot(4, 69) << endl; 
    cout << sol.nthRoot(2, 9) << endl;

    return 0;
}