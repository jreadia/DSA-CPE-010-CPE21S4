#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::srand;
using std::time;

// Setting the max size of the array to 100
const int SIZE = 100;
int arr[SIZE];

// Function for the number generator
int number_generator(){
    
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
    return -1;
}

// Main Program that runs
int main() {

    number_generator();

return 0;
}

