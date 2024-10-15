#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;
    int mid;

    while (left <= right) {
        mid = left + (right - left) / 2;
        cout << "Left: " << left << ", Mid: " << mid << ", Right: " << right << ", Mid Value: " << arr[mid] << endl;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Key not found
}

int main() {
    vector<int> sortedList = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int key = 8;

    int result = binarySearch(sortedList, key);

    if (result != -1) {
        cout << "Key " << key << " found at index " << result << endl;
    } else {
        cout << "Key " << key << " not found in the list" << endl;
    }

    return 0;
}