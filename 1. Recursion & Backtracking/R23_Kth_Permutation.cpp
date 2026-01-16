#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> nums;
        int fact = 1;
        for (int i = 1; i < n; i++){
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k = k - 1;
        while(true){
            ans = ans + to_string(nums[k / fact]);
            nums.erase(nums.begin() + k / fact);
            if(nums.size() == 0) break;
            k = k % fact;
            fact = fact / nums.size(); 
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int n = 4;
    int k = 9;

    string result = solution.getPermutation(n, k);
    cout << result << endl;

    return 0;
}