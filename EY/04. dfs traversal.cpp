Given a connected undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Traversal (DFS) starting from vertex 0, visiting vertices from left to right as per the adjacency list, and return a list containing the DFS traversal of the graph.

Note: Do traverse in the same order as they are in the adjacency list.

Examples:

Input: adj = [[2,3,1], [0], [0,4], [0], [2]]

Output: [0, 2, 4, 3, 1]
Explanation: Starting from 0, the DFS traversal proceeds as follows: 
Visit 0 → Output: 0 
Visit 2 (the first neighbor of 0) → Output: 0, 2 
Visit 4 (the first neighbor of 2) → Output: 0, 2, 4 
Backtrack to 2, then backtrack to 0, and visit 3 → Output: 0, 2, 4, 3 
Finally, backtrack to 0 and visit 1 → Final Output: 0, 2, 4, 3, 1
Input: adj = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]

Output: [0, 1, 2, 3, 4]
Explanation: Starting from 0, the DFS traversal proceeds as follows: 
Visit 0 → Output: 0 
Visit 1 (the first neighbor of 0) → Output: 0, 1 
Visit 2 (the first neighbor of 1) → Output: 0, 1, 2 
Visit 3 (the first neighbor of 2) → Output: 0, 1, 2, 3 
Backtrack to 2 and visit 4 → Final Output: 0, 1, 2, 3, 4
Constraints:
1 ≤ adj.size() ≤ 104
1 ≤ adj[i][j] ≤ 104

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& isVisited, vector<int>& result){
        isVisited[node]=true;
        result.push_back(node);
        for(int adjacents : adj[node]){
            if(!isVisited[adjacents]){
                dfs(adjacents,adj,isVisited,result);
            }
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<bool>isVisited(v,false);
        vector<int>res;
        
        dfs(0,adj,isVisited,res);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
