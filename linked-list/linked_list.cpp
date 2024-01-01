#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node()
    {
        //   cout<<"i am inside the default constructor"<<endl;
        this->next = NULL;
    }

    Node(int data)
    {
        // cout<<" i am inside the parameterized constructor"<<endl;
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "destructor is called now for " << this->data<<endl;
    }
};

int getLength(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
void printlinkedlist(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {

        cout << temp->data << " ->";

        temp = temp->next;
    }
}
void insertAthead(Node *&head, Node *tail, int data)
{
    if (head == NULL)
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }

    else
    {
        // creation of the new node
        Node *newnode = new Node(data);
        // attaching the newnode
        newnode->next = head;
        // updating the new node
        head = newnode; // the head is the destination
    }
}

void insertAttail(Node *head, Node *tail, int data)
{

    if (head == NULL)
    {
        Node *finnode = new Node(data);
        head = finnode;
        tail = finnode;
    }
    else
    {
        Node *finnode = new Node(data);
        tail->next = finnode;
        tail = finnode;
    }
}

void insertAtposition(Node *head, Node *tail, int data, int position)
{
    if (position < 1)
    {
        cout << "cannot insert at the position " << endl;
    }
    int length = getLength(head);
    if (position > length)
    {
        cout << "cannot insert in the position" << endl;
    }

    if (position == 1)
    {
        insertAthead(head, tail, data);
    }
    else if (position == length)
    {
        insertAttail(head, tail, data);
    }
    else
    {
        // insert at any position
        Node *newnode = new Node(data);
        Node *prev = NULL;
        Node *curr = head;
        while (position != 1)
        {
            prev = curr;       // previous is moving ahead and becomes equals to current
            curr = curr->next; // current is moving ahead
            position--;
        }
        // step:3
        prev->next = newnode;
        newnode->next = curr;
    }
}

void Deletenode(Node *&head, Node *&tail, int position)
{
    int length = getLength(head);
    if(head==tail){
        Node*temp=head;
        delete temp;
        head=NULL;
        tail=NULL;
        return;
    }
    if (position == 1)
    {
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else if (position == length)
    {
        // deleting the previous tail
        Node *prev = head;
        while (prev->next != tail)
        {
            // previous will stop when the last node is equal to second last node
            prev = prev->next;
        }
        // making the second last one equals to null
        prev->next = NULL;
        delete tail; // destructor
        // updating the last node
        tail = prev;
    }
    else
    {
        // same traversal logic by decrementing by 1
        Node *curr = head;
        Node *prev = NULL;

        while (position != 1)
        {
            position--;
            prev = curr;
            curr = curr->next;
        }
        // isolating that particular node
        prev->next = curr->next;
        // making it null
        curr->next = NULL;
        // now remove
        delete curr;
    }
}

int main()
{
    // Node a;//static object has been created
    // Node*a=new Node();//dynamically object has been created
    // creation of the different node

    Node *first = new Node(10);
    Node *head = first;
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *tail = third;

    // linked-list created
    first->next = second;
    second->next = third;
    third->next = NULL;

    // insert at the head of the linked list

    // Node*tail=NULL;

    // printlinkedlist(head);
    //  cout<<"printing the length "<<getLength(head)<<endl;
    insertAthead(head, tail, 101);
    insertAttail(head, tail, 200);
    insertAtposition(head, tail, 3453, 3);
    printlinkedlist(head);

    Deletenode(head,tail,3);
    printlinkedlist(head);
    return 0;
}