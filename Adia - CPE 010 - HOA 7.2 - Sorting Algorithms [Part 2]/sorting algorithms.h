#ifndef SORTING_ALGORITHMS
#define SORTING_ALGORITHMS


// ---------- Function to sort an array using Shell Sort ---------- //
void shellSort(int array[], int size) {
    
    // Start with a gap that is half the size of the array and reduce it
    for (int interval = size / 2; interval > 0; interval /= 2) {
        
        // Go through the array elements starting from the current gap
        for (int i = interval; i < size; i++) {
            // Save the current element to a temporary variable
            int temp = array[i];
            int j;

            // Move elements that are greater than temp to the right
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
                array[j] = array[j - interval]; // Shift the element
            }
            
            // Place the saved element (temp) in its correct position
            array[j] = temp;
        }
    }
}

// ---------- Function to sort an array using Merge Sort ---------- //
void merge(int array[], int left, int middle, int right) {
    // Calculate the sizes of the two subarrays to be merged
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays to hold the elements of the subarrays
    int* leftArray = new int[n1];
    int* rightArray = new int[n2];

    // Copy data to temporary arrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = array[middle + 1 + j];

    // Merge the temporary arrays back into array[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if any
    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if any
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }

    // Deallocate the memory for temporary arrays
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int array[], int left, int right) {
    // If the array has one or no elements, it is already sorted
    if (left >= right)
        return;

    // Find the middle point to divide the array into two halves
    int middle = left + (right - left) / 2;

    // Recursively sort the first and second halves
    mergeSort(array, left, middle);
    mergeSort(array, middle + 1, right);

    // Merge the sorted halves
    merge(array, left, middle, right);
}

// ---------- Function to sort an array using Quick Sort ---------- //
int partition(int array[], int low, int high) {
    int pivot = array[high]; // Choose the rightmost element as pivot
    int i = (low - 1); // Pointer for the greater element

    // Traverse through all elements
    // Compare each element with pivot
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++; // If element smaller than pivot is found, swap it
            std::swap(array[i], array[j]);
        }
    }

    // Swap the pivot element with the greater element specified by i
    std::swap(array[i + 1], array[high]);

    // Return the position from where partition is done
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        // Find the pivot element such that
        // elements smaller than pivot are on the left
        // elements greater than pivot are on the right
        int pivot = partition(array, low, high);

        // Recursively sort the elements before and after partition
        quickSort(array, low, pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}

#endif

