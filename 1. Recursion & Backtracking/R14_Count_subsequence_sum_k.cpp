// Types of Recursion
// 1. Print All
// 2. Sum
// 3. Count

// for count

// base case
//     if yes return 1
//     if no return 0

// left case
// right case

// return left + right


#include <bits/stdc++.h>
using namespace std;

int print_subsequence(vector<int>& curr, int k, const vector<int>& arr, int index) {
    if (index == arr.size()) {
        if (k == 0) {
            return 1;
        }
        else {
            return 0;
        }
    }

    curr.push_back(arr[index]);
    k -= arr[index];
    int l = print_subsequence(curr, k, arr, index + 1);

    k += arr[index];
    curr.pop_back(); 
    int r = print_subsequence(curr, k, arr, index + 1);

    return l + r;
}


int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);  

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target_sum;
    cout << "Enter the target sum: ";
    cin >> target_sum;  


    vector<int> curr;
    int ans = print_subsequence(curr, target_sum, arr, 0);
    cout << "Total Subsequences with sum " << target_sum << " are: " << ans << endl;

    return 0;
}

