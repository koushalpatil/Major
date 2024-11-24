#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    map<string, vector<pair<string, int>>> adj;
    map<string, int> heuristic;

    void addEdge(string u, string v, int cost) {
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }

    void setHeuristic(string node, int h) {
        heuristic[node] = h;
    }

    vector<string> aStar(string start, string goal) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> openSet;
        map<string, int> gCost;
        map<string, string> cameFrom;

        for (auto &node : adj) {
            gCost[node.first] = INT_MAX;
        }

        gCost[start] = 0;
        openSet.push({heuristic[start], start});

        while (!openSet.empty()) {
            string current = openSet.top().second;
            openSet.pop();

            if (current == goal) {
                vector<string> path;
                while (current != "") {
                    path.push_back(current);
                    current = cameFrom[current];
                }
                reverse(path.begin(), path.end());
                return path;
            }

            for (auto &neighbor : adj[current]) {
                string nextNode = neighbor.first;
                int edgeCost = neighbor.second;

                int tentativeGCost = gCost[current] + edgeCost;

                if (tentativeGCost < gCost[nextNode]) {
                    cameFrom[nextNode] = current;
                    gCost[nextNode] = tentativeGCost;

                    int fCost = gCost[nextNode] + heuristic[nextNode];
                    openSet.push({fCost, nextNode});
                }
            }
        }

        return {};
    }
};

int main() {
    Graph graph;

    graph.addEdge("S", "A", 1);
    graph.addEdge("S", "G", 10);
    graph.addEdge("A", "B", 2);
    graph.addEdge("A", "C", 1);
    graph.addEdge("B", "D", 5);
    graph.addEdge("C", "D", 3);
    graph.addEdge("C", "G", 4);
    graph.addEdge("D", "G", 2);

    graph.setHeuristic("S", 5);
    graph.setHeuristic("A", 3);
    graph.setHeuristic("B", 4);
    graph.setHeuristic("C", 2);
    graph.setHeuristic("D", 6);
    graph.setHeuristic("G", 0);

    string start = "S";
    string goal = "G";

    vector<string> path = graph.aStar(start, goal);

    if (!path.empty()) {
        cout << "Path: ";
        for (const auto &node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path found!" << endl;
    }

    return 0;
}