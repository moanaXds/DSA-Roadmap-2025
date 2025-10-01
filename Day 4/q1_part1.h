#include <iostream>

using namespace std;

class Node
{

public:
    Node *next;
    int data;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
private:
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    void push(int val)
    {
        Node *newnode = new Node(val);

        if (head == NULL)
        {
            head = newnode;
            return;
        }

        newnode->next = head;
        head = newnode;
    }

    int popfront()
    {
        if (head == NULL)
        {
            cout << "The list is empty\n";
            return -1;
        }

        Node *temp = head;
        int data = head->data;
        head = head->next;
        delete temp;

        return data;
    }

    void peek()
    {
        if (head == NULL)
        {
            cout << "Empty\n";
            return;
        }

        cout << "\nThe Top element" << head->data << endl;
    }

    void isempty()
    {
        if (head == NULL)
        {
            cout << "Empty\n";
            return;
        }
    }

    void Display()
    {
        Node *temp = head;
        cout << "dISPLAY-\n";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
