#include <bits/stdc++.h>
using namespace std;

void fact (int i, int n) {
    if (i == 0){
        cout << n;
        return;
    } 
    fact(i-1, n * i);
}

int main (){
    int n;
    cout << "Enter number: ";
    cin >> n;
    fact (n, 1);
    return 0;
}
