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

// Function to pop all items from the stack until it becomes empty
void popItems(stack<string> pl) {
    while (!pl.empty()) {
        cout << "Popping: " << pl.top() << endl;
        pl.pop();
    }
    cout << "Stack is already empty. Cannot pop items anymore." << endl;
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

    // Pop all items from the stack
    popItems(pl);

    return 0;
}