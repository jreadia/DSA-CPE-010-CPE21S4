#include<iostream>
using namespace std;

// Make a class for the node
class Node {
public:
    char data;
    Node *next;
    Node *prev;
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
    newNode->prev = nullptr;

    if (head != nullptr) {
        head->prev = newNode;
    }

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
    newNode->prev = current;

    if (current->next != nullptr) {
        current->next->prev = newNode;
    }

    current->next = newNode;
}

// Function to insert a new node at the end of the linked list
void insert_at_end(Node *&head, char newData) {
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

// Function to delete a node from the linked list
void delete_node(Node *&head, char key) {
    Node *temp = head;

    // If the head node itself holds the key to be deleted
    if (temp != nullptr && temp->data == key) {
        head = temp->next; // Changed head
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp; // Free old head
        return;
    }

    // Search for the key to be deleted
    while (temp != nullptr && temp->data != key) {
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == nullptr) return;

    // Unlink the node from linked list
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }

    delete temp; // Free memory
}

int main() {
    // Step 1: Initialize pointers for each node
    Node *head = nullptr;
    Node *second = nullptr;
    Node *third = nullptr;
    Node *fourth = nullptr;
    Node *fifth = nullptr;
    Node *last = nullptr;
    
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
    head->prev = nullptr;
    second->data = 'P';
    second->next = third;
    second->prev = head;
    third->data = 'E';
    third->next = fourth;
    third->prev = second;
    fourth->data = '0';
    fourth->next = fifth;
    fourth->prev = third;
    fifth->data = '1';
    fifth->next = last;
    fifth->prev = fourth;
    
    // Step 4: Assign data to the last node and set its next pointer to nullptr
    last->data = '0';
    last->next = nullptr;
    last->prev = fifth;

    // Traverse the linked list and print the data
    cout << "Original linked list: ";
    traverse(head);
    cout << endl;

    // Insert a new node at the head
    cout << "Inserting a new node at the head. " << endl;
    insert_at_head(head, 'G');
    // Traverse the linked list again to see the new head
    cout << "New linked list: ";
    traverse(head);
    cout << endl;

    // Insert a new node at after 'P' (position 3)
    cout << "Inserting a new node after 'P'. " << endl;
    insert_at_any_position(head, 'E', 3);
    // Traverse the linked list again to see the new node at position 3
    cout << "New linked list: ";
    traverse(head);
    cout << endl;

    // Delete a node with data 'C'
    cout << "Deleting node with data 'C'. " << endl;
    delete_node(head, 'C');
    // Traverse the linked list again to see the updated list
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

    // Outputting the latest linked list
    cout << "Final linked list: ";
    traverse(head);

    // Clean up memory
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}