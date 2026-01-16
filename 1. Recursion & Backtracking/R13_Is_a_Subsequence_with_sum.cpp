// In base case just check 
// if condition full filled return true 
// if condition not full filled return false 
#include <bits/stdc++.h>
using namespace std;


bool print_subsequence(vector<int>& curr, int k, const vector<int>& arr, int index) {
    if (index == arr.size()) {
        if (k == 0) {
            return true;
        }
        else return false;
    }

    curr.push_back(arr[index]);
    k -= arr[index];
    if(print_subsequence(curr, k, arr, index + 1) == true){
        return true;
    }

    k += arr[index];
    curr.pop_back(); 
    if(print_subsequence(curr, k, arr, index + 1) == true){
        return true;
    }
    return false;
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
    if(print_subsequence(curr, target_sum, arr, 0) == true){
        cout << "Found a subsequence with the given sum: { ";
        for(int x : curr){
            cout << x << " ";
        }
        cout << "}" << endl;
    }
    else{
        cout << "No subsequence found with the given sum." << endl;
    }

    return 0;
}