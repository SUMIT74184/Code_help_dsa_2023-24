#include<iostream>
#include<vector>

using namespace std;

void selectionsort(vector<int> &v){
   int n=v.size();
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){

            if(v[j]<v[minIndex]){

               minIndex=j;
          
             // minIndex=j;
            }
            

            
        }
           swap(v[i],v[minIndex]);
  
}
}

void print(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<"printing...."<<v[i]<<endl;
    }
}




int main(){
vector<int> v(6);

    for(int i=0;i<v.size();i++){
//{45,75,85,95,90};
cin>>v[i];
    }
selectionsort(v);
print(v);

    return 0;
}