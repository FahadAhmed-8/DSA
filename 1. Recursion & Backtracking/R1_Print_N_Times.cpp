#include <bits/stdc++.h>
using namespace std;

void callname (int i, int n) {
    if (i >= n) return;
    cout << i + 1 << ". Fahad" << endl;
    callname (i+1, n);
}

int main (){
    int n;
    cout << "Enter number: ";
    cin >> n;
    callname (0, n);
    return 0;
}