# Lab 7: Graph Data Structures

## Objectives

- Understand and implement graph representations (Adjacency List).
- Master graph traversal algorithms (BFS and DFS).
- Apply topological sorting to dependency problems.
- Implement Dijkstra's algorithm for shortest paths in weighted graphs.
- Solve real-world problems modeled as graphs.

---

## Problem 1: The Social Network

**File:** `problem1.cpp`

**Scenario:**
You are building a social network platform. Users can follow each other, and you need to support various queries about the network structure.

**Task:**
Implement a **Graph** class using an **Adjacency List** representation that supports:

1. `addUser(userId)`: Add a new user to the network.
2. `follow(userId1, userId2)`: User1 follows User2 (directed edge).
3. `unfollow(userId1, userId2)`: User1 unfollows User2.
4. `getFollowers(userId)`: Get all users who follow this user.
5. `getFollowing(userId)`: Get all users this user follows.
6. `isFollowing(userId1, userId2)`: Check if User1 follows User2.

**Example:**

```
addUser(1), addUser(2), addUser(3)
follow(1, 2)  // User 1 follows User 2
follow(1, 3)  // User 1 follows User 3
follow(2, 3)  // User 2 follows User 3

getFollowing(1) -> [2, 3]
getFollowers(3) -> [1, 2]
isFollowing(1, 2) -> true
isFollowing(2, 1) -> false
```

---

## Problem 2: Six Degrees of Separation

**File:** `problem2.cpp`

**Scenario:**
In social network theory, the "six degrees of separation" concept suggests that any two people are connected through at most six intermediate connections.

Given a social network graph, find the **shortest path** (minimum number of hops) between two users.

**Task:**
Implement **BFS (Breadth-First Search)** to:

1. Find the shortest path between two users.
2. Return the path as a sequence of user IDs.
3. Return -1 if no path exists.

**Example:**

```
Network:
  Alice -- Bob -- Charlie -- Diana
    |              |
  Eve ----------- Frank

shortestPath("Alice", "Diana") -> ["Alice", "Bob", "Charlie", "Diana"] (distance: 3)
shortestPath("Alice", "Frank") -> ["Alice", "Eve", "Frank"] (distance: 2)
shortestPath("Alice", "Zoe") -> [] (no path, Zoe not in network)
```

---

## Problem 3: The Island Counter

**File:** `problem3.cpp`

**Scenario:**
You are given a 2D grid map where:

- `1` represents land
- `0` represents water

An **island** is a group of connected land cells (horizontally or vertically adjacent). Count the number of distinct islands in the grid.

**Task:**
Implement **DFS (Depth-First Search)** to:

1. Traverse the grid and identify all islands.
2. Count the total number of islands.
3. Optionally, label each island with a unique ID.

**Example:**

```
Grid:
  1 1 0 0 0
  1 1 0 0 0
  0 0 1 0 0
  0 0 0 1 1

Output: 3 islands
  - Island 1: top-left 2x2 block
  - Island 2: center cell
  - Island 3: bottom-right 1x2 block
```

---

## Problem 4: The Course Scheduler

**File:** `problem4.cpp`

**Scenario:**
A university has courses with prerequisites. Before taking a course, you must complete all its prerequisites. Given a list of courses and their prerequisites, determine:

1. Is it possible to complete all courses? (No circular dependencies)
2. If yes, provide a valid order to take the courses.

**Task:**
Implement **Topological Sort** using Kahn's Algorithm (BFS-based) to:

1. Detect if the course graph has a cycle (impossible to complete).
2. Return a valid ordering of courses if possible.

**Example:**

```
Courses: [0, 1, 2, 3]
Prerequisites:
  - Course 1 requires Course 0
  - Course 2 requires Course 0
  - Course 3 requires Course 1
  - Course 3 requires Course 2

Graph:
  0 -> 1 -> 3
  |         ^
  +-> 2 ----+

Valid orderings: [0, 1, 2, 3] or [0, 2, 1, 3]

---

Courses: [0, 1, 2]
Prerequisites:
  - Course 1 requires Course 0
  - Course 0 requires Course 2
  - Course 2 requires Course 1

This has a cycle: 0 -> 1 -> 2 -> 0
Output: IMPOSSIBLE
```

---

## Problem 5: The Navigation System

**File:** `problem5.cpp`

**Scenario:**
You are building a GPS navigation system. Given a map of cities and roads with distances, find the shortest path from a starting city to all other cities.

**Task:**
Implement **Dijkstra's Algorithm** to:

1. Find the shortest distance from a source city to all other cities.
2. Reconstruct the actual shortest path to any destination.
3. Handle disconnected cities (unreachable destinations).

**Example:**

```
Cities: A, B, C, D, E
Roads:
  A --5-- B
  A --2-- C
  B --1-- D
  C --3-- D
  C --7-- E
  D --2-- E

From A:
  A -> A: 0
  A -> B: 5 (direct)
  A -> C: 2 (direct)
  A -> D: 5 (A -> C -> D, cost 2+3)
  A -> E: 7 (A -> C -> D -> E, cost 2+3+2)

Shortest path A to E: A -> C -> D -> E (distance: 7)
```

---

## Compilation

Use the provided `Makefile` to compile the solutions.

```bash
make
./problem1
./problem2
./problem3
./problem4
./problem5
```
