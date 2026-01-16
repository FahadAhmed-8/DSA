#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        int maxlens = 0;
        int n = fruits.size();
        unordered_map<int,int> map;

        while (right < n) {
            map[fruits[right]]++;
            if (map.size() > 2){
                while (map.size() > 2){
                    map[fruits[left]]--;
                    if (map[fruits[left]] == 0) map.erase(fruits[left]);
                    left++;
                }
            }
            maxlens = max(maxlens, right - left + 1);
            right++;
        }
        return maxlens;
    }
};

int main() {
    Solution sol;
    vector<int> fruits = {1, 2, 3, 2, 2};
    cout << sol.totalFruit(fruits) << endl;
    return 0;
}