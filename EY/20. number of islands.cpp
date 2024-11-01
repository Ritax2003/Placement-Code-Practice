/*
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Examples:

Input: grid = [[0,1],[1,0],[1,1],[1,0]]

[0,1]
[1,0]
[1,1]
[1,0]

Output: 1
Explanation:

The grid is-
[0,1]
[1,0]
[1,1]
[1,0]

All lands are connected.
Input: grid = [[0,1,1,1,0,0,0],[0,0,1,1,0,1,0]]


Output: 2
Expanation:
The grid is-

[0,1,1,1,0,0,0]
[0,0,1,1,0,1,0]

There are two islands :- one is colored in "blue" and other in "red".
Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
grid[i][j] = {'0', '1'}


*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int r,int c,vector<vector<char>>& grid, vector<pair<int,int>>& dir){
       int rows = grid.size();
       int cols = grid[0].size();
        grid[r][c]='0';
        for(pair<int,int>p :dir){
            int nr = r+p.first,nc = c+p.second;
            if(nr>=0 && nr< rows && nc>=0 && nc<cols && grid[nr][nc]=='1'){
                dfs(nr,nc,grid,dir);
            }
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
       if(grid.empty()) return 0;
       int rows = grid.size();
       int cols = grid[0].size();
       int islandcount = 0;
       
       vector<pair<int,int>>direction={
           {-1,0},//left
           {1,0},//right
           {0,-1},//down
           {0,1},//up
           {-1,-1},//down left diagonal
           {-1,1},//up left diagonal
           {1,-1},//down right diagonal
           {1,1}//up right diagonal
           };
           
           for(int r=0;r<rows;r++){
               for(int c=0;c<cols;c++){
                   if(grid[r][c]=='1') {
                       islandcount++;
                       dfs(r,c,grid,direction);
                   }
                   
               }
           }
           
       return islandcount;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends
