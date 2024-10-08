#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Job {
public:
    int id;
    string user;
    int pages;

    Job() : id(0), user(""), pages(0) {}
    Job(int id, string user, int pages) : id(id), user(user), pages(pages) {}
};

class Printer {
private:
    static const int MAX_JOBS = 100; // Maximum number of jobs the printer can handle
    Job jobArray[MAX_JOBS];
    int front;
    int rear;
    int count;

public:
    Printer() : front(0), rear(0), count(0) {}

    // Add a job to the queue
    void addJob(int id, string user, int pages) {
        if (count < MAX_JOBS) {
            jobArray[rear] = Job(id, user, pages);
            rear = (rear + 1) % MAX_JOBS;
            count++;
            cout << "Job added: " << id << " by " << user << " with " << pages << " pages." << endl;
        } else {
            cout << "Queue is full. Cannot add more jobs." << endl;
        }
    }

    // Process all jobs in the queue
    void processJobs() {
        while (count > 0) {
            Job currentJob = jobArray[front];
            front = (front + 1) % MAX_JOBS;
            count--;
            cout << endl;
            cout << "Processing job: " << currentJob.id << " by " << currentJob.user << " with " << currentJob.pages << " pages." << endl;
            cout << endl;

            // Simulate printing time
            for (int i = 0; i < currentJob.pages; ++i) {
                cout << "Printing page " << (i + 1) << " of " << currentJob.pages << " for job " << currentJob.id << endl;
            }
        }
        cout << endl;
        cout << "All jobs processed." << endl;
    }
};

int main() {
    Printer printer;

    // Add jobs to the printer
    printer.addJob(1, "Evan", 5);
    printer.addJob(2, "Aaron", 3);
    printer.addJob(3, "Paul", 7);
    cout << endl;

    // Process all jobs in the queue
    printer.processJobs();

    return 0;
}