#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// ------------------- Utility -------------------
bool isLetter(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

string cleanWord(const string& w)
{
    string cleaned = "";
    for (int i = 0; i < w.length(); i++)
    {
        char c = w[i];
        if (isLetter(c))
            cleaned += tolower(c);
    }
    return cleaned;
}

class Node
{
public:
    string word;
    int count;
    Node* next;

    Node(string w) : word(w), count(1), next(nullptr) {}
};

class HashTable
{
private:
    Node** table;
    int size;

    int hashFunction(const string& key)  // add all ascii, divide by size , return
    {
        int hash = 0;

        for (int i = 0; i < key.length(); i++)
        {
            hash = hash + key[i];
        }

        int result = hash % size;

        return result;
    }

public:
    HashTable(int s)
    {
        size = s;
        table = new Node * [size];
        for (int i = 0; i < size; i++)
            table[i] = nullptr;
    }

    void insertWord(const string& w)
    {
        int index = hashFunction(w);

        Node* curr = table[index];

        while (curr != NULL)
        {
            if (curr->word == w)
            {
                curr->count++;
                return;
            }
            curr = curr->next;
        }

        Node* newnode = new Node(w);
        newnode->next = table[index];  // AT HEAD
        table[index] = newnode;
    }

    void displayWords()
    {
        for (int i = 0; i < size; i++)
        {
            Node* temp = table[i];

            while (temp != NULL)
            {
                cout << "Word : " << temp->word;
                cout << "        |         No Of Times : " << temp->count;

                temp = temp->next;
            }
            cout << " NULL" << endl;
        }
    }

    void deleteWord(const string& w)
    {
        int index = hashFunction(w);

        Node* curr = table[index];
        Node* pre = NULL;

        while (curr != NULL)
        {
            if (curr->word == w)  // FOUND
            {
                if (pre == NULL)    // IF IST NODE
                {
                    table[index] = curr->next;

                }


                else
                {
                    pre->next = curr->next;

                }

                delete curr;
                cout << "DELETED KEY :" << w;
                return;
            }

            pre = curr;
            curr = curr->next;
        }
        cout << "KEY NOT FOUND:" << w;
    }

    void insertFromFile(const string& filename)
    {
        ifstream file(filename);
        if (!file.is_open())
        {
            cout << "Cannot open file.\n";
            return;
        }

        string line, word = "";
        while (getline(file, line))
        {
            for (int i = 0; i < line.length(); i++)
            {
                char c = line[i];
                if (c == ' ')
                {
                    if (!word.empty())
                    {
                        word = cleanWord(word);
                        if (!word.empty())
                            insertWord(word);
                        word = "";
                    }
                }
                else
                {
                    word += c;
                }
            }

            if (!word.empty())
            {
                word = cleanWord(word);
                if (!word.empty())
                    insertWord(word);
                word = "";
            }
        }

        cout << "\nWords inserted from file.\n";
    }
};

int main()
{

    HashTable table(100);
    table.insertFromFile("C:\\Users\\HP\\Desktop\\paragraph.txt");
    int choice;
    string word, filename;

    do
    {
        cout << "\n--- Word Counter Menu ---\n";
        cout << "1. Display all words\n";
        cout << "2. Delete a word\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nAll Words:\n";
            table.displayWords();
            break;
        case 2:
            cout << "Enter word to delete: ";
            cin >> word;
            word = cleanWord(word);
            table.deleteWord(word);
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 3);

    return 0;
}