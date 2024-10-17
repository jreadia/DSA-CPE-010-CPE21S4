#include <iostream>
#include "sorting algorithms.h"

using std::cout;
using std::endl;

int main() {
    
    // Array to be sorted
    int arr[] = {5, 3, 8, 4, 2};
    size_t arrSize = sizeof(arr) / sizeof(arr[0]);

    // Sorting the array using bubble sort from the header file sorting algorithms.h
    bubbleSort(arr, arrSize);
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

return 0;
}
