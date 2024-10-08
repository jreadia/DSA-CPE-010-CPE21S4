// Creating a node
#include <iostream>
using namespace std;


class Node {
    public:
        int value;
        Node* next;
};

int main() {
    Node* head;
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL;

    // allocate 3 nodes in the heap
    one = new Node();
    two = new Node();
    three = new Node();

    // Assigning data values
    one->value = 1;
    two->value = 2;
    three->value = 3;

    // Connect nodes
    one->next = two;
    two->next = three;
    three->next = NULL;

    // Print the linked list value
    head = one;
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }

    return 0;
}