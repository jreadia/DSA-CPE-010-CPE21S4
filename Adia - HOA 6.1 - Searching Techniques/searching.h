#ifndef SEARCHING_H
#define SEARCHING_H


#include <iostream>


int linearSearch(int data[], int n, int item) {
    for (int i = 0; i < n; ++i) {
        if (data[i] == item) {
            std::cout << "Searching is successful" << std::endl;
            return i;
        }
    }
    std::cout << "Searching is unsuccessful" << std::endl;
    return -1;
}

int binarySearch(int data[], int n, int item) {
    int low = 0, up = n - 1;
    while (low <= up) {
        int mid = (low + up) / 2;
        if (data[mid] == item) {
            std::cout << "Search element is found!" << std::endl;
            return mid;
        } else if (data[mid] < item) {
            low = mid + 1;
        } else {
            up = mid - 1;
        }
    }
    std::cout << "Search element is not found" << std::endl;
    return -1;
}


#endif // SEARCHING_H
