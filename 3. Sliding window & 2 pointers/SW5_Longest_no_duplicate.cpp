#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int maxlens = 0;
        int left = 0;
        int right = 0;
        while ( right < s.length()){
            if (map.find(s[right]) != map.end()){
                left = max(left, map[s[right]] + 1);
            }
            map[s[right]] = right;
            maxlens = max(maxlens, right - left + 1);
            right++;
        }
        return maxlens;
    }
};

int main() {
    Solution sol;
    string s = "abcabcbb";
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}