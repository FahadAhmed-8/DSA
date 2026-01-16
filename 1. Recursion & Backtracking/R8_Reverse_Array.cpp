#include <bits/stdc++.h>
using namespace std;

void swap (int i, int j, int arr[]){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void reverse (int i, int n, int arr[]) {
    if (i >= n/2) return;
    swap(i ,n - 1 - i , arr);
    reverse (i + 1, n, arr);
}

int main() {
    int n;
    cout << "Enter the lenght of the Array: ";
    cin >> n;

    
    int arr[n];
    for (int i = 0; i < n; i++){
        cout << "Enter the " << i + 1 << " element of array: ";
        cin >> arr[i];
    } 

    reverse (0, n, arr);

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}