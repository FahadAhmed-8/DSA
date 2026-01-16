#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right){
    int l = left;
    int r = mid + 1;
    vector<int> temp;
    while (l <= mid && r <= right) {
        if (arr[l] <= arr[r]) {
            temp.push_back(arr[l]);
            l++;
        } else {
            temp.push_back(arr[r]);
            r++;
        }
    }
    while (l <= mid) {
        temp.push_back(arr[l]);
        l++;
    }
    while (r <= right) {
        temp.push_back(arr[r]);
        r++;
    }
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i - left];
    }
}

void merge_sort(vector<int>& arr, int left, int right) {
    if (left >= right){ 
        return;
    }

    int mid = (left + right) / 2;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    merge(arr, left, mid, right);
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

    merge_sort(arr, 0, n - 1);

    cout << "Sorted array is:\n";
    for (int i = 0; i < n; i++) {   
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}