//leetcode 1423: Maximum Points You Can Obtain from Cards
#include <iostream>
#include <vector>
#include <algorithm> // Required for max

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0, rsum = 0, maxSum = 0;
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }
        maxSum = lsum;
        int rindex = cardPoints.size() - 1;
        for (int i = k - 1; i >= 0; i--) {
            lsum -= cardPoints[i];
            rsum += cardPoints[rindex];
            rindex--;
            maxSum = max(maxSum, lsum + rsum);
        }
        return maxSum;
    }
};

int main() {
    // Example Test Case
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    Solution sol;
    int result = sol.maxScore(cardPoints, k);

    cout << "Max Score: " << result << endl;

    return 0;
}