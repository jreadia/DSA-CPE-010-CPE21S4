#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting algorithms.h" // Include the header file

using std::cout;
using std::endl;
using std::srand;
using std::time;

// ---------- Quick Sort function that uses other sorting algorithms for sublists ---------- //
void quickSort_others(int array[], int low, int high) {
    if (low < high) {
        // Partition the array
        int pi = partition(array, low, high);

        // Sort the left sublist using Shell Sort
        shellSort(array + low, pi - low);

        // Sort the right sublist using Merge Sort
        mergeSort(array, pi + 1, high);
    }
}

int main(){

    const int size = 20;
    int array[size];

    // Seed for random number generation
    srand(time(0));

    // Generate random numbers and fill the array
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100; // Random numbers between 0 and 99
    }

    // Print the original array
    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Perform Quick Sort
    quickSort_others(array, 0, size - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

return 0;
}
