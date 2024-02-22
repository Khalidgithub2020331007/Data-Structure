#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform Depth First Search
void dfs(vector<vector<int>>& adjList, int startNode) {
    vector<bool> visited(adjList.size(), false); // To keep track of visited nodes
    stack<int> s; // Stack for DFS

    // Push the start node onto the stack
    s.push(startNode);

    while (!s.empty()) {
        int current = s.top(); // Get the top of the stack
        s.pop(); // Remove the top node from the stack

        if (!visited[current]) {
            cout << current << " "; // Process current node
            visited[current] = true; // Mark current node as visited

            // Traverse adjacent nodes of current node
            for (int adjNode : adjList[current]) {
                if (!visited[adjNode]) {
                    s.push(adjNode); // Push adjacent node onto the stack
                }
            }
        }
    }
}

int main() {
    // Example graph represented using adjacency lists
    int numNodes = 6;
    vector<vector<int>> adjList(numNodes);

    // Add edges
    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 4};
    adjList[2] = {0, 4};
    adjList[3] = {1, 5};
    adjList[4] = {1, 2, 5};
    adjList[5] = {3, 4};

    // Start DFS from node 0
    cout << "DFS Traversal: ";
    dfs(adjList, 0);

    return 0;
}
