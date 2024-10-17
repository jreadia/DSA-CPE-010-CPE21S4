#include <iostream>
#include "sorting algorithms.h"

using std::cout;
using std::endl;


int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSort(arr, arrSize);

    cout << "Sorted array: ";
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}