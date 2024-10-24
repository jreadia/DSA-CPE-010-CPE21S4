#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
Node<T>* new_node(T data) {
    Node<T>* node = new Node<T>();
    node->data = data;
    node->next = nullptr;
    return node;
}

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last) {
    if (start == nullptr) return nullptr;

    Node<T>* slow = start;
    Node<T>* fast = start->next;

    while (fast != last) {
        fast = fast->next;
        if (fast != last) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

template <typename T>
Node<T>* binarySearch(Node<T>* head, T key) {
    Node<T>* start = head;
    Node<T>* last = nullptr;

    do {
        Node<T>* mid = getMiddle(start, last);
        if (mid == nullptr) return nullptr;
        if (mid->data == key) return mid;
        else if (mid->data < key) start = mid->next;
        else last = mid;

    } while (last == nullptr || last != start);

    return nullptr;
}

int main() {
    char choice = 'y';
    int count = 1;
    int newData;
    Node<int>* temp, * head = nullptr, * node;

    while (choice == 'y') {
        std::cout << "Enter data: ";
        std::cin >> newData;
        if (count == 1) {
            head = new_node(newData);
            std::cout << "Successfully added " << head->data << " to the list.\n";
            count++;
        }
        else if (count == 2) {
            node = new_node(newData);
            head->next = node;
            node->next = nullptr;
            std::cout << "Successfully added " << node->data << " to the list.\n";
            count++;
        }
        else {
            temp = head;
            while (true) {
                if (temp->next == nullptr) 
                    break;
                temp = temp->next;
            }
            node = new_node(newData);
            temp->next = node;
            std::cout << "Successfully added " << node->data << " to the list.\n";
            count++;
        }
        std::cout << "Continue? (y/n): ";
        std::cin >> choice;
        if (choice == 'n') 
            break;
    }

    // Display the linked list
    Node<int>* currNode = head;
    while (currNode != nullptr) {
        std::cout << currNode->data << " ";
        currNode = currNode->next;
    }
    std::cout << std::endl;

    // Perform binary search
    int key;
    std::cout << "Enter the value to search: ";
    std::cin >> key;
    Node<int>* result = binarySearch(head, key);
    if (result != nullptr) {
        std::cout << "Element " << key << " found in the list.\n";
    }
    else {
        std::cout << "Element " << key << " not found in the list.\n";
    }

    return 0;
}