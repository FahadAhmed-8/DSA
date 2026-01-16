#include <bits/stdc++.h>
using namespace std;

bool pal(int i, int n, string input){
    if (input[i] == input[n]) return true;
    else return false;
}

void check_palindrome(int i, int n, string input) {
    if (i >= n/2) {
        cout << "Yes A palindrome";
        return;
    }
    if (!pal(i, n - 1- i, input)){
        cout << "Not A palindrome";
        return;
    } 
    check_palindrome(i + 1, n, input);
}

int main(){
    string input;
    cout << " Enter the Word: ";
    cin >> input;

    //function
    check_palindrome(0, input.size() ,input);

    return 0;
}