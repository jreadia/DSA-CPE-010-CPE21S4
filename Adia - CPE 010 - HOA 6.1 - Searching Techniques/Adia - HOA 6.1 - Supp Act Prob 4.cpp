#include <iostream>
#include <vector>

using namespace std;

int binarySearchRecursive(const vector<int>& arr, int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        cout << "Left: " << left << ", Mid: " << mid << ", Right: " << right << ", Mid Value: " << arr[mid] << endl;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            return binarySearchRecursive(arr, mid + 1, right, key);
        } else {
            return binarySearchRecursive(arr, left, mid - 1, key);
        }
    }

    return -1; // Key not found
}

int main() {
    vector<int> sortedList = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int key = 8;

    int result = binarySearchRecursive(sortedList, 0, sortedList.size() - 1, key);

    if (result != -1) {
        cout << "Key " << key << " found at index " << result << endl;
    } else {
        cout << "Key " << "key not found in the list" << endl;
    }

    return 0;
}
