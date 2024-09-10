// Swapping Numbers in 2 different variables
#include <iostream>
using namespace std;

int main(){
    
    int num1,num2,holder;
    
    // Entering 1st Number
    cout << "Enter the 1st number (num1): ";
    cin >> num1;
    
    // Entering 2nd Number
    cout << "Enter the  2nd number (num2): ";
    cin >> num2;
    
    // Output of original values
    cout << "The firs number is " << num1 << " and the 2nd number is " << num2 << endl;
    
    // Swapping of num1 and num2
    holder = num1;
    num1 = num2;
    num2 = holder;
    
    // Output of swapped values
    cout << "After swapping values, the new value of num1 = " << num1 << " and num2 = " << num2;

return 0;    
}
