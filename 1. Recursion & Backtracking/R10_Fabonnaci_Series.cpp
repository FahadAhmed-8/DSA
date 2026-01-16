#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fib(n-1) + fib(n-2);
}

void print(int n){
    if (n < 0) return;
    cout << "The element at location " << n << " is " << fib(n) << endl;
    print(n - 1); 
}

int main(){
    int n;
    cout << "Enter the lenght of the Sequence: ";
    cin >> n;
    print(n);
    return 0;
}