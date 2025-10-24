#include <iostream>

using namespace std;

// ====================================================================
// Use inspiration from the previous lab task of 2D Doubly Linked List
// to implement the variation mentioned in the PDF file of this lab's
// manual.
// =====================================================================


class Node {
public:
    Node* next;
    Node* prev;
    int data;

    Node(int val)
    {
        next = prev = NULL;
        data = val;
    }
};

class MultiRowCircularDoublyList {
private:
    int rows;
    int cols;
    Node** head;

public:
    MultiRowCircularDoublyList(int rows, int cols)
    {
        this->rows = rows;
        this->cols = cols;
        head = new Node * [rows];

        for (int i = 0; i < rows; i++)
        {
            head[i] = NULL;
        }
    }

    void setValue(int i, int j, int val)
    {
        Node* newnode = new Node(val);

        if (head[i] == NULL)
        {
            head[i] = newnode;
            head[i]->next = newnode;
            head[i]->prev = newnode;

            return;
        }

        Node* temp = head[i]->prev;

        temp->next = newnode;
        newnode->prev = temp;

        head[i]->prev = newnode;
        newnode->next = head[i];
    }

    void display()
    {
        for (int i = 0; i < rows; i++)
        {
            if (head[i] == NULL)return;

            Node* temp = head[i];

            do
            {
                cout << temp->data << " ";
                temp = temp->next;

            } while (temp != head[i]);
            cout << endl;
        }
    }
};


int main()
{
    int rows, cols, val;
    int choice;

    cout << "Rows: ";
    cin >> rows;

    cout << "Columns: ";
    cin >> cols;

    MultiRowCircularDoublyList list(rows, cols);
    val = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            list.setValue(i, j, val++);

        }
    }
    list.display();
    return 0;
}
