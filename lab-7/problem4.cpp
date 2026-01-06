/**
 * Problem 4: The Course Scheduler
 * 
 * Implement Topological Sort using Kahn's Algorithm (BFS-based) to:
 * - Detect if course prerequisites form a cycle (impossible to complete)
 * - Find a valid order to complete all courses
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

class CourseScheduler {
private:
    int numCourses;
    vector<vector<int>> adjList;    // adjList[i] = courses that depend on course i
    vector<int> inDegree;           // inDegree[i] = number of prerequisites for course i

public:
    CourseScheduler(int n) : numCourses(n), adjList(n), inDegree(n, 0) {}
    
    // Add a prerequisite: must complete 'prereq' before 'course'
    // This creates a directed edge from prereq -> course
    void addPrerequisite(int course, int prereq) {
        adjList[prereq].push_back(course);
        inDegree[course]++;
    }
    
    // Topological Sort using Kahn's Algorithm
    // Returns true if all courses can be completed (no cycle)
    // Returns false if there's a cycle
    // Fills 'order' with a valid course ordering
    bool canFinish(vector<int>& order) {
        order.clear();
        
        // TODO: Implement Kahn's Algorithm
        
        return false;  // placeholder
    }
    
    // Get the minimum number of semesters to complete all courses
    // Assumes you can take multiple courses per semester if no dependencies
    // Uses level-by-level BFS
    int minSemesters() {
        if (numCourses == 0) return 0;
        
        // TODO: Implement semester calculation
        
        return -1;  // placeholder (-1 indicates cycle or not implemented)
    }
    
    // Print course dependencies
    void printDependencies() {
        cout << "Course Dependencies:" << endl;
        for (int i = 0; i < numCourses; i++) {
            cout << "  Course " << i << " (in-degree " << inDegree[i] << "):";
            if (adjList[i].empty()) {
                cout << " no dependents";
            } else {
                cout << " enables -> [";
                for (int j = 0; j < adjList[i].size(); j++) {
                    if (j > 0) cout << ", ";
                    cout << adjList[i][j];
                }
                cout << "]";
            }
            cout << endl;
        }
    }
};

// Helper class for courses with names
class NamedCourseScheduler {
private:
    unordered_map<string, int> courseToId;
    vector<string> idToCourse;
    CourseScheduler* scheduler;

public:
    NamedCourseScheduler() : scheduler(nullptr) {}
    
    ~NamedCourseScheduler() {
        delete scheduler;
    }
    
    void addCourse(const string& name) {
        if (courseToId.find(name) == courseToId.end()) {
            courseToId[name] = idToCourse.size();
            idToCourse.push_back(name);
        }
    }
    
    void build() {
        scheduler = new CourseScheduler(idToCourse.size());
    }
    
    void addPrerequisite(const string& course, const string& prereq) {
        if (scheduler) {
            scheduler->addPrerequisite(courseToId[course], courseToId[prereq]);
        }
    }
    
    bool getSchedule(vector<string>& schedule) {
        if (!scheduler) return false;
        
        vector<int> order;
        bool possible = scheduler->canFinish(order);
        
        schedule.clear();
        for (int id : order) {
            schedule.push_back(idToCourse[id]);
        }
        
        return possible;
    }
};

int main() {
    cout << "=== Course Scheduler ===" << endl;
    
    // Test 1: Simple linear dependencies
    cout << "\n--- Test 1: Linear Dependencies ---" << endl;
    {
        // Courses: 0 -> 1 -> 2 -> 3
        CourseScheduler scheduler(4);
        scheduler.addPrerequisite(1, 0);  // 1 requires 0
        scheduler.addPrerequisite(2, 1);  // 2 requires 1
        scheduler.addPrerequisite(3, 2);  // 3 requires 2
        
        scheduler.printDependencies();
        
        vector<int> order;
        bool possible = scheduler.canFinish(order);
        
        cout << "Can finish all courses? " << (possible ? "Yes" : "No") << endl;
        cout << "Expected: Yes" << endl;
        
        if (possible) {
            cout << "Course order: [";
            for (int i = 0; i < order.size(); i++) {
                if (i > 0) cout << ", ";
                cout << order[i];
            }
            cout << "]" << endl;
            cout << "Expected: [0, 1, 2, 3]" << endl;
        }
    }
    
    // Test 2: Diamond dependency
    cout << "\n--- Test 2: Diamond Dependency ---" << endl;
    {
        //     0
        //    / \
        //   1   2
        //    \ /
        //     3
        CourseScheduler scheduler(4);
        scheduler.addPrerequisite(1, 0);  // 1 requires 0
        scheduler.addPrerequisite(2, 0);  // 2 requires 0
        scheduler.addPrerequisite(3, 1);  // 3 requires 1
        scheduler.addPrerequisite(3, 2);  // 3 requires 2
        
        scheduler.printDependencies();
        
        vector<int> order;
        bool possible = scheduler.canFinish(order);
        
        cout << "Can finish all courses? " << (possible ? "Yes" : "No") << endl;
        cout << "Expected: Yes" << endl;
        
        if (possible) {
            cout << "Course order: [";
            for (int i = 0; i < order.size(); i++) {
                if (i > 0) cout << ", ";
                cout << order[i];
            }
            cout << "]" << endl;
            cout << "Expected: [0, 1, 2, 3] or [0, 2, 1, 3]" << endl;
        }
    }
    
    // Test 3: Cycle detection
    cout << "\n--- Test 3: Cycle (Impossible) ---" << endl;
    {
        // 0 -> 1 -> 2 -> 0 (cycle!)
        CourseScheduler scheduler(3);
        scheduler.addPrerequisite(1, 0);  // 1 requires 0
        scheduler.addPrerequisite(2, 1);  // 2 requires 1
        scheduler.addPrerequisite(0, 2);  // 0 requires 2 (creates cycle!)
        
        scheduler.printDependencies();
        
        vector<int> order;
        bool possible = scheduler.canFinish(order);
        
        cout << "Can finish all courses? " << (possible ? "Yes" : "No") << endl;
        cout << "Expected: No (cycle exists)" << endl;
    }
    
    // Test 4: Independent courses
    cout << "\n--- Test 4: Independent Courses ---" << endl;
    {
        CourseScheduler scheduler(5);
        // No dependencies - all courses are independent
        
        scheduler.printDependencies();
        
        vector<int> order;
        bool possible = scheduler.canFinish(order);
        
        cout << "Can finish all courses? " << (possible ? "Yes" : "No") << endl;
        cout << "Expected: Yes" << endl;
        
        if (possible) {
            cout << "Course order: [";
            for (int i = 0; i < order.size(); i++) {
                if (i > 0) cout << ", ";
                cout << order[i];
            }
            cout << "]" << endl;
            cout << "Expected: Any permutation of [0, 1, 2, 3, 4]" << endl;
        }
    }
    
    // Test 5: Multiple starting points
    cout << "\n--- Test 5: Multiple Starting Points ---" << endl;
    {
        //  0     1
        //  |     |
        //  v     v
        //  2 --> 3
        //        |
        //        v
        //        4
        CourseScheduler scheduler(5);
        scheduler.addPrerequisite(2, 0);
        scheduler.addPrerequisite(3, 1);
        scheduler.addPrerequisite(3, 2);
        scheduler.addPrerequisite(4, 3);
        
        scheduler.printDependencies();
        
        vector<int> order;
        bool possible = scheduler.canFinish(order);
        
        cout << "Can finish all courses? " << (possible ? "Yes" : "No") << endl;
        
        if (possible) {
            cout << "Course order: [";
            for (int i = 0; i < order.size(); i++) {
                if (i > 0) cout << ", ";
                cout << order[i];
            }
            cout << "]" << endl;
        }
    }
    
    // Test 6: Real course names
    cout << "\n--- Test 6: Named Courses ---" << endl;
    {
        NamedCourseScheduler scheduler;
        
        // Add courses
        scheduler.addCourse("Calculus I");
        scheduler.addCourse("Calculus II");
        scheduler.addCourse("Linear Algebra");
        scheduler.addCourse("Physics I");
        scheduler.addCourse("Physics II");
        scheduler.addCourse("Data Structures");
        scheduler.addCourse("Algorithms");
        
        scheduler.build();
        
        // Add prerequisites
        scheduler.addPrerequisite("Calculus II", "Calculus I");
        scheduler.addPrerequisite("Physics I", "Calculus I");
        scheduler.addPrerequisite("Physics II", "Physics I");
        scheduler.addPrerequisite("Physics II", "Calculus II");
        scheduler.addPrerequisite("Algorithms", "Data Structures");
        scheduler.addPrerequisite("Algorithms", "Linear Algebra");
        
        vector<string> schedule;
        bool possible = scheduler.getSchedule(schedule);
        
        cout << "Can complete all courses? " << (possible ? "Yes" : "No") << endl;
        
        if (possible) {
            cout << "Course order:" << endl;
            for (int i = 0; i < schedule.size(); i++) {
                cout << "  " << (i + 1) << ". " << schedule[i] << endl;
            }
        }
    }
    
    // Test 7: Minimum semesters
    cout << "\n--- Test 7: Minimum Semesters ---" << endl;
    {
        //     0
        //    / \
        //   1   2
        //    \ /
        //     3
        CourseScheduler scheduler(4);
        scheduler.addPrerequisite(1, 0);
        scheduler.addPrerequisite(2, 0);
        scheduler.addPrerequisite(3, 1);
        scheduler.addPrerequisite(3, 2);
        
        int semesters = scheduler.minSemesters();
        cout << "Minimum semesters needed: " << semesters << endl;
        cout << "Expected: 3 (Semester 1: [0], Semester 2: [1,2], Semester 3: [3])" << endl;
    }
    
    return 0;
}

