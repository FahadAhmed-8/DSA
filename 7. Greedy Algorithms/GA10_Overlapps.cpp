#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comparision(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& meeting) {
        int n = meeting.size();
        sort(meeting.begin(), meeting.end(), comparision);
        int cnt = 1;
        int lastmeet = meeting[0][1];
        for (int i = 0; i < n; i++){
            if (meeting[i][0] >= lastmeet){
                cnt++;
                lastmeet = meeting[i][1];
            }
        }
        
        return n - cnt;
    }
};