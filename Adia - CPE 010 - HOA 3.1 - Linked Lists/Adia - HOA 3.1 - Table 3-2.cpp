#include<iostream>
#include<utility>
using namespace std;

// Make a class for the node
class Node {
public:
    char data;
    Node *next;
};

// Function to traverse the linked list and print the data of each node
void traverse(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to insert a new node at the head of the linked list
void insert_at_head(Node *&head, char newData) {
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

// Function to insert a new node at a given position in the linked list
void insert_at_any_position(Node *&head, char newData, int position) {
    if (position == 0) {
        insert_at_head(head, newData);
        return;
    }

    Node *newNode = new Node;
    newNode->data = newData;

    Node *current = head;
    for (int i = 0; current != nullptr && i < position - 1; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position out of bounds" << endl;
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Function to insert a new node at the end of the linked list
void insert_at_end(Node *&head, char newData) {
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
}

// Function to delete a node from the linked list
void delete_node(Node *&head, char key) {
    Node *temp = head;
    Node *prev = nullptr;

    // If the head node itself holds the key to be deleted
    if (temp != nullptr && temp->data == key) {
        head = temp->next; // Changed head
        delete temp; // Free old head
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == nullptr) return;

    // Unlink the node from linked list
    prev->next = temp->next;

    delete temp; // Free memory
}

int main() {
    // Step 1: Initialize pointers for each node
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *fourth = NULL;
    Node *fifth = NULL;
    Node *last = NULL;
    
    // Step 2: Allocate memory for each node
    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;
    fifth = new Node;
    last = new Node;
    
    // Step 3: Assign data to each node and link them
    head->data = 'C';
    head->next = second;
    second->data = 'P';
    second->next = third;
    third->data = 'E';
    third->next = fourth;
    fourth->data = '0';
    fourth->next = fifth;
    fifth->data = '1';
    fifth->next = last;
    
    // Step 4: Assign data to the last node and set its next pointer to nullptr
    last->data = '0';
    last->next = nullptr;

    // Traverse the linked list and print the data
    cout << "Original linked list: ";
    traverse(head);
    cout << endl;

    // Insert a new node at the head
    cout << "Inserting a new node at the head. " << endl;
    insert_at_head(head, 'A');
    // Traverse the linked list again to see the new head
    cout << "New linked list: ";
    traverse(head);
    cout << endl;

    // Insert a new node at position 3
    cout << "Inserting a new node at position 3. " << endl;
    insert_at_any_position(head, 'X', 3);
    // Traverse the linked list again to see the new node at position 3
    cout << "New linked list: ";
    traverse(head);
    cout << endl;

    // Insert a new node at the end
    cout << "Inserting a new node at the end. " << endl;
    insert_at_end(head, 'Z');
    // Traverse the linked list again to see the new node at the end
    cout << "New linked list: ";
    traverse(head);
    cout << endl;

    // Delete a node with data 'P'
    cout << "Deleting node with data 'P'. " << endl;
    delete_node(head, 'P');
    // Traverse the linked list again to see the updated list
    cout << "New linked list: ";
    traverse(head);
    cout << endl;

    // Clean up memory
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;
    delete last;

    return 0;
}