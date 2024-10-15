#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to append a node to the linked list
void appendNode(Node*& head, int data) {
    if (head == nullptr) {
        head = createNode(data);
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = createNode(data);
    }
}

// Function to perform sequential search on linked list
int sequentialSearchLinkedList(Node* head, int key) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

// Function to perform sequential search on array
int sequentialSearchArray(int arr[], int size, int key) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            count++;
        }
    }
    return count;
}

int main() {
    // Array approach
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 18;
    int countArray = sequentialSearchArray(arr, size, key);
    cout << "Using Array: Number of occurrences of " << key << " is " << countArray << endl;

    // Linked list approach
    Node* head = nullptr;
    for (int i = 0; i < size; i++) {
        appendNode(head, arr[i]);
    }
    int countLinkedList = sequentialSearchLinkedList(head, key);
    cout << "Using Linked List: Number of occurrences of " << key << " is " << countLinkedList << endl;

    return 0;
}
