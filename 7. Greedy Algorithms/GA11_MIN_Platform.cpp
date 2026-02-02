#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // static bool comparision(vector<int>& a, vector<int>& b){
    //     return a[1] < b[1];
    // }
  
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int ans = 0, cnt = 0;
        int i = 0, j = 0;
        
        while (i < arr.size() && j < dep.size()){
            if (arr[i] <= dep[j]){
                cnt++;
                i++;
            }
            else {
                cnt--;
                j++;
            }
            ans = max(ans, cnt);
        }
        
        return ans;
        // vector<vector<int>> train;
        // int n = arr.size();
        
        // for (int i = 0; i < arr.size(); i++){
        //     train.push_back({arr[i], dep[i]});
        // }
        
        // sort(train.begin(), train.end(), comparision);
        
        // vector<int> last_train;
        // last_train.push_back(dep[1]);
        // int platform = 1;
        
        // for (int i = 1; i < n; i++){
        //     for (int j = 0; j < last_train.size(); j++){
        //         if (train[i][1] <= last_train[j]){
        //             platform++;
        //             last_train.push_back(train[i][1]);
        //         } else if (train[i][1] > last_train[j]) {
        //             last_train[j] = train[i][1];
        //         }
        //     }
        // }
        // return platform;
    }
};
