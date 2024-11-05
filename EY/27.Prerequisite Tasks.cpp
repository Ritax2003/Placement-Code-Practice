/*
There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.


Example 1:

Input: 
N = 4, P = 3
prerequisites = {{1,0},{2,1},{3,2}}
Output:
Yes
Explanation:
To do task 1 you should have completed
task 0, and to do task 2 you should 
have finished task 1, and to do task 3 you 
should have finished task 2. So it is possible.
Example 2:

Input:
N = 2, P = 2
prerequisites = {{1,0},{0,1}}
Output:
No
Explanation:
To do task 1 you should have completed
task 0, and to do task 0 you should
have finished task 1. So it is impossible.

Your task:
You don’t need to read input or print anything. 
Your task is to complete the function isPossible() which takes the integer N denoting the number of tasks, P denoting the number of prerequisite pairs and prerequisite as input parameters and returns true if it is possible to finish all tasks otherwise returns false. 


Expected Time Complexity: O(N + P)
Expected Auxiliary Space: O(N + P)


Constraints:
1 ≤ N ≤ 104
1 ≤ P ≤ 105
*/

class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	  // Step 1: Create an adjacency list and in-degree array
	  vector<int>adj[N];
	  vector<int> inDegree(N,0);
	  
	  for(auto& pre : prerequisites){
	      int u = pre.second;
	      int v = pre.first;
	      adj[u].push_back(v);
	      inDegree[v]++;
	  }
	  // Step 2: Initialize the queue with tasks having in-degree 0
	  queue<int>q;
	  for(int i=0;i<N;i++){
	      if(inDegree[i]==0) q.push(i);
	  }
	  // Step 3: Perform topological sort
	  int count = 0;
	  while(!q.empty()){
	      int node = q.front();
	      q.pop();
	      count++;
	       // Decrease the in-degree of neighboring nodes
	      for(int neighbor:adj[node]){
	          inDegree[neighbor]--;
	          if(inDegree[neighbor]==0) q.push(neighbor);
	      }
	  }
	  
	  return count==N;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends
