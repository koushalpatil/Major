//dfs

#include <bits/stdc++.h>
using namespace std;


void dfsUtil(int current, unordered_map<int, vector<int>>& adjList, vector<bool>& visited) {
    visited[current] = true;
    cout << current << " ";

    for (int neighbor : adjList[current]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, adjList, visited);
        }
    }
}


void dfs(int startNode, unordered_map<int, vector<int>>& adjList, int n) {
    vector<bool> visited(n + 1, false);
    cout << "DFS Traversal: ";
    dfsUtil(startNode, adjList, visited);
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
        adjList[v].push_back(u); 
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    dfs(startNode, adjList, n);

    return 0;
}
