/**
 * Problem 1: The Social Network
 * 
 * Implement a Graph class using Adjacency List to model a social network.
 * - addUser(userId): Add a new user
 * - follow(userId1, userId2): User1 follows User2 (directed edge)
 * - unfollow(userId1, userId2): User1 unfollows User2
 * - getFollowers(userId): Get all users who follow this user
 * - getFollowing(userId): Get all users this user follows
 * - isFollowing(userId1, userId2): Check if User1 follows User2
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class SocialNetwork {
private:
    // Adjacency list: userId -> set of users they follow
    unordered_map<int, unordered_set<int>> following;
    
    // Reverse adjacency list: userId -> set of users who follow them
    unordered_map<int, unordered_set<int>> followers;
    
    // Set of all users in the network
    unordered_set<int> users;

public:
    // Add a new user to the network
    // If user already exists, do nothing
    void addUser(int userId) {
        // Implement this
    }
    
    // User1 follows User2 (creates directed edge from user1 to user2)
    // If either user doesn't exist, add them first
    // If already following, do nothing
    void follow(int userId1, int userId2) {
        // Implement this
    }
    
    // User1 unfollows User2
    // If not following, do nothing
    void unfollow(int userId1, int userId2) {
        // Implement this
    }
    
    // Get all users who follow the given user
    vector<int> getFollowers(int userId) {
        // Implement this
        return {};  // placeholder
    }
    
    // Get all users the given user follows
    vector<int> getFollowing(int userId) {
        // Implement this
        return {};  // placeholder
    }
    
    // Check if userId1 follows userId2
    bool isFollowing(int userId1, int userId2) {
        // Implement this
        return false;  // placeholder
    }
    
    // Get the number of users in the network
    int getUserCount() {
        return users.size();
    }
    
    // Get total number of follow relationships
    int getEdgeCount() {
        int count = 0;
        for (const auto& pair : following) {
            count += pair.second.size();
        }
        return count;
    }
    
    // Print the network structure
    void printNetwork() {
        cout << "Social Network Structure:" << endl;
        cout << "Users: " << getUserCount() << ", Connections: " << getEdgeCount() << endl;
        
        for (int user : users) {
            cout << "  User " << user << ":" << endl;
            
            vector<int> followingList = getFollowing(user);
            cout << "    Following: [";
            for (int i = 0; i < followingList.size(); i++) {
                if (i > 0) cout << ", ";
                cout << followingList[i];
            }
            cout << "]" << endl;
            
            vector<int> followerList = getFollowers(user);
            cout << "    Followers: [";
            for (int i = 0; i < followerList.size(); i++) {
                if (i > 0) cout << ", ";
                cout << followerList[i];
            }
            cout << "]" << endl;
        }
    }
};

int main() {
    cout << "=== Social Network ===" << endl;
    
    SocialNetwork network;
    
    // Test 1: Add users and follow relationships
    cout << "\n--- Test 1: Building the Network ---" << endl;
    
    network.addUser(1);
    network.addUser(2);
    network.addUser(3);
    network.addUser(4);
    network.addUser(5);
    
    network.follow(1, 2);  // User 1 follows User 2
    network.follow(1, 3);  // User 1 follows User 3
    network.follow(2, 3);  // User 2 follows User 3
    network.follow(3, 4);  // User 3 follows User 4
    network.follow(4, 5);  // User 4 follows User 5
    network.follow(5, 1);  // User 5 follows User 1 (creates a cycle)
    
    network.printNetwork();
    
    // Test 2: Query relationships
    cout << "\n--- Test 2: Query Relationships ---" << endl;
    
    cout << "User 1 follows User 2? " << (network.isFollowing(1, 2) ? "Yes" : "No") << " (expected: Yes)" << endl;
    cout << "User 2 follows User 1? " << (network.isFollowing(2, 1) ? "Yes" : "No") << " (expected: No)" << endl;
    cout << "User 5 follows User 1? " << (network.isFollowing(5, 1) ? "Yes" : "No") << " (expected: Yes)" << endl;
    
    // Test 3: Get followers and following
    cout << "\n--- Test 3: Followers and Following ---" << endl;
    
    vector<int> user3Followers = network.getFollowers(3);
    cout << "Followers of User 3: [";
    for (int i = 0; i < user3Followers.size(); i++) {
        if (i > 0) cout << ", ";
        cout << user3Followers[i];
    }
    cout << "] (expected: [1, 2])" << endl;
    
    vector<int> user1Following = network.getFollowing(1);
    cout << "User 1 is following: [";
    for (int i = 0; i < user1Following.size(); i++) {
        if (i > 0) cout << ", ";
        cout << user1Following[i];
    }
    cout << "] (expected: [2, 3])" << endl;
    
    // Test 4: Unfollow
    cout << "\n--- Test 4: Unfollow ---" << endl;
    
    cout << "Before unfollow - User 1 follows User 2? " << (network.isFollowing(1, 2) ? "Yes" : "No") << endl;
    network.unfollow(1, 2);
    cout << "After unfollow - User 1 follows User 2? " << (network.isFollowing(1, 2) ? "Yes" : "No") << " (expected: No)" << endl;
    
    // Test 5: Edge cases
    cout << "\n--- Test 5: Edge Cases ---" << endl;
    
    // Follow non-existent user (should add them)
    network.follow(6, 7);
    cout << "After follow(6, 7) - User count: " << network.getUserCount() << " (expected: 7)" << endl;
    
    // Self-follow (edge case - typically not allowed in social networks)
    network.follow(1, 1);
    cout << "User 1 follows User 1? " << (network.isFollowing(1, 1) ? "Yes" : "No") << endl;
    
    // Unfollow someone you don't follow (should do nothing)
    network.unfollow(1, 5);
    cout << "Unfollow someone not followed - no crash ✓" << endl;
    
    cout << "\n--- Final Network State ---" << endl;
    network.printNetwork();
    
    return 0;
}

