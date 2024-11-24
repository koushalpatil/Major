#include <bits/stdc++.h>

using namespace std;

class Graph{

    public :
    int V;
    vector<vector<pair<int,int>>> adj;

    Graph(int V){
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u,int v,int weight){
        adj[u].push_back({v,weight});
        adj[v].push_back({u  ,weight});
    }

    void bestFirstSearch(int start,int goal){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<bool> visited(V,false);

        vector<int> parent(V,-1);

        pq.push({0,start});

        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();

            if(u==goal){
                vector<int> path;

                for(int i=u;i!=-1;i=parent[i]){
                    path.push_back(i);
                }

                cout<<"Goal Found : ";

                reverse(path.begin(),path.end());

                for(auto it : path){
                    cout << it << "->";
                }



                return;
            }
            else{
                visited[u]=true;

                for(auto it : adj[u]){
                    if(!visited[it.first]){
                        parent[it.first] = u;
                        pq.push({it.second,it.first});
                    }
                }
            }
        }

        cout<<"goal not found";
    }
};

int main(){
    int V = 8;
    Graph g(V);

    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 6);
    g.addEdge(1, 3, 9);
    g.addEdge(1, 4, 8);
    g.addEdge(2, 5, 12);
    g.addEdge(2, 6, 14);
    g.addEdge(3, 7, 10);
    g.addEdge(4, 7, 15);
    g.addEdge(5, 6, 7);
    g.addEdge(6, 7, 2);

    int start = 0, goal = 6;
    cout << "Best First Search starting from node " << start << " and aiming for node " << goal << ":\n";
    g.bestFirstSearch(start, goal);

    return 0;
}