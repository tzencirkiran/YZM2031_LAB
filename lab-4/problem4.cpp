/**
 * Problem 4: The Sorting Consultant
 * 
 * You have started a consulting company specializing in algorithm optimization.
 * Today, three different clients have come to you with sorting problems.
 * Each client has DIFFERENT constraints, and you must choose the RIGHT algorithm
 * for each situation.
 * 
 * Your job: Analyze each client's requirements and implement the BEST sorting
 * algorithm for their specific use case. Justify your choice in comments.
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

// ============================================================================
// CLIENT 1: The Art Gallery Auction
// ============================================================================
// The prestigious Istanbul Art Gallery is hosting an auction. They have a list
// of bids, where each bid contains (amount, bidder_name, timestamp).
// 
// CRITICAL REQUIREMENT: When two bids have the SAME amount, the bid that arrived
// FIRST (earlier timestamp) must appear first. This is a legal requirement for
// auction fairness.
// ============================================================================

struct Bid {
    int amount;
    string bidderName;
    int timestamp;  // Lower = arrived earlier
};


void sortAuctionBids(vector<Bid>& bids) {
    // TODO: Implement the appropriate sorting algorithm (Inserion Sort)
    int n = bids.size();
    for (int i = 0; i < n; i++) { // iterating over bids 
        Bid i_bid = bids[i];
        int j = i - 1;

        while (j >= 0 && (bids[j].amount < i_bid.amount || 
        (bids[j].amount == i_bid.amount && bids[j].timestamp > bids[i].timestamp))) 
        // ith element compared against prior i-1 elements
        {
            bids[j + 1] = bids[j];
            j--;
        }
        bids[j + 1] = i_bid;
    }
     
}

// ============================================================================
// CLIENT 2: The Spacecraft Navigation System  
// ============================================================================
// SpaceX Turkey is developing navigation software for a satellite. The system
// receives sensor readings that need to be sorted for trajectory calculations.
//
// CRITICAL CONSTRAINTS:
// - Memory is EXTREMELY limited (cannot create auxiliary arrays)
// - The readings are ALMOST SORTED (only a few elements are out of place after
//   each sensor update cycle)
// - Speed is important, but not at the cost of memory
// ============================================================================

void sortSensorReadings(vector<int>& readings) {
    // TODO: Implement the appropriate sorting algorithm
    // Insertion Sort -> Best Case O(N), worst case O(N^2), our case is nearly sorted and O(1) space
    int n = readings.size();
    for (int i = 0; i < n; i++) { // iterating over bids 
        int data = readings[i];
        int j = i - 1;

        while (j >= 0 && readings[j] > data)
        {
            readings[j + 1] = readings[j];
            j--;
        }
        readings[j + 1] = data;
    }
}

// ============================================================================
// CLIENT 3: The Student Grade System
// ============================================================================
// Yildiz Technical University needs to sort student grades (0-100) for 50,000
// students. The grades are integers only (no decimals).
//
// CRITICAL REQUIREMENT:
// - Must be faster than O(n log n) comparison-based sorts
// ============================================================================

vector<int> generate_gap_idx(int n) {
    int h;
    vector<int> gaps;
    for (int k = 0; k < n; k++) {
        if (k%2 == 0) {
            h = 9 * pow(2, k) - 9 * pow(2, k/2) + 1;
        }
        else {
            h = 9 * pow(2, k) - 9 * pow(2, k/2) + 1;
        }
        gaps.push_back(h);
    }
    return gaps; // reverse order gap numbers
}

void sortStudentGrades(vector<int>& grades) {
    // TODO: Implement the appropriate sorting algorithm (Sedgewick's Gap)
    int n = grades.size();
    vector<int> gaps = generate_gap_idx(n);
    int k = gaps.size();

    for (int j = k; j > 0; j--) { // for each gap value
        int gap = gaps[j];
        for (int i = gap; i < n; i=i+gap) { // for each group of grouped i s (indices)
            int grade = grades[i];
            int m = i - gap;

            while (m >= 0 && grades[i - gap] > grade)
            {
                grades[m + gap] = grades[m];
                m = m - gap;
            }
            grades[m + gap] = grade;
        }

    }
}

// ============================================================================
// TEST FUNCTIONS - DO NOT MODIFY
// ============================================================================

vector<Bid> generateAuctionData() {
    return {
        {1000, "Ahmet", 1},
        {1500, "Mehmet", 2},
        {1000, "Ayse", 3},      // Same amount as Ahmet, but arrived later
        {2000, "Fatma", 4},
        {1500, "Ali", 5},       // Same amount as Mehmet, but arrived later
        {1000, "Zeynep", 6}     // Same amount as Ahmet & Ayse, arrived last
    };
}

vector<int> generateNearlySortedData(int size) {
    vector<int> data(size);
    for (int i = 0; i < size; i++) {
        data[i] = i * 10;
    }
    // Displace only 5% of elements
    for (int i = 0; i < size / 20; i++) {
        int idx1 = rand() % size;
        int idx2 = rand() % size;
        swap(data[idx1], data[idx2]);
    }
    return data;
}

vector<int> generateGradeData(int numStudents) {
    vector<int> grades(numStudents);
    for (int i = 0; i < numStudents; i++) {
        grades[i] = rand() % 101;  // Grades 0-100
    }
    return grades;
}

int main() {
    srand(42);  // Fixed seed for reproducibility
    
    // ========== Test Client 1: Art Gallery ==========
    cout << "=== CLIENT 1: Art Gallery Auction ===" << endl;
    vector<Bid> bids = generateAuctionData();
    
    cout << "Before sorting:" << endl;
    for (const auto& b : bids) {
        cout << "  $" << b.amount << " by " << b.bidderName 
             << " (timestamp: " << b.timestamp << ")" << endl;
    }
    
    sortAuctionBids(bids);
    
    cout << "\nAfter sorting by amount (descending):" << endl;
    for (const auto& b : bids) {
        cout << "  $" << b.amount << " by " << b.bidderName 
             << " (timestamp: " << b.timestamp << ")" << endl;
    }
    
    // Verify stability: For same amounts, earlier timestamp should come first
    cout << "\nStability check for $1000 bids:" << endl;
    cout << "Expected order: Ahmet(1) -> Ayse(3) -> Zeynep(6)" << endl;
    cout << "If your sort is STABLE, timestamps within same amount should be ascending." << endl;
    
    // ========== Test Client 2: Spacecraft ==========
    cout << "\n=== CLIENT 2: Spacecraft Navigation ===" << endl;
    vector<int> readings = generateNearlySortedData(1000);
    
    cout << "Sorting 1000 nearly-sorted sensor readings..." << endl;
    sortSensorReadings(readings);
    
    bool sorted2 = is_sorted(readings.begin(), readings.end());
    cout << "Result: " << (sorted2 ? "SORTED CORRECTLY" : "FAILED") << endl;
    
    // ========== Test Client 3: Student Grades ==========
    cout << "\n=== CLIENT 3: Student Grade System ===" << endl;
    vector<int> grades = generateGradeData(50000);
    
    cout << "Sorting 50,000 student grades (range 0-100)..." << endl;
    sortStudentGrades(grades);
    
    bool sorted3 = is_sorted(grades.begin(), grades.end());
    cout << "Result: " << (sorted3 ? "SORTED CORRECTLY" : "FAILED") << endl;
    
    // Show grade distribution sample
    cout << "\nFirst 10 grades after sorting: ";
    for (int i = 0; i < 10 && i < (int)grades.size(); i++) {
        cout << grades[i] << " ";
    }
    cout << "..." << endl;
    
    cout << "\n=== SUMMARY ===" << endl;
    cout << "Did you choose the right algorithm for each client?" << endl;
    cout << "Client 1 needs: A STABLE sort (preserves order of equal elements)" << endl;
    cout << "Client 2 needs: Efficient on nearly-sorted data with O(1) space" << endl;
    cout << "Client 3 needs: Non-comparison sort for limited integer range" << endl;
    
    return 0;
}
