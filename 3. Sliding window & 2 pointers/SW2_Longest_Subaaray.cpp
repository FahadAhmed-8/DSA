// longest subaaray with sum <= k
#include<bits/stdc++.h>
using namespace std;

int sliding_window_sum(vector<int>& arr, int k){
    int n = arr.size();
    int l = 0, r = 0;
    int curr_sum = 0;
    int max_lens = 0;
    while ( r < n ){
        curr_sum += arr[r];
        if ( curr_sum > k){
            curr_sum -= arr[l];
            l++;
        }
        if (curr_sum <=k ){
            max_lens = max(max_lens, r - l + 1);
        }
        r++;
    }
    return max_lens;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;

    int max = sliding_window_sum(arr, k);

    cout<<max<<endl;

    return 0;
}