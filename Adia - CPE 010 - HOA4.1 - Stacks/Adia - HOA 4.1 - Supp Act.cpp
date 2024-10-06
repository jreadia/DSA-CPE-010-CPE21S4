#include <iostream>
#include <string>
#include <stack>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stack;

// Stack implementation using arrays
class ArrayStack {
private:
    static const int MAX = 1000;
    int top;
    char a[MAX]; // Maximum size of Stack

public:
    ArrayStack() { top = -1; }
    bool push(char x) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow\n";
            return false;
        } else {
            a[++top] = x;
            return true;
        }
    }
    char pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return 0;
        } else {
            char x = a[top--];
            return x;
        }
    }
    bool isEmpty() {
        return (top < 0);
    }
};

// Stack implementation using linked lists
class LinkedListStack {
private:
    struct Node {
        char data;
        Node* next;
    };
    Node* top;

public:
    LinkedListStack() { top = nullptr; }
    void push(char x) {
        Node* temp = new Node();
        if (!temp) {
            cout << "Heap Overflow\n";
            return;
        }
        temp->data = x;
        temp->next = top;
        top = temp;
    }
    char pop() {
        if (top == nullptr) {
            cout << "Stack Underflow\n";
            return 0;
        }
        Node* temp = top;
        top = top->next;
        char popped = temp->data;
        delete temp;
        return popped;
    }
    bool isEmpty() {
        return top == nullptr;
    }
};

// Function to check if the given character is an opening delimiter
bool isOpening(char ch) {
    return (ch == '(' || ch == '{' || ch == '[');
}

// Function to check if the given character is a closing delimiter
bool isClosing(char ch) {
    return (ch == ')' || ch == '}' || ch == ']');
}

// Function to check if the opening and closing delimiters match
bool isMatching(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
            (opening == '{' && closing == '}') ||
            (opening == '[' && closing == ']'));
}

// Function to check for balanced symbols using ArrayStack
bool checkBalancedSymbolsArray(const string& expr) {
    ArrayStack stack;
    for (char ch : expr) {
        if (isOpening(ch)) {
            stack.push(ch);
        } else if (isClosing(ch)) {
            if (stack.isEmpty() || !isMatching(stack.pop(), ch)) {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

// Function to check for balanced symbols using LinkedListStack
bool checkBalancedSymbolsLinkedList(const string& expr) {
    LinkedListStack stack;
    for (char ch : expr) {
        if (isOpening(ch)) {
            stack.push(ch);
        } else if (isClosing(ch)) {
            if (stack.isEmpty() || !isMatching(stack.pop(), ch)) {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    if (checkBalancedSymbolsArray(expr)) {
        cout << "Balanced using ArrayStack\n";
    } else {
        cout << "Not Balanced using ArrayStack\n";
    }

    if (checkBalancedSymbolsLinkedList(expr)) {
        cout << "Balanced using LinkedListStack\n";
    } else {
        cout << "Not Balanced using LinkedListStack\n";
    }

    return 0;
}