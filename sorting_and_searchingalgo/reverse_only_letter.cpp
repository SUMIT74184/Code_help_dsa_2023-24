#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

bool isAlpha(char c) {
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
        return true;
    }
   else {
        return false;
    }
}

// void swap(char arr[], int a, int b) {
//     char t = arr[a];
//     arr[a] = arr[b];
//     arr[b] = t;
// }

string reverseOnlyAlphabetical(string str) {
    int left = 0;
    int right = str.size() - 1;

    while (left < right) {
        if (!isAlpha(str[left]))
            left++;
        else if (!isAlpha(str[right]))
            right--;
        else {
            swap( str[left], str[right]);
            left++;
            right--;
        }
    }

    return str;
}

int main() {
    string str = "sea!$hells3";
    cout << reverseOnlyAlphabetical(str);
    return 0;
}