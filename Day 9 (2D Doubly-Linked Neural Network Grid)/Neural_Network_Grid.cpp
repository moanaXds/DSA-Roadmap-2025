#include <iostream>
using namespace std;




class Neuron
{
public:
    int data;
    Neuron* up;
    Neuron* down;
    Neuron* left;
    Neuron* right;

    Neuron(int val)
    {
        data = val;
        up = down = left = right = NULL;
    }
};




class NeuralGrid
{
private:
    Neuron* head; // top-left neuron
    int rows, cols;

public:
    NeuralGrid(int rows, int cols)
    {
        this->rows = rows;
        this->cols = cols;

        head = NULL;
        create2DList();
    }



   //  we need :
     
   //  1. previous row start and previous node
   //  2. current row start and curr node

    void create2DList()
    {
        Neuron* prevRow = NULL;     // start of previous row
        Neuron* prevNode = NULL;    // previous node 
        int val = 1;

        //  allocating nodes row by row 

        for (int i = 0; i < rows; i++)
        {
            Neuron* currentRowStart = NULL;
            Neuron* currentNode = NULL;

            for (int j = 0; j < cols; j++)
            {
                Neuron* newNode = new Neuron(val++);

                if (head == NULL)
                {
                    head = newNode;
                }


                //  if prev node exits

                if (prevNode)
                {
                    prevNode->right = newNode;
                    newNode->left = prevNode;
                }

                // if above/prev row exist

                int step = 0;

                if (prevRow)
                {
                    Neuron* upper = prevRow;
                    while (upper != NULL && step < j)
                    {
                        upper = upper->right;
                        step++;
                    }

                    if (upper)
                    {
                        upper->down = newNode;
                        newNode->up = upper;
                    }

                }

                // set first node in this row

                if (j == 0)
                {
                    currentRowStart = newNode;
                }


                prevNode = newNode;
            }

           //  move to next row

            prevRow = currentRowStart;
            prevNode = NULL;
        }
    }







    void setValue(int r, int c, int val)
    {
        Neuron* temp = head;

        for (int i = 0; i < r; i++)
        {
            temp = temp->down;
        }

        for (int j = 0; j < c; j++)
        {
            temp = temp->right;
        }

        temp->data = val;
    }



    void removeByValue(int val)
    {
        Neuron* row = head;

        while (row)
        {
            Neuron* col = row;

            while (col)
            {
                if (col->data == val)
                {
                    col->left->right = col->right;

                    col->right->left = col->left;

                    col->up->down = col->down;

                    col->down->up = col->up;

                     If head

                    if (col == head)
                    {
                        if (head->right != NULL)
                        {
                            head = head->right;   // move right
                        }
                        else
                        {
                            head = head->down;    // otherwise move down
                        }
                    }


                    delete col;

                    cout << "Neuron with value " << val << " removed.\n";
                    return;
                }

                col = col->right;

            }

            row = row->down;

        }

        cout << "Value not found.\n";
    }




    void reverseColumn(int col)
    {
        if (head == NULL)
        {
            cout << "empty.\n";
            return;
        }

       //  Step 1: Move to the desired column

        Neuron* colHead = head;

        int step = 0;

        while (colHead != NULL && step < col)
        {
            colHead = colHead->right;
            step++;
        }

        if (colHead == NULL)
        {
            cout << "WRONG column number.\n";
            return;
        }

         //         COUNT ROWS IN THAT COL

        int count = 0;

        Neuron* temp = colHead;

        while (temp != NULL)
        {
            count++;
            temp = temp->down;
        }


        //  incomplete column

        if (count != rows)
        {
            cout << "Cannot reverse column\n";
            return;
        }


       //    CONVERT NEURONS INTO ARRAY


        Neuron* arr[50];

        temp = colHead;

        int S = 0;

        while (temp != NULL)
        {
            arr[S++] = temp;
            temp = temp->down;
        }

        int i = 0;
        int j = count - 1;

        while (i < j)
        {
            swap(arr[i]->data, arr[j]->data);
            i++;
            j--;
        }

        cout << "Column " << col << " reversed successfully!\n";
    }




    void print()
    {
        Neuron* row = head;
        while (row)
        {
            Neuron* col = row;
            while (col)
            {
                cout << col->data << "\t";
                col = col->right;
            }
            cout << endl;
            row = row->down;
        }
    }
};




int main()
{
    int rows = 3, cols = 4;
    NeuralGrid grid(rows, cols);

    int choice, r, c, val;
    do
    {
        cout << "\n----------- Neural Grid Menu ---------------\n";
        cout << "1. Display Grid\n";
        cout << "2. Set Value \n";
        cout << "3. Remove by Value\n";
        cout << "4. Exit\n";
        cout << "-----------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            grid.print();
            break;
        case 2:
            cout << "Enter row : ";
            cin >> r;

            cout << "Enter col : ";
            cin >> c;

            cout << "Enter new value: ";
            cin >> val;


            grid.setValue(r, c, val);
            break;

        case 3:
            cout << "Enter value to remove: ";
            cin >> val;

            grid.removeByValue(val);
            break;


        case 4:
            cout << "Exit\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    int col;

    cout << "enter col for reversing\n";
    cin >> col;
    grid.reverseColumn(col);

    cout << "\nGrid after reversing  " << col << ":\n";
    grid.print();

    return 0;
}
