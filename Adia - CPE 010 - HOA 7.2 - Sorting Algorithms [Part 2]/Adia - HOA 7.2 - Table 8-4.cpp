#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting algorithms.h" // Include the header file

using std::cout;
using std::endl;
using std::srand;
using std::time;

// Setting the max size of the array to 100
const int SIZE = 100;
int arr[SIZE];

// Function for the number generator
void number_generator() {
    // Seeding the random number generator
    srand(time(0));
   
    // Fill the array with random values
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100; // Random values between 0 and 99
    }
   
    // Print the unsorted array
    cout << "Unsorted array:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    number_generator(); // Call the number generator function
    // Sort the array using Quick Sort
    quickSort(arr, 0, SIZE - 1); // Call the sorting function

    // Print the sorted array
    cout << "Sorted array using Quick Sort:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}