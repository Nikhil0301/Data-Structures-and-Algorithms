#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //use bfs toposort
        //wil build adj list
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        vector<int> indeg(numCourses, 0);
        for(auto edge:prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        for(int i = 0; i < numCourses; i++){
            for(auto neigh : adj[i]){
                indeg[neigh]++;
            }
        }
        //push all the 0 indegrees to the queue
        for(int i = 0; i < indeg.size(); i++){
            if(indeg[i] == 0)
                q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto neigh:adj[node]){
                indeg[neigh]--;
                if(!indeg[neigh])
                 q.push(neigh);
            }
        }
        return topo.size() == numCourses ? true : false;
    }
};