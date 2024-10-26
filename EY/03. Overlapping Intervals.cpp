/*
Input: arr[] = [[1,3],[2,4],[6,8],[9,10]]
Output: [[1,4], [6,8], [9,10]]

Explanation: Given intervals: [1,3], [2,4], [6,8], [9,10], we have only two overlapping intervals here, [1,3] and [2,4]. 
Therefore we will merge these two and return [1,4], [6,8], [9,10].

Input: arr[] = [[6,8],[1,9],[2,4],[4,7]]
Output: [[1,9]]
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
       vector<vector<int>> ans;
       sort(arr.begin(), arr.end());
       ans.push_back(arr[0]);
       for(int i=1;i<arr.size();i++){
           
           vector<int>&last = ans.back();
           
           if(arr[i][0]<=last[1]){
               
               last[1]=max(last[1],arr[i][1]);
               
           }
           else{
               ans.push_back(arr[i]);
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
