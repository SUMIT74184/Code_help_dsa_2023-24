// #include<bits/stdc++.h>
// #include<vector>
// #include<algorithm>

// using namespace std;


// void print(vector<int> &v){
// for(int i=0;i<v.size();i++){
//     cout<<" "<<v[i]<<endl;
// }
// }

// bool mycomp(int &a, int &b){ 
//             return a>b;
// }

// int main(){
// vector<int> v={44,5,6,2,42};

//  sort(v.begin(),v.end());
//   sort(v.begin(),v.end(),mycomp);
 
// print(v);



//     return 0;
// }
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>

using namespace std;


// void print(vector<vector<int>>&v){
// for(int i=0;i<v.size();i++){
//     cout<<" "<<v[i]<<endl;
// }
// }


void printvv(vector<vector<int>> &v) {
  for (int i = 0; i < v.size(); ++i) {
    vector<int> &temp = v[i];
    int a = temp[0];
    int b = temp[1];
    cout << a << " " << b << endl;
  }
  cout << endl;
}

int mycomp(vector<int>&a,vector<int>&b){
  return a[1]<b[1];
}


int main(){
    int n;
  vector<vector<int>>v(n);
  cout<<"enter the size"<<endl;
  cin>>n;
  for(int i=0;i<n;i++){
    int a,b;  
    cout<<"now enter a and b"<<endl;
    cin>>a;
    cin>>b;
        vector<int>temp;
    temp.push_back(a);
    temp.push_back(b);
    v.push_back(temp);
    
  }
  printvv(v);
  sort(v.begin(),v.end(),mycomp);
  printvv(v);
  


    return 0;
}