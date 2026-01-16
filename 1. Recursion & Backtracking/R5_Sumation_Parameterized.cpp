#include <bits/stdc++.h>
using namespace std;

void sum (int i, int n) {
    if (i < 0){
        cout << n;
        return;
    } 
    sum(i-1, n + i);
}

int main (){
    int n;
    cout << "Enter number: ";
    cin >> n;
    sum (n, 0);
    return 0;
}