#include <iostream>
#include <stack>
using namespace std;

// Setting the maximum size of the stack
const int MAX_SIZE = 3; 

// Function to display the stack
void display(stack<string>& pl) {
    while (!pl.empty()) {
        cout << pl.top() << endl;
        pl.pop();
    } 
    cout << endl;
}

// Function to check if the stack is full
bool isFull(const stack<string>& pl) {
    return pl.size() >= MAX_SIZE;
}

// Function to push items to the stack
void pushToStack(stack<string>& pl, const string& item) {
    if (!isFull(pl)) {
        pl.push(item);
        cout << "Added: " << item << endl;
    } else {
        cout << "Stack is full. Cannot add: " << item << endl;
    }
}

int main() {

    // Variable declaration to hold the stack
    stack<string> pl;
    cout << "Pushing elements into stack: \n";

    // Add items to the stack
    pushToStack(pl, "C++");
    pushToStack(pl, "Java");
    pushToStack(pl, "Python");
    pushToStack(pl, "JavaScript");
    
    // Display the added items in the stack
    cout << endl;
    cout << "The items in the stack are: \n";
    display(pl);

    return 0;
}