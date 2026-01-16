#include <iostream>
#include <string>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        int minLen = INT_MAX;
        string result = "";
        int s1_idx = 0;
        int s2_idx = 0;

        while (s1_idx < n) {
            if (s1[s1_idx] == s2[s2_idx]) {
                s2_idx++;
            }

            if (s2_idx == m) {
                int end = s1_idx;
                int check_s2 = m - 1;
                while (check_s2 >= 0) {
                    if (s1[end] == s2[check_s2]) {
                        check_s2--;
                    }
                    end--;
                }
                int start = end + 1;
                int currentLen = s1_idx - start + 1;
                if (currentLen < minLen) {
                    minLen = currentLen;
                    result = s1.substr(start, minLen);
                }
                s1_idx = start + 1;
                s2_idx = 0;
            } else {
                s1_idx++;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    string s1 = "abcdebdde";
    string s2 = "bde";
    cout << sol.minWindow(s1, s2) << endl;

    string s3 = "jmeqsiwvaovvnbstl";
    string s4 = "u";
    cout << sol.minWindow(s3, s4) << endl;

    string s5 = "fhhjkeejkdjjs";
    string s6 = "jkj";
    cout << sol.minWindow(s5, s6) << endl;

    return 0;
}