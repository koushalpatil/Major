#include <bits/stdc++.h>
using namespace std;

// BFS function
void bfs(int startNode, unordered_map<int, vector<int>>& adjList, int n) {
    vector<bool> visited(n + 1, false);
    queue<int> q;

    q.push(startNode);
    visited[startNode] = true;

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    unordered_map<int, vector<int>> adjList;

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Comment this line for directed graphs
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    bfs(startNode, adjList, n);

    return 0;
}
