#include <bits/stdc++.h>
using namespace std;

void print_arr(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
}

void print_subsequence(vector<int>& curr, const vector<int>& arr, int index) {
    if (index == arr.size()) {
        cout << "{ ";
        print_arr(curr);
        cout << " }" << endl;
        return;
    }

    curr.push_back(arr[index]);
    print_subsequence(curr, arr, index + 1);

    curr.pop_back(); 
    print_subsequence(curr, arr, index + 1);
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

    vector<int> curr;
    print_subsequence(curr, arr, 0);

    return 0;
}