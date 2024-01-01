#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
        cout << "destructor has been called of :" << this->data << endl;
    }
};

int getLength(Node *&head)
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
void printlinkedlist(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {

        cout << temp->data << " ->";

        temp = temp->next;
    }
}

void insertAthead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }
    else
    {
        Node *newnode = new Node(data);
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insertAttail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
    }
    else
    {
        Node *newnode = new Node(data);
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}

void insertAtposition(Node *&head, Node *&tail, int position, int data)
{
    Node *newnode = new Node(data);
    Node *curr = head;
    Node *prevNode = NULL;
    while (position != 1)
    {
        position--;
        prevNode = curr;
        curr = curr->next;
    }
    // previos node ke sath setting
    prevNode->next = newnode;
    newnode->prev = prevNode;
    // current node ke sath setting
    newnode->next = curr;
    curr->prev = newnode;
}
void deleteAthead(Node *&head, Node *&tail, int position)
{
}
void deleteAttail(Node *&head, Node *&tail, int position)
{
}
void deleteAtposition(Node *&head, Node *&tail, int position)
{
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAthead(head, tail, 40);
    insertAthead(head, tail, 30);
    insertAthead(head, tail, 20);
    insertAthead(head, tail, 10);
    insertAtposition(head, tail, 3, 45);
    printlinkedlist(head);
    return 0;
}