#include<iostream>
using namespace std;

int main(){
    // string name;
    // //cin>>name;
    
    // getline(cin,name);

    // cout<<"get the length of the string"<<name.length()<<endl;
    // cout<<"name at the position : "<<name.at(0);

    // string str1="sumit";
    // string str2="rai";
    // cout<<"before appending the string"<<endl;
    // cout<<str1<<endl;
    // cout<<str2<<endl;

    // cout<<"after appending the string"<<endl;
    // str1.append(str2);
    // cout<<str1<<endl;

//   for(int index=0;index<name.size();index++){
//     cout<<"position of string :" <<index<<" character present at :" <<name[index]<<endl;
//   //  index++;
// }
// cout<<(int)name[6]<<endl;


//     string stat="this is a car";
//     stat.erase(4,3);
//     cout<<"romoving :"<<stat<<endl;

//     string name="sumit ";
//     string sr="rai";
//    // name.insert(5,sr);//insert in the middle(index no,string name)
//     name.push_back('sr');
//     cout<<name<<endl;

    string str1="this is the home";
    string str2="homeooooo";

    if(str1.find(str2)==string::npos)
    {
        cout<<"element  not found"<<endl;
    }
    else{
        cout<<"element found"<<endl;
    }


        string desc="this is a car,big daddy of all the suv";
        // desc.substr(19,5);
        cout<<desc.substr(18,6)<<endl;

    return 0;
}