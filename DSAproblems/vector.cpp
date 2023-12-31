#include<iostream>
#include<vector>

using namespace std;



 void printvect(vector<int>v){
for(int i=0;i<v.size();i++){
    cout<<"the vectors are"<<v[i]<<endl;
}


}
int main(){



vector<int>v;
v.push_back(90);
v.push_back(89);
v.push_back(76);
printvect(v);



    return 0;
}
