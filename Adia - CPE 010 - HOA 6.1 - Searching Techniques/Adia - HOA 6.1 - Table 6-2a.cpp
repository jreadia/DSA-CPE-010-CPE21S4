#include <iostream>
#include "searching.h"


int main() {
   
    // Set up the dataset
    int dataset[] = {10, 20, 30, 40, 50};
    int n = sizeof(dataset) / sizeof(dataset[0]);
   
    // Find the number 30 from the dataset
    int item = 30;
    std::cout << "Searching for item: " << item << std::endl;


    // Function to perform linear search
    int result = linearSearch(dataset, n, item);
    if (result != -1) {
        std::cout << "Item " << item << " found at index: " << result << std::endl;
    } else {
        std::cout << "Item not found" << std::endl;
    }


    return 0;
}
