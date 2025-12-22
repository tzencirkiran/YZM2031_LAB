/**
 * Problem 1: The Music Streaming Playlist
 * 
 * Implement Merge Sort to sort songs by play count (descending).
 * The sort must be STABLE - songs with equal play counts keep their relative order.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Song {
    string name;
    int playCount;
    
    Song(string n, int p) : name(n), playCount(p) {}
};

// Merge two sorted subarrays into one sorted array
// Left subarray: arr[left..mid]
// Right subarray: arr[mid+1..right]
// Sort by playCount in DESCENDING order (higher plays first)
// IMPORTANT: Must be stable - if two songs have the same playCount,
// the one that appeared first in the original array should come first
void merge(vector<Song>& arr, int left, int mid, int right) {
    // Implement this
}

// Recursive Merge Sort
void mergeSort(vector<Song>& arr, int left, int right) {
    // Implement this
}

void printPlaylist(const vector<Song>& songs) {
    cout << "Playlist:" << endl;
    for (const auto& song : songs) {
        cout << "  " << song.name << " - " << song.playCount << " plays" << endl;
    }
}

int main() {
    cout << "=== Music Streaming Playlist Sorter ===" << endl;
    
    // Test 1: Basic sorting with stability check
    cout << "\n--- Test 1: Stability Check ---" << endl;
    vector<Song> playlist1 = {
        Song("Alpha", 100),
        Song("Beta", 200),
        Song("Charlie", 100),  // Same as Alpha
        Song("Delta", 150),
        Song("Echo", 100)      // Same as Alpha and Charlie
    };
    
    cout << "Before sorting:" << endl;
    printPlaylist(playlist1);
    
    mergeSort(playlist1, 0, playlist1.size() - 1);
    
    cout << "\nAfter sorting (descending by plays):" << endl;
    printPlaylist(playlist1);
    cout << "Expected order: Beta(200), Delta(150), Alpha(100), Charlie(100), Echo(100)" << endl;
    cout << "Note: Alpha, Charlie, Echo should maintain their relative order!" << endl;
    
    // Test 2: Already sorted
    cout << "\n--- Test 2: Already Sorted Input ---" << endl;
    vector<Song> playlist2 = {
        Song("Song1", 500),
        Song("Song2", 400),
        Song("Song3", 300),
        Song("Song4", 200),
        Song("Song5", 100)
    };
    
    cout << "Before sorting:" << endl;
    printPlaylist(playlist2);
    
    mergeSort(playlist2, 0, playlist2.size() - 1);
    
    cout << "\nAfter sorting:" << endl;
    printPlaylist(playlist2);
    
    // Test 3: Reverse sorted
    cout << "\n--- Test 3: Reverse Sorted Input ---" << endl;
    vector<Song> playlist3 = {
        Song("Track1", 100),
        Song("Track2", 200),
        Song("Track3", 300),
        Song("Track4", 400),
        Song("Track5", 500)
    };
    
    cout << "Before sorting:" << endl;
    printPlaylist(playlist3);
    
    mergeSort(playlist3, 0, playlist3.size() - 1);
    
    cout << "\nAfter sorting:" << endl;
    printPlaylist(playlist3);

    return 0;
}
