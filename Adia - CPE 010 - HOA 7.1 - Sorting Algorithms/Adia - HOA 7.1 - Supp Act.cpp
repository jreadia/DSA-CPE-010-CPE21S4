#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting algorithms.h"

using std::cout;
using std::endl;

// Setting the size of the array and the number of candidates
const int ARRAY_SIZE = 100;
const int NUM_CANDIDATES = 5;

// Function to generate random votes
void generateVotes(int arr[], int size) {
    std::srand(std::time(0));
    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand() % NUM_CANDIDATES + 1;
    }
}

// Function to count the votes
void countVotes(int arr[], int size, int voteCount[], int numCandidates) {
    for (int i = 0; i < size; ++i) {
        voteCount[arr[i] - 1]++;
    }
}

// Function to find the winner
int findWinner(int voteCount[], int numCandidates) {
    int maxVotes = 0;
    int winner = 0;
    for (int i = 0; i < numCandidates; ++i) {
        if (voteCount[i] > maxVotes) {
            maxVotes = voteCount[i];
            winner = i + 1;
        }
    }
    return winner;
}

int main() {
    int votes[ARRAY_SIZE];
    int voteCount[NUM_CANDIDATES] = {0};

    generateVotes(votes, ARRAY_SIZE);
    cout << "Unsorted votes: ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cout << votes[i] << " ";
    }

    // Using insertion sort from the created "sorting algorithms.h" header file to sort the votes
    insertionSort(votes, ARRAY_SIZE);
    cout << "\nSorted votes: ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cout << votes[i] << " ";
    }

    countVotes(votes, ARRAY_SIZE, voteCount, NUM_CANDIDATES);
    cout << "\nVote count: \n";
    for (int i = 0; i < NUM_CANDIDATES; ++i) {
        cout << "Candidate " << i + 1 << ": " << voteCount[i] << endl;
    }

    int winner = findWinner(voteCount, NUM_CANDIDATES);
    cout << "The winning candidate is Candidate " << winner << " with " << voteCount[winner - 1] << " votes." << endl;

    return 0;
}