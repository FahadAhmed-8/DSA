#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxfreq = 0, maxlens = 0;
        int left = 0, right = 0;
        int n = s.length();
        int hash[26] = {0};
        while (right < n) {
            hash[s[right] - 'A']++;
            maxfreq = max(maxfreq, hash[s[right] - 'A']);
            if ((right - left + 1) - maxfreq > k) {
                hash[s[left] - 'A']--;
                left++;
            }
            maxlens = max(maxlens, right - left + 1);
            right++;
        }
        return maxlens;
    }
};

int main() {
    Solution sol;
    string s = "AABABBA";
    int k = 1;
    cout << sol.characterReplacement(s, k) << endl;
    return 0;
}