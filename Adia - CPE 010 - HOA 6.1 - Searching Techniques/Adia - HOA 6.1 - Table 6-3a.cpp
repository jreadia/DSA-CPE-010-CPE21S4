#include <iostream>
#include "searching.h"

int main(){
    
    // Setting up the data
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(data) / sizeof(data[0]);
    int item = 5;
    std::cout << "Searching for element: " << item << std::endl;
    
    // Searching for the element using linear search
    int result = linearSearch(data, n, item);
    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    // Searching for the element using binary search
    result = binarySearch(data, n, item);
    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }
    return 0;
}