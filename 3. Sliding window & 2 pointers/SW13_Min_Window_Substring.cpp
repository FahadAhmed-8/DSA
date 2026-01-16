#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0;
        int n = s.length(), m = t.length();
        int cnt = 0, sindex = -1, minlens = INT_MAX;
        int hash[256] = {0};
        
        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }
        
        while (right < n) {
            if (hash[s[right]] > 0) cnt++;
            hash[s[right]]--;
            
            while (cnt == m) {
                if (minlens > right - left + 1) {
                    minlens = right - left + 1;
                    sindex = left;
                }
                hash[s[left]]++;
                if (hash[s[left]] > 0) cnt--;
                left++;
            }
            right++;
        }
        
        if (sindex == -1) return "";
        return s.substr(sindex, minlens);
    }
};

int main() {
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << sol.minWindow(s, t) << endl;
    return 0;
}