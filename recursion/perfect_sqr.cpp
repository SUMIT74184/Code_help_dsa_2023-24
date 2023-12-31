#include <bits/stdc++.h>


using namespace std;

int numsquare(int n)
{
//we are finding the least number square to get out target solution
    if (n == 0)
    {
        return 0;
    }
    int ans = INT_MAX;
    int end = sqrt(n);
    int i = 1;
    while (i <= end)//we can also use a for loop to implement it
    {
        int perfectsquare = i * i;//it will caluc
        int numofcountprfsqr = 1 + numsquare(n - perfectsquare);//count will be return as the root node will give
        if (numofcountprfsqr < ans)//matching it with ans 
        {
            ans = numofcountprfsqr;
        }
        ++i;
    }
    return ans;
}
int main()
{

    int nsa = numsquare(12);
    cout << "THE NUMBER OF POSSIBEL WAYS TO SUMUP:" << nsa << endl;
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;

// int numsquare(int n) {
//     if (n == 0) {
//         return 0;
//     }

//     int ans = INT_MAX;
//     int end = sqrt(n);
//     for (int i = 1; i <= end; ++i) {
//         int perfectsquare = i * i;
//         int numofcountprfsqr = 1 + numsquare(n - perfectsquare);
//         if (numofcountprfsqr < ans) {
//             ans = numofcountprfsqr;
//         }
//     }
//     return ans;
// }

// int main() {
//     int nsa = numsquare(25);
//     cout << "THE NUMBER OF POSSIBLE WAYS TO SUM UP: " << nsa << endl;
//     return 0;
// }
