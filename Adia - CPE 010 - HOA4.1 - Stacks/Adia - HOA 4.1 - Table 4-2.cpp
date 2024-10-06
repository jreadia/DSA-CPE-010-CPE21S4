#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const size_t maxCap = 100;
int stack[maxCap]; // Stack with max of 100 elements
int top = -1, i, newData;

void push();
void pop();
void Top();
void display();
void exit();
bool isEmpty();

int main() {
    int choice;
    cout << "Enter the number of max elements for new stack: ";
    cin >> i;
    cout << endl;

    while (true) {
        cout << "Stack Operations: " << endl;
        cout << "1. PUSH, 2. POP, 3. TOP, 4. isEMPTY, 5. DISPLAY, 6. EXIT" << endl;
        cout << "Enter your choice [number only]: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1: push();
                    break;
            
            case 2: pop();
                    break;

            case 3: Top();
                    break;

            case 4: cout << isEmpty() << endl;
                    break;

            case 5: display();
                    break;

            case 6: exit();
                    break;

            default: cout << "Invalid Choice" << endl;
                    break;

        }
    }

return 0;
}

// Function to check if the stack is empty
bool isEmpty() {
    if (top == -1) 
        return true;
        return false;
}

// Function to push a new element to the stack
void push(){
    //check if full -> if yes, return error 
    if(top == i-1){
    cout << "Stack Overflow." << "\n\n";
    return;
    }   

    cout << "New Value: "; 
    cin >> newData;
    stack[++top] = newData;
    cout << "\n\n";
}

// Function to pop the top element from the stack
void pop(){
    //check if empty -> if yes, return error
    if(isEmpty()){
    cout << "Stack Underflow." << "\n\n";
    return;
    }

    // Display the top value
    cout << "Popping: " << stack[top];
    // Decrement the top value from the stack
    top--;
    cout << "\n\n";
}

// Function to display the top element of the stack
void Top() {
    if(isEmpty()){
    cout << "Stack is Empty." << "\n\n";
    return;
    }

    cout << "The element at the top of the stack is: " << stack[top] << "\n\n";
}

// Function to display the stack
void display() {
    if(isEmpty()){
    cout << "Stack is Empty." << "\n\n";
    return;
    }

    cout << "The stack is: ";
    for(int j = 0; j <= top; j++){
    cout << stack[j] << " ";
    }
    cout << "\n\n";
}

// Function to exit the program
void exit() {
    cout << "Exiting Program." << endl;
    exit(0);
}
