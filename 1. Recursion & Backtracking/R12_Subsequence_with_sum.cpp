//all subsequences with sum K
#include <bits/stdc++.h>
using namespace std;

void print_arr(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
}

void print_subsequence(vector<int>& curr, int k, const vector<int>& arr, int index) {
    if (index == arr.size()) {
        if (k == 0) {
            cout << "{ ";
            print_arr(curr);
            cout << "}" << endl;
        }
        return;
    }

    curr.push_back(arr[index]);
    k -= arr[index];
    print_subsequence(curr, k, arr, index + 1);

    k += arr[index];
    curr.pop_back(); 
    print_subsequence(curr, k, arr, index + 1);
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
    print_subsequence(curr, target_sum, arr, 0);

    return 0;
}