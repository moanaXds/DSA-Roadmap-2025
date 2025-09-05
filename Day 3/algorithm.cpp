#include <iostream>
#include <fstream>
#include <chrono>
#include <cstring>
#include "algorithm.h"


// Function to perform Bubble Sort
void bubbleSort(int arr[], int count) {
    for (int i = 0; i < count - 1; i++) {
        // Last i elements are already in place
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void selectionSort(int arr[], int count) {
    for (int i = 0; i < count - 1; i++) {
        // Find the index of the minimum element in the unsorted part
        int minIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first unsorted element
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Function to perform Insertion Sort
void insertionSort(int arr[], int count) {
    for (int i = 1; i < count; i++) {
        int key = arr[i];         // Element to be inserted
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;  // Insert the key at the correct position
    }
}

int binarySearch(int arr[], int count, int target) {
    int left = 0;
    int right = count - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;             // Found
        else if (arr[mid] < target)
            left = mid + 1;         // Search right half
        else
            right = mid - 1;        // Search left half
    }

    return -1;  // Not found
}
