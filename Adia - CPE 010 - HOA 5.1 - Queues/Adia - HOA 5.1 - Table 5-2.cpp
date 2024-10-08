#include <iostream>
#include <queue>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::queue;

struct Node {
    string data;
    Node* next;
};

class Queue {

private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Inserting an item into a non-empty queue
    void enqueue(string item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = nullptr;

        if (front == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
            cout << "Item inserted into non-empty queue: " << rear->data << endl;
        }
    }

    // Inserting an item into an empty queue
    void enqueueEmpty(string item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = nullptr;

        front = newNode;
        rear = newNode;
        cout << "Item inserted into empty queue: " << front->data << endl;
    }

    // Deleting an item from a queue of more than one item
    void dequeueMultiple() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        cout << "Item deleted from queue: " << temp->data << endl;
        delete temp;
    }

    // Deleting an item from a queue with one item
    void dequeueSingle() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        front = nullptr;
        rear = nullptr;
        cout << "Item deleted from queue: " << temp->data << endl;
        delete temp;
    }

    // Display the queue
    void displayQueue() {
        if (front == nullptr) {
            cout << "Current items in the queue: --- No Items ---" << endl;
            return;
        }
        Node* temp = front;
        cout << "Current items in the queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    // Display the original queue
    cout << "Original queue: ";
    queue.displayQueue();
    cout << endl;

    // Inserting an item into an empty queue
    queue.enqueueEmpty("James");
    queue.displayQueue();
    cout << endl;

    // Inserting an item into a non-empty queue
    queue.enqueue("Gob");
    queue.enqueue("Aries");
    queue.displayQueue();
    cout << endl;

    // Deleting an item from a queue of more than one item
    queue.dequeueMultiple();
    queue.dequeueMultiple();
    queue.displayQueue();
    cout << endl;

    // Deleting an item from a queue with one item
    queue.dequeueSingle();
    queue.displayQueue();

    return 0;
}