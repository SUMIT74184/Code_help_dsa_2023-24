#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkredundant(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '+' || ch == '-' || ch == '/' || ch == '*')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            int operatorcount = 0;
            while (!st.empty() && st.top() != '(')
            {
                char temp = st.top();
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
                {
                    operatorcount++;
                }
                st.pop();
               
            }
             if (operatorcount == 0)
                {
                    return true;
                }
        }

        
    }
    return false;
}

    int main()
    {
        string str = "(a+b/(b))";
        bool ans = checkredundant(str);

        if (ans == true)
        {
            cout << " redundant bracket is present" << endl;
        }
        else
        {
            cout << "redundant brackets are not presrnt " << endl;
        }

        return 0;
    }