// ILO A - Basic C++ Code Structure
#include <iostream>
using namespace std;

// Function to display the sum of two numbers
void displaySum(float a, float b) {
    float sum = a + b;
    cout << "Sum: " << sum << endl;
}

// Function to check if variable A is greater than variable B
bool isAGreaterThanB(float a, float b) {
    if (a > b) {
        return true;
    } else {
        return false;
    }
}

/*

Function to display the result of all logical operations on two Boolean values
and return true if it was a success

*/ 
bool performLogicalOperations(bool value1, bool value2) {
    cout << "AND: " << (value1 && value2) << endl;
    cout << "OR: " << (value1 || value2) << endl;
    cout << "NOT value1: " << !value1 << endl;
    cout << "NOT value2: " << !value2 << endl;
    return true;
}

int main() {
    // Call each function
    displaySum(5, 3);
    
    bool result = isAGreaterThanB(10, 5);
    if (result == true) {
        cout << "A is greater than B" << endl;
    } else {
        cout << "A is not greater than B" << endl;
    }

    
    bool success = performLogicalOperations(true, false);
    cout << "Logical operations success: " << success << endl;
    
    return 0;
}