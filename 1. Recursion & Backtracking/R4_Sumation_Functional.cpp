#include <bits/stdc++.h>
using namespace std;

int sum (int n) {
    if (n == 0){
        return 0;
    }
    return n + sum (n - 1);
}

int main (){
    int n, ans;
    cout << "Enter number: ";
    cin >> n;
    ans = sum (n);
    cout << "Sum is: " << ans << endl;
    return 0;
}

