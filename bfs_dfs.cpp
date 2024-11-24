//bfs and dfs

#include <bits/stdc++.h>

using namespace std ;


void bfs(vector<int>& ans,vector<vector<int>>& adj){
    queue<int> q;
    vector<int> v(10,0);
    q.push(0);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        v[node]=1;
        for(auto it : adj[node]){
            if(!v[it]){
                q.push(it);
            }
        }
    }

    for(auto it : ans){
        cout<< it <<" ";
    }
}

void dfs( vector<vector<int>>& adj,vector<int>& ans1,vector<int>& v,int node){
    v[node]=1;
    ans1.push_back(node);

    for(auto it : adj[node]){
        if(v[it]!=1){
          dfs(adj,ans1,v,it);  
        }
    }
}

int main(){
    

     
    vector<vector<int>> adj(8);

    
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 6, 5};
    adj[3] = {1, 7};
    adj[4] = {1, 7};
    adj[5] = {2, 6};
    adj[6] = {5,2,7};
    adj[7] = {3,4,6};
    

    vector<int> ans;
    vector<int> ans1;
    cout<<"BFS : ";
    bfs(ans,adj);
    vector<int> v(10,0);
    int node = 0;
    dfs(adj,ans1,v,node);
    cout<<endl;
    cout<<"DFS : ";
    for(auto it : ans1){
        cout<< it <<" ";
    }
    return 0;
}