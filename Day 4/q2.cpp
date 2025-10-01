#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;

    cout << "Enter numbers of signal : ";
    cin >> n;

    string signal[20];
    string result[20];

    cout << "Enter  signals: \n";

    for (int i = 0; i < n; i++) 
    {
        cin >> signal[i];
    }



    for (int i = 0; i < n; i++)
    {
        string current = signal[i];
        string weaker = "-"; 

        
        for (int j = i + 1; j < n; j++) 
        {
            if (signal[j] < current) 
            {   // lexicographically check
                weaker = signal[j];
                break;   
            }
        }
        result[i] = weaker;
    }

    cout << "Lexical Destabilization Map: ";
    for (int i = 0; i < n; i++) 
    {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}
