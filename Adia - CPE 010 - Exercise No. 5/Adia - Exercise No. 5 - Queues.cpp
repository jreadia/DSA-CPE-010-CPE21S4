#include <iostream>
#include <queue>
using namespace std;

// Function to display the queue
void display(queue<string> pl) {
    while (!pl.empty()) {
        cout << pl.front() << endl;
        pl.pop();
    }
    cout << endl;
}

int main() {

    // Variable declaration to hold the queue
    queue<string> pl;
    cout << "The items in the queue are \n";
    
    // Add items to the queue
    pl.push("C++");
    pl.push("Java");
    pl.push("Python");
    display(pl);

    return 0;
}