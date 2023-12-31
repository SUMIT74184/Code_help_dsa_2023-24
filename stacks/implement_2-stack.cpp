#include <iostream>
using namespace std;

class stack
{
public:
    int *arr;//making the dynamic array
    int size;//
    int top1;//pointer
    int top2;//pointer

    stack(int size)
    {
        arr = new int[size];
        this->size = size;//taking the size by reference
        top1 = -1;//intiating there position
        top2 = size;//initiating there position
    }
    void push1(int data)
    {
        if (top2 - top1 == 1)//it is the condition that stack is overflowed already
        {
            cout << "the stack is overflow" << endl;
        }
        else
        {
            top1++;
            arr[top1] = data;
        }
    }

    void push2(int data)
    {

        if (top2 - top1 == 1)
        {//it is the condition that stack is already fulled
            cout << "the stack is overflow" << endl;
        }
        else
        {
            top2--;
            arr[top2] = data;
        }
    }

    void pop1()
    {
        if (top1 == -1)
        {//stack is already emoty
            cout << "the stack is already empty for top 1" << endl;
        }
        arr[top1] = 0;
        top1--;
    }

    void pop2()
    {
        if (top2 == size)
        {
            cout << "the stack is already empty for top 2" << endl;
        }
        else
        {
            arr[top2] = 0;
            top2++;
        }
    }

    void print()
    {
        cout << "top1 :" << top1 << endl;
        cout << "top2 :" << top2 << endl;
        cout << "the values in the stack is" << endl;
        for (int i = 0; i < size; i++)
        {

            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    stack st(6);
    st.print();

    st.push1(34);
    st.print();
    // st.pop1();
    st.print();
    st.push2(234);
    st.push1(78);
    st.push2(90);
    st.print();
    st.push1(23);
    st.push1(34);
    st.print();

    st.pop1();
    st.pop1();
   // st.pop1();
   // st.pop1();
   st.print();

    return 0;
}