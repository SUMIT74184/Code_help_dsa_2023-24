#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class MinStack {
public:
    vector<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            //making an array with two integer value to be carried
            //pair->vector<pair<int,int>>st;
            //make_pair then please provide the values too
            pair<int,int>p;//=make_pair(3,4);
            p.first=val;
            p.second=val;
            st.push_back(p);

        }
        else{
             pair<int,int>p;//=make_pair();
             p.first=val;//storing the current value
             int previous_min=st.back().second;//storing the value int the previous vairable
             p.second=min(previous_min,val);//comparing the minimum value
             st.push_back(p);
        }
        
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        pair<int,int>rightmost=st.back();
        return rightmost.first;
    }
    
    int getMin() {
         pair<int,int>rightmost=st.back();
        return rightmost.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main(){

    return 0;
}