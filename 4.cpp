#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef pair<int, int> Edge; // {weight, node}
typedef tuple<int, int, int> MSTEdge; // {weight, node1, node2}

void primMST(int n, vector<vector<Edge>> &adjList) {
    vector<bool> visited(n, false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq; // Min-heap for edges
    vector<MSTEdge> mstEdges; // To store edges of the MST
    int totalWeight = 0;

    // Start from node 0 (arbitrarily chosen)
    pq.push({0, 0}); // {weight, node}

    while (!pq.empty()) {
        int weight, node;
        tie(weight, node) = pq.top();
        pq.pop();

        if (visited[node]) continue;
        visited[node] = true;

        totalWeight += weight;
        
        // Add edges from this node to MST
        for (const auto &edge : adjList[node]) {
            int nextWeight = edge.first;
            int nextNode = edge.second;
            if (!visited[nextNode]) {
                pq.push({nextWeight, nextNode});
                mstEdges.push_back({nextWeight, node, nextNode});
            }
        }
    }

    cout << "Total Weight of Minimum Spanning Tree: " << totalWeight << endl;

    cout << "Edges in the MST:" << endl;
    for (const auto &edge : mstEdges) {
        int w = get<0>(edge);
        int u = get<1>(edge);
        int v = get<2>(edge);
        if (u != v) { // Avoid self-loops
            cout << u << " - " << v << " (Weight: " << w << ")" << endl;
        }
    }
}

int main() {
    int n, m; // Number of nodes and edges
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> adjList(n);

    cout << "Enter edges (node1, node2, weight):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({w, v});
        adjList[v].push_back({w, u});
    }

    primMST(n, adjList);

    return 0;
}
