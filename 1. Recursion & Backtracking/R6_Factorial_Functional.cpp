#include <bits/stdc++.h>
using namespace std;

int fact(int n){
    if (n == 0){
        return 1;
    }
    return fact (n-1) * n;
}

int main(){
    int n;
    cout << "Enter the number: " << endl;
    cin >> n;
    cout << "The the factorial of " << n << " is " << fact(n) << endl;
}
