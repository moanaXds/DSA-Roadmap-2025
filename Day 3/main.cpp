#include <iostream>
#include <fstream>
#include <chrono>
#include <cstring>
#include "algorithm.h"

using namespace std;
using namespace chrono;

int main() {
    string filename_random_5000 = "./data/random5000.txt";
    string filename_random_10000 = "./data/random10000.txt";
    string filename_random_50000 = "./data/random50000.txt";

    string filename_reversed_5000 = "./data/reversed5000.txt";
    string filename_reversed_10000 = "./data/reversed10000.txt";
    string filename_reversed_50000 = "./data/reversed50000.txt";

    string filename_sorted_5000 = "./data/sorted5000.txt";
    string filename_sorted_10000 = "./data/sorted10000.txt";
    string filename_sorted_50000 = "./data/sorted50000.txt";

    cout << "Select input file:\n";
    cout << "1. Random 5000\n";
    cout << "2. Random 10000\n";
    cout << "3. Random 50000\n";
    cout << "4. Reversed 5000\n";
    cout << "5. Reversed 10000\n";
    cout << "6. Reversed 50000\n";
    cout << "7. Sorted 5000\n";
    cout << "8. Sorted 10000\n";
    cout << "9. Sorted 50000\n";
    cout << "Enter choice (1-9): ";

    int fileChoice;
    cin >> fileChoice;

    string filename;
    switch (fileChoice) 
    {
        case 1: filename = filename_random_5000; break;
        case 2: filename = filename_random_10000; break;
        case 3: filename = filename_random_50000; break;
        case 4: filename = filename_reversed_5000; break;
        case 5: filename = filename_reversed_10000; break;
        case 6: filename = filename_reversed_50000; break;
        case 7: filename = filename_sorted_5000; break;
        case 8: filename = filename_sorted_10000; break;
        case 9: filename = filename_sorted_50000; break;
        default:
            cout << "Invalid choice! Using Random 5000 as default.\n";
            filename = filename_random_5000;

    }

    ifstream in(filename);
    int count = 0;
    int temp;
    while (in >> temp) {
        count++;
    }

    int* arr = new int[count];

    in.clear();               
    in.seekg(0, ios::beg); 

    for (int i = 0; i < count; ++i) {
        in >> arr[i];
    }
    in.close();

    cout << "\nChoose operation:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Binary Search (array will be sorted first)\n";
    cout << "Enter choice (1/2/3/4): ";

    int choice;
    cin >> choice;

    char algorithmName[30];
    auto start = high_resolution_clock::now();

    switch (choice) {
    case 1:
        bubbleSort(arr, count);
        strcpy_s(algorithmName, sizeof(algorithmName), "Bubble Sort");
        break;
    case 2:
        selectionSort(arr, count);
        strcpy_s(algorithmName, sizeof(algorithmName), "Selection Sort");
        break;
    case 3:
        insertionSort(arr, count);
        strcpy_s(algorithmName, sizeof(algorithmName), "Insertion Sort");
        break;
    case 4: {
        insertionSort(arr, count); 
        strcpy_s(algorithmName, sizeof(algorithmName), "Binary Search");

        int target;
        cout << "Enter number to search: ";
        cin >> target;

        auto searchStart = high_resolution_clock::now();
        int result = binarySearch(arr, count, target);
        auto searchStop = high_resolution_clock::now();

        auto searchTime = duration_cast<microseconds>(searchStop - searchStart).count();
        if (result != -1)
            cout << "Number found at index: " << result << "\n";
        else
            cout << "Number not found.\n";

        ofstream fout("./data/results.txt", ios::app);
        fout << "Binary Search: " << searchTime << " microseconds\n";
        fout.close();

        cout << "Binary Search completed in " << searchTime << " microseconds.\n";

        delete[] arr;
        return 0;
    }
    default:
        cout << "Invalid choice!\n";
        delete[] arr;
        return 1;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start).count();

    ofstream fout("./data/results.txt", ios::app);
    if (fout.is_open()) {
        fout << algorithmName << ": " << duration << " microseconds\n";
        fout.close();
    }
    else {
        cerr << "Error opening results file to write.\n";
    }

    cout << "\nOperation completed using " << algorithmName << ".\n";
    cout << "Execution time: " << duration << " microseconds.\n";
    cout << "Result saved to results.txt.\n";

    delete[] arr;
    return 0;
}
