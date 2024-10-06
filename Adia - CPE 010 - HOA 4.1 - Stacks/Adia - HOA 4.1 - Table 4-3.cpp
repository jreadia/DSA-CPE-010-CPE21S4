#include <iostream>
using std::cout;
using std::endl;

class Node{ 
public:
    int data; 
    Node *next;
};

Node *head=NULL,*tail=NULL; 

void push(int newData){
    Node *newNode = new Node; 
    newNode->data = newData; 
    newNode->next = head;

    if(head==NULL){
        head = tail = newNode;
    } else {
        newNode->next = head; 
        head = newNode;
    }
}

// Function to pop the top element from the stack
int pop(){
    int tempVal;
    Node *temp;
    if(head == NULL){
        head = tail = NULL;
        cout << "Stack Underflow." << endl; 
        return -1;
    } else {
        temp = head;
        tempVal = temp->data; 
        head = head->next; 
        delete(temp);
        return tempVal;
    }
}

// Function to display the top element of the stack
void Top(){
    if(head==NULL){
        cout << "Stack is Empty." << endl; 
        return;
    } else {
        cout << "Top of Stack: " << head->data << endl;
    }
}

// Function to display the stack
void displayStack() {
    if (head == NULL) {
        cout << "Stack is Empty." << endl;
        return;
    }
    Node *temp = head;
    cout << "Stack elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){

    push(1);
    cout << "After the first PUSH top of the stack is: ";
    Top();
    displayStack();
    
    push(5);
    cout << "After the second PUSH top of the stack is: ";
    Top();
    displayStack();

    pop();
    cout << "After the first POP operation, top of the stack is: ";
    Top();
    displayStack();

    pop();
    cout << "After the second POP operation, top of the stack is: ";
    Top();

    displayStack();
    pop();

    return 0;
}