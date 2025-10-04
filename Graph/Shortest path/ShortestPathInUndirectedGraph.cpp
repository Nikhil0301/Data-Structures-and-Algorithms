#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size(); // no. of nodes in the graph
        vector<int> path(n, -1);
        queue<pair<int, int> > q;
        q.push({src, 0});
        path[src] = 0;
        while(!q.empty()){
            auto nodePair = q.front();
            q.pop();
            int node = nodePair.first;
            int dist = nodePair.second;
            //go through the neighbors of the node array
            for(auto neigh : adj[node]){
                if(path[neigh] == -1){
                    path[neigh] = dist + 1;
                    q.push({neigh, dist + 1});
                }
            }
        }
        return path;
    }
};
int main(){
    //int adj[][] = [[1, 3], [0, 2], [1, 6], [0, 4], [3, 5], [4, 6], [2, 5, 7, 8], [6, 8], [7, 6]];
    vector<vector<int> > adj = {
        {1, 3},
        {0, 2},
        {1, 6},
        {0, 4},
        {3, 5},
        {4, 6},
        {2, 5, 7, 8},
        {6, 8},
        {7, 6}
    };

    Solution sol;
    int src = 0;
    vector<int> shortestPaths = sol.shortestPath(adj, src);
    for(int i = 0; i < shortestPaths.size(); i++) {
        cout << "Node " << i << ": " << shortestPaths[i] << endl;
    }
    return 0;
}