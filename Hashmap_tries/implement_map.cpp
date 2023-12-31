#include<iostream>
#include<unordered_map>
#include<vector> 
using namespace std;

int main(){

    unordered_map<string,int>mapping;

    pair<string,int>p=make_pair("sumit_rai",22);
    pair<string,int>q("dipansh",23);
    pair<string,int>qw;
    qw.first="sunil";
    qw.second=43;

//insertion implementation
    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(qw);
   mapping["rohit"]=34; //new method of insertion

   //implementation
    cout<<mapping.size()<<endl;
    cout<<mapping.at("sunil")<<endl;
    //at function is used to access the value pair corresponding to it
    cout<<mapping["sumit_rai"]<<endl;
    //counting the value
    cout<<"counting :"<<mapping.count("sumit_rai")<<endl;
    cout<<"mapping with new mwthod :"<<mapping.at("rohit")<<endl;



    //understanding the find function
    if(mapping.find("sumit_rai")!=mapping.end()){
        //if we reach final then element is not found thats why we are using the end
        cout<<"congo element is found!!!! "<<endl;
    }
    else{
        cout<<"element not find pal"<<endl;
    }

     //how size can be increased
    cout<<"the size of our entire mapping is "<<mapping.size()<<endl;
    cout<<"This entry"<<mapping["samar"]<<endl;
    cout<<"now the updated size is :"<<mapping.size()<<endl;
    cout<<mapping.at("samar")<<endl;//here mapping is created at the 0th postion
    return 0;

}