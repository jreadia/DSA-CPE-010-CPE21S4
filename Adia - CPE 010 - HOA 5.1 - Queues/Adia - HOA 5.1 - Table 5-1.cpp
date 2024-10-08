#include <iostream>
#include <queue>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::queue;

// Function to display queue
void display(queue <string> q)
{
    queue <string> c = q;
    cout << "The queue of students is:";
    while (!c.empty())
    {
    cout << " " << c.front();
    c.pop();
    }
    cout << "\n";
}

int main() {
    queue<string> studentQueue ;

    // Array of students' names
    string students[] = {"James", "Gob", "Aries", "Aaron", "Isaac"};

    // Add students to the queue
    for (int i = 0; i < 5; i++) {
        studentQueue.push(students[i]);
    }

    // Print the queue
    display(studentQueue);

return 0;
}


