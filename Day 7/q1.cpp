

#include <iostream>


using namespace std;

// ===========================================================
// Implement Node class with an ID and the pointer to point
// to point to its previous node.
// ===========================================================

class Node
{
public:
    int id;
    Node* prev;

    Node(int id)
    {
        this->id = id;
        prev = NULL;
    }

};



// ===============================================================
// Implement CircularNetwork class with the following methods:
// addNode(id)
// simulateShutdown(k) where k is the nodes to shutdown in circles
// ===============================================================

class CircularNetwork {
private:
    Node* head;

public:
    CircularNetwork()
    {
        head = NULL;
    }

    void addNode(int id)
    {
        Node* newnode = new Node(id);

        if (head == NULL)
        {
            head = newnode;
            head->prev = head;
            return;
        }

        Node* temp = head;

        while (temp->prev != head)
        {
            temp = temp->prev;
        }

        temp->prev = newnode;
        newnode->prev = head;

    }

    void simulateShutdown(int k)
    {
        Node* temp = head;

        while (temp->prev != temp)
        {

            for (int i = 1; i < k - 1; i++)
            {
                temp = temp->prev;
            }


            Node* temp2 = temp->prev;

            cout << "DELETED NODE " << temp2->id << " ";


            temp->prev = temp2->prev;

            if (temp2 != head)
            {
                delete temp2;
            }


            temp = temp->prev;
        }

        cout << "Remaining node :" << temp->id;

    }


    void display()
    {
        Node* temp = head;
        if (head == NULL)return;

        do
        {
            cout << temp->id;
            temp = temp->prev;
        } while (temp != head);
        cout << endl;
    }
};


int main() {
    int n, k;
    cout << "Enter total nodes: ";
    cin >> n;
    cout << "Enter step count (k): ";
    cin >> k;

    CircularNetwork network;

    for (int i = 1; i <= n; ++i)
        network.addNode(i);


    network.display();

    network.simulateShutdown(k);

    return 0;
}
