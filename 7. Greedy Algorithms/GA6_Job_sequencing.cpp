// without dsu
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    struct Job {
        int id;
        int deadline;
        int profit;
    };

    static bool comparison(const Job &a, const Job &b) {
        return (a.profit > b.profit);
    }
    
  
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        vector<Job> jobs(n);
    
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            jobs[i] = {i + 1, deadline[i], profit[i]};
            maxDeadline = max(maxDeadline, deadline[i]);
        }
        
        sort(jobs.begin(), jobs.end(), comparison);

        
        vector<int> slot(maxDeadline + 1, -1);
    
        int countJobs = 0, totalProfit = 0;
    
        for (int i = 0; i < n; i++) {
            for (int j = jobs[i].deadline; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = jobs[i].id; 
                    countJobs++;
                    totalProfit += jobs[i].profit;
                    break; 
                }
            }
        }
    
        return {countJobs, totalProfit};
        }
};