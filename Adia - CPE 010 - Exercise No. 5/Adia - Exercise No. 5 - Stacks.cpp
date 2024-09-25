#include <iostream>
#include <stack>
using namespace std;

// Function to display the stack
void display(stack<string> pl) {
    while (!pl.empty()) {
        cout << pl.top() << endl;
        pl.pop();
    }
    cout << endl;
}

int main() {

    // Variable declaration to hold the stack
    stack<string> pl;
    cout << "The items in the stack are: \n";
    
    // Add items to the stack
    pl.push("C++");
    pl.push("Java");
    pl.push("Python");
    display(pl);

    return 0;
}