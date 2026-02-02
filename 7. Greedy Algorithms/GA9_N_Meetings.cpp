#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool comparision(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        if (n == 0) return 0;
        vector<vector<int>> meeting;
        
        for (int i = 0; i < n; i++){
            meeting.push_back({start[i], end[i]});
        }
        
        sort(meeting.begin(), meeting.end(), comparision);
        int cnt = 1;
        int lastmeet = meeting[0][1];
        for (int i = 0; i < n; i++){
            if (meeting[i][0] > lastmeet){
                cnt++;
                lastmeet = meeting[i][1];
            }
        }
        
        return cnt;
        
        // Combine both the vectors with index also
        // sort using ending time
        // last ending < start[i] add it to ds
        
    }
};