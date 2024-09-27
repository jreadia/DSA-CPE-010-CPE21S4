#include <iostream>
#include <string>
using namespace std;

// Define a Song class with a title and a pointer to the next song in the playlist
class Song {
public:
    string title;
    Song* next;

    Song(const string& title) : title(title), next(nullptr) {}
};

// Define a Playlist class with a head and tail pointer to the first and last songs in the playlist
class Playlist {
private:
    Song* head;
    Song* tail;

public:
    
    // Constructor to initialize an empty playlist
    Playlist() : head(nullptr), tail(nullptr) {}

    // Function to add a new song to the playlist
    void add_song(const string& title) {
        Song* newSong = new Song(title);
        if (!head) {
            head = newSong;
            tail = newSong;
            newSong->next = head;
        } else {
            tail->next = newSong;
            tail = newSong;
            tail->next = head;
        }
    }

    // Function to remove a song from the playlist by title
    void remove_song(const string& title) {
        if (!head) return;

        Song* current = head;
        Song* previous = nullptr;

        do {
            if (current->title == title) {
                if (previous) {
                    previous->next = current->next;
                    if (current == tail) {
                        tail = previous;
                    }
                } else {
                    head = head->next;
                    tail->next = head;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != head);
    }

    // Function to play all songs in the playlist
    void play_all_songs() const {
        if (!head) return;

        Song* current = head;
        do {
            cout << "Playing: " << current->title << endl;
            current = current->next;
        } while (current != head);
    }

    // Destructor to free memory allocated for the playlist
    ~Playlist() {
        if (!head) return;

        Song* current = head;
        do {
            Song* nextSong = current->next;
            delete current;
            current = nextSong;
        } while (current != head);
    }
};

// Main function to test the Playlist class
int main() {
    Playlist playlist;

    // Add some songs to the playlist
    playlist.add_song("Song 1");
    playlist.add_song("Song 2");
    playlist.add_song("Song 3");

    // Play all songs in the playlist
    cout << "Playlist:" << endl;
    playlist.play_all_songs();
    cout << endl;

    // Remove a song from the playlist
    cout << "Removing 'Song 2' from playlist." << endl;
    playlist.remove_song("Song 2");
    cout << endl;

    // Play all songs in the updated playlist
    cout << "Updated Playlist:" << endl;
    playlist.play_all_songs();

    return 0;
}