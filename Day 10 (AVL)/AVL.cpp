
#include <iostream>
#include <string>
using namespace std;

// ===== Gamer Class =====
class Gamer
{
public:
    int rank;
    float accuracy;

    Gamer() : rank(0), accuracy(0.0) {}

    Gamer(int r, float acc) : rank(r), accuracy(acc) {}

    void display() const
    {
        cout << "Rank : #" << rank
            << ", Accuracy: " << accuracy
            << endl;
    }
};

// ===== AVL Node Class =====
class Node
{
public:
    Gamer gamer;
    Node* left;
    Node* right;
    int height;

    Node(Gamer g) : gamer(g), left(nullptr), right(nullptr), height(1) {}

};

// ===== AVL Class =====

class GamerAVL
{
private:
    Node* root;

    int getHeight(Node * node)
    {
        if (node == NULL)return 0;

        return node->height;
    }

    int getBalance(Node* node)
    {
        if (node == NULL)return 0;

        return getHeight(node->left) - getHeight(node->right);

    }

    Node* RotateRight(Node* node)
    {
        Node* y = node->left;
        Node* x = y->right;

        y->right = node;
        node->left = x;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;


        return y;
    }

    Node* RotateLeft(Node* node)
    {
        Node* y = node->right;
        Node* x = y->left;

        y->left = node;
        node->right = x;

        
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* insert(Node* node, Gamer g)
    {
        if (node == NULL)
        {
            return new Node(g);
        }

        if (g.rank < node->gamer.rank)
        {
            node->left = insert(node->left, g);
        }

        else if (g.rank > node->gamer.rank)
        {
            node->right = insert(node->right, g);
        }

        else
        {
            return node;
        }
            

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        int balance = getBalance(node);

        // r

        if (balance > 1 && getBalance(node->left) >= 0)
        {
            return RotateRight(node);
        }

        // lr

        if (balance > 1 && getBalance(node->left) < 0)
        {
            node->left = RotateLeft(node->left);
            return RotateRight(node);
        }

        // l

        if (balance < -1 && getBalance(node->right) <= 0)
        {
            return RotateLeft(node);
        }

        //rl

        if (balance < -1 && getBalance(node->right) > 0)
        {
            node->right = RotateRight(node->right);
            return RotateLeft(node);
        }

        return node;
    }

    void inorder(Node* node)
    {
        if (!node)
            return;
        inorder(node->left);
        node->gamer.display();
        inorder(node->right);
    }

    Node* search(Node* node, int rank)
    {
        if (node == NULL)
        {
            return NULL;
        }

        if (rank == node->gamer.rank)
        {
            return node;
        }

        if (rank < node->gamer.rank)
        {
            return  search(node->left, rank);
        }

        if (rank > node->gamer.rank)
        {
            return  search(node->right, rank);
        }
        else
        {
            return node;
        }
    }

    Node* findMinaccNode(Node* node)
    {
        if (node == NULL)return NULL;

        Node* minNode = NULL;

        findMinaccNodeHelper(node, minNode);

        return minNode;
    }

    void findMinaccNodeHelper(Node* node, Node*& minNode)
    {
        if (node == nullptr) return;

        if (minNode == NULL || node->gamer.accuracy < minNode->gamer.accuracy)
        {
            minNode = node;
        }

        findMinaccNodeHelper(node->left, minNode);
        findMinaccNodeHelper(node->right, minNode);
    }

    Node* deleteByRank(Node* node, int rank)
    {
        if (node == NULL)
        {
            return NULL;
        }


        if (rank < node->gamer.rank)
        {
            node->left = deleteByRank(node->left, rank);
        }

        else if (rank > node->gamer.rank)
        {
            node->right = deleteByRank(node->right, rank);
        }

        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }

            else if (node->right == NULL)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            else
            {
                Node* temp = node->right;

                while (temp->left != NULL)
                {
                    temp = temp->left;
                }

                node->gamer = temp->gamer;

                node->right = deleteByRank(node->right, temp->gamer.rank);

            }
        }

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        int balance = getBalance(node);

        // r

        if (balance > 1 && getBalance(node->left) >= 0)
        {
            return RotateRight(node);
        }

        // lr

        if (balance > 1 && getBalance(node->left) < 0)
        {
            node->left = RotateLeft(node->left);
            return RotateRight(node);
        }

        // l

        if (balance < -1 && getBalance(node->right) <= 0)
        {
            return RotateLeft(node);
        }

        //rl

        if (balance < -1 && getBalance(node->right) > 0)
        {
            node->right = RotateRight(node->right);
            return RotateLeft(node);
        }

        return node;
    }

public:
    GamerAVL() : root(nullptr) {}

    void insert(Gamer g)
    {
        root = insert(root, g);
    }

    void displayLeaderboard()
    {
        cout << "\n=== Leaderboard (sorted by rank) ===\n";
        inorder(root);
    }

    void searchByRank(int rank)
    {
        Node* result = search(root, rank);

        if (result == NULL) cout << "Player not found\n";

        else
        {
            cout << "Player found: ";
            result->gamer.display();
        }
    }

    void deleteMinAccuracy()
    {
        Node* minNode = findMinaccNode(root);
        if (minNode)
        {
            root = deleteByRank(root, minNode->gamer.rank);
        }
    }


    bool verifyAVL(Node* node) 
    {
        if (!node) return true;

        int balance = getBalance(node);

        if (balance < -1 || balance > 1) return false;

        return verifyAVL(node->left) && verifyAVL(node->right);
    }

};

// ===== Main Function =====
int main()
{
    GamerAVL leaderboard;

    // Insert nodes
    leaderboard.insert(Gamer(50, 85.5));
    leaderboard.insert(Gamer(30, 70.2));
    leaderboard.insert(Gamer(70, 92.1));

    leaderboard.displayLeaderboard();

    leaderboard.deleteMinAccuracy();
    leaderboard.displayLeaderboard();

    return 0;
}