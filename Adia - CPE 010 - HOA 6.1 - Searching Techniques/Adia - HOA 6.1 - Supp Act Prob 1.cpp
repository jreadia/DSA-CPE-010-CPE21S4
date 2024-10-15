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
    int comparisons = 0;
    Node* temp = head;
    while (temp != nullptr) {
        comparisons++;
        if (temp->data == key) {
            return comparisons;
        }
        temp = temp->next;
    }
    return comparisons;
}

// Function to perform sequential search on array
int sequentialSearchArray(int arr[], int size, int key) {
    int comparisons = 0;
    for (int i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == key) {
            return comparisons;
        }
    }
    return comparisons;
}

int main() {
    // Array approach
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 18;
    int comparisonsArray = sequentialSearchArray(arr, size, key);
    cout << "Using Array: Number of comparisons to find " << key << " is " << comparisonsArray << endl;

    // Linked list approach
    Node* head = nullptr;
    for (int i = 0; i < size; i++) {
        appendNode(head, arr[i]);
    }
    int comparisonsLinkedList = sequentialSearchLinkedList(head, key);
    cout << "Using Linked List: Number of comparisons to find " << key << " is " << comparisonsLinkedList << endl;

    return 0;
}