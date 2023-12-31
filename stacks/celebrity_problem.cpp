 #include<iostream>
 #include<vector>
 #include<stack>
 using namespace std;
 
  int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        //step 2 discard method that might be celebrity
        while(st.size()!=1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            
            //if a knows b
            if(M[a][b]){
                //a is discarded and we are going to push b
                st.push(b);
            }
            else{
                // st.push
                st.push(a);
            }
        }
        //step 3 checking that the single person is celebrity
        int mightCelebrity=st.top();
        st.pop();
        
        //celebrity does not know anyone 
        for(int i=0;i<n;i++){
            if(M[mightCelebrity][i]!=0){
                return -1; //representing the row that it should be 0 but here it's not
            }
        }
        //everonne should know celebrity
        for(int i;i<n;i++){
            if(M[i][mightCelebrity]==0 && i!=mightCelebrity){
                return -1;//reperenting the column that it should be one
            }
        }
        //mightbe celebrity
        return mightCelebrity;
    } 