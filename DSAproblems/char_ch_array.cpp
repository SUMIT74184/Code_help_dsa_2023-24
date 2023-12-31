#include<bits/stdc++.h>
using namespace std;

int getLength(char ch[], int size) {
    int length = 0;
    for (int i = 0; i < size; i++) {
        if (ch[i] == '\0') {
            break;
        }
        else {
            length++;
        }
    }
    return length;
}

void reverseString(char ch[], int size) {
int i = 0;
    int j = size - 1;
  for(int index=0;index<size;index++){
        swap(ch[index], ch[j]);
        index++;
        j--; // Fix: Decrement j here
    }
    ch[size] = '\0'; // Fix: Add null-terminator at the end
    return;
}

int main() {
    // char ch[100];
    // cin >> ch;

    // int len = getLength(ch, 100);
    // cout << "the length of a character array: " << len << endl;
    // reverseString(ch, len);
    // cout << "reversal of the string is: " << ch << endl;


char cha[102];

 cin.getline(cha,90);
 int len=getLength(cha,90);
cout<<"the length of the string is "<<len;

// //cin>>cha;
// cout<<"printing the character array"<<" :"<<cha;





    return 0;
}