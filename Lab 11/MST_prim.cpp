#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to implement Prim's algorithm and obtain the MST
void MST_prime(vector<vector<int>>& graph, int startNode) {
    int vertices_count = graph.size();

    vector<int> key(vertices_count, INT_MAX);
    vector<int> parent(vertices_count, -1);
    vector<bool> visited(vertices_count, false);

    key[startNode] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mst_queue;
    mst_queue.push({0, startNode});

    while (!mst_queue.empty()) {
        // Extract the vertex with the minimum key value
        int u = mst_queue.top().second;
        mst_queue.pop();
        visited[u] = true;

        // Traverse all adjacent vertices of u
        for (int v = 0; v < vertices_count; ++v) {
            // Check if v is adjacent to u, not visited, and has a lower weight
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
                mst_queue.push({key[v], v});
            }
        }
    }

    cout << "Minimum Spanning Tree (MST):\n";
    for (int i = 1; i < vertices_count; ++i) {
        cout << parent[i] << " - " << i << "\n";
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    int startNode = 0;

    MST_prime(graph, startNode);

    return 0;
}

