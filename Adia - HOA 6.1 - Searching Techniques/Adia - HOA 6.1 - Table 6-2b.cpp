#include <iostream>

// Define the Node structure
template <typename T>
struct Node {
    T data;
    Node* next;
};

// Function to create a new node
template <typename T>
Node<T>* new_node(T data) {
    Node<T>* node = new Node<T>;
    node->data = data;
    node->next = nullptr;
    return node;
}

// Function to perform linear search on a linked list
template <typename T>
bool linearLS(Node<T>* head, T dataFind) {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == dataFind) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int main() {
    // Create linked list for linear search
    Node<char> *name1 = new_node('J');
    Node<char> *name2 = new_node('a');
    Node<char> *name3 = new_node('m');
    Node<char> *name4 = new_node('e');
    Node<char> *name5 = new_node('s');

    // Link each node to each other
    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = nullptr;

    // Output the linked list created
    std::cout << "Linked list created: ";
    Node<char>* current = name1;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Setting the data to find
    char dataFind = 'n';
    std::cout << "Data to find: " << dataFind << std::endl;

    // Perform linear search
    if (linearLS(name1, dataFind)) {
        std::cout << "Element '" << dataFind << "' found in the linked list." << std::endl;
    } else {
        std::cout << "Element '" << dataFind << "' not found in the linked list." << std::endl;
    }

    // Clean up memory
    delete name1;
    delete name2;
    delete name3;
    delete name4;
    delete name5;

    return 0;
}