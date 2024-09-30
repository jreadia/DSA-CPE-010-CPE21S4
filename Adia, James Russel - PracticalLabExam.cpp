/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <queue>
using namespace std;

// Function to display the current items in the queue
void display_items(queue<string> queue){
  while (!queue.empty()) {
    cout << queue.front() << endl;
    queue.pop();
  }
  cout << endl;
}

// Function to display that the item insertion is successful
void inserted_items(queue<string> queue) {
    while (!queue.empty()) {
        cout << queue.front() << " has been inserted successfully. \n";
        queue.pop();
    }
    cout << endl;
}

// Function to display that the item in the queue is being deleted
void deleted_items(queue<string> queue){
  while (!queue.empty()) {
    cout << queue.front() << " is being deleted \n";
    queue.pop();
  }
  cout << endl;
}

// Main program that will run
int main() {
    
    // Assigning data type string as a queue
    queue<string> numbers;
    
    // Opening statement
    cout << "Underflow. \n";
    
    // Inserting items to the queue
    numbers.push("10");
    numbers.push("24");
    numbers.push("28");
    numbers.push("32");
    numbers.push("30");
    
    // Insertion of Items to the queue
    inserted_items(numbers);
    
    // Display of the inserted items in queue
    display_items(numbers);
    
    // Deletion of all items in the queue
    deleted_items(numbers);
    // While loop to make sure that there will be no items in the queue
    while (!numbers.empty()) {
      numbers.pop();
    }
    
    
return 0;
}
