#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        long long wt = 0;
        sort(bt.begin(), bt.end());
        
        long long t = 0;
        for (int i = 0; i < bt.size(); i++){
            wt += t;
            t += bt[i];
        }
        long long n = bt.size();
        
        return wt / (n);
    }
};