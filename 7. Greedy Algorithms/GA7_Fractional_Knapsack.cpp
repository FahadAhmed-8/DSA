#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    struct sack{
        int val;
        int wt;
    };
    
    static bool comparison(const sack &a, const sack &b) {
        return (double)a.val / a.wt > (double)b.val / b.wt;
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        double ans = 0.0;
        int n = val.size();
        
        vector<sack> S;
        
        for (int i = 0; i < n; i++) {
            S.push_back({val[i], wt[i]});
        }

        
        sort(S.begin(), S.end(), comparison);
        
        for (int i = 0; i < n && capacity > 0; i++){
            if (capacity >= S[i].wt) {
                ans += S[i].val;
                capacity -= S[i].wt;
            } else {
                ans += (double)S[i].val * capacity / S[i].wt;
                capacity = 0;
            }
        }
        return ans;
    }
};
