#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& rat) {
        int n = rat.size();
        int candies = n;
        int i = 1;

        while (i < n){
            if (rat[i] == rat[i - 1]){
                i++;
                continue;
            }
            int peak = 0;
            while (i < n && rat[i] > rat[i - 1]){
                peak++;
                candies += peak;
                i++;
            }
            int valley = 0;
            while (i < n && rat[i] < rat[i - 1]){
                valley++;
                candies += valley;
                i++;
            }
            candies -= min(peak, valley);
        }
        return candies;
    }
};