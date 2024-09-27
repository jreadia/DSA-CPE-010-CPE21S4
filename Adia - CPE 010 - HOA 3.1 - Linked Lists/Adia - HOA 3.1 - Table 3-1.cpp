#include<iostream>
#include<utility>
using namespace std;

// Make a class for the node
class Node {
public:
	char data;
	Node *next;
};

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

}