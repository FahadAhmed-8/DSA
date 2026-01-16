#include <bits/stdc++.h>
using namespace std;

void call (int i, int n){
    if (i >= n) return;
    call (i+1, n);
    cout << i + 1 << ". Fahad" << endl;
}

int main () {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    call(0, n);
    return 0;
}
