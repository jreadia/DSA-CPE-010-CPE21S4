#include <iostream>
#include <queue>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::queue;

class CircularQueue {
private:
    int* q_array;
    int q_capacity;
    int q_size;
    int q_front;
    int q_back;

public:
    // Constructor
    CircularQueue(int capacity) : q_capacity(capacity), q_size(0), q_front(0), q_back(-1) {
        q_array = new int[q_capacity];
    }

    // Destructor
    ~CircularQueue() {
        delete[] q_array;
    }

    // Copy Constructor
    CircularQueue(const CircularQueue& other) : q_capacity(other.q_capacity), q_size(other.q_size), q_front(other.q_front), q_back(other.q_back) {
        q_array = new int[q_capacity];
        for (int i = 0; i < q_capacity; ++i) {
            q_array[i] = other.q_array[i];
        }
    }

    // Copy Assignment Operator
    CircularQueue& operator=(const CircularQueue& other) {
        if (this != &other) {
            delete[] q_array;
            q_capacity = other.q_capacity;
            q_size = other.q_size;
            q_front = other.q_front;
            q_back = other.q_back;
            q_array = new int[q_capacity];
            for (int i = 0; i < q_capacity; ++i) {
                q_array[i] = other.q_array[i];
            }
        }
        return *this;
    }

    // Test whether container is empty
    bool Empty() const {
        return q_size == 0;
    }

    // Return size
    int Size() const {
        return q_size;
    }

    // Clear the queue
    void Clear() {
        q_size = 0;
        q_front = 0;
        q_back = -1;
    }

    // Access next element
    int Front() const {
        if (Empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return q_array[q_front];
    }

    // Access last element
    int Back() const {
        if (Empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return q_array[q_back];
    }

    // Insert element
    void Enqueue(int value) {
        if (q_size == q_capacity) {
            throw std::overflow_error("Queue is full");
        }
        q_back = (q_back + 1) % q_capacity;
        q_array[q_back] = value;
        ++q_size;
    }

    // Remove next element
    void Dequeue() {
        if (Empty()) {
            throw std::underflow_error("Queue is empty");
        }
        q_front = (q_front + 1) % q_capacity;
        --q_size;
    }
};

// Test the CircularQueue class
int main() {
    CircularQueue q(5);

    // Enqueue elements
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);

    // Display Front and Back elements
    cout << "Front element: " << q.Front() << endl;
    cout << "Back element: " << q.Back() << endl;

    // Dequeue an element
    q.Dequeue();
    cout << "Front element after dequeue: " << q.Front() << endl;

    // Clear the queue
    q.Clear();
    cout << "Queue size after clear: " << q.Size() << endl;

    return 0;
}