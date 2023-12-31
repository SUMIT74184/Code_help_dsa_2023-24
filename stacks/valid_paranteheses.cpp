#include <iostream>
#include <stack>
using namespace std;

bool validparantheses(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
            // our main logic work from here
        }
        else
        {
            if (!st.empty())
            { // if the the stack is empty then only the element will be inserted
                if (ch == ')' && st.top() == '(')
                {
                    st.pop(); // if we find closing bracket then we will remove it only if the top element is
                    // is of the same type
                }
                else if (ch == ']' && st.top() == '[')
                {
                    st.pop();
                }
                else if (ch == '}' && st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    return false; // or we simply return the false
                }
            }
            else
            {
                return false; // if the stack is not empty
            }
        }
    }
    if (st.size() == 0)
    {
        return true;
    } // in this position only the stack value will be return that is empty or not
    else
    {
        return false;
    }
}

int main()
{
    string str = "{([])}";
    bool ans = validparantheses(str);

    if (ans == 1)
    {
        cout << "it is valid parantheses" << endl;
    }
    else
    {
        cout << "not a valid parantheses" << endl;
    }

    return 0;
}