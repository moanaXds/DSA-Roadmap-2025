#include<iostream>

using namespace std;

class ArrayStack{
    private:

        int arr[10];
        int val;
        int s =0;

    public:
        void push(int element)
        {
            val = sizeof(arr) / sizeof(arr[0]);

            for (int i = val-1; i > 0; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[0] = element;
            s++;
        }

        int pop()
        {
            if(val==0)
            {
                cout << "Array is empty\n";
             
                return -1;
            }
            s--;

            return arr[0];
        }

        void peek()
        {
            if (val == 0)
            {
                cout << "Array is empty\n";
                return;
            }
            cout <<"\nThe first element is :"<< arr[0]<<endl;
        }

        void isempty()
        {
            if (val == 0)
            {
                cout << "Array is empty\n";
            }
        }
        void display()
        {
            for (int i = 0; i < s; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

