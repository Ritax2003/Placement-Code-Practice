/*
Given two strings str1 & str 2 of length n & m respectively, return the length of their longest common subsequence. 
If there is no common subsequence then, return 0. 

A subsequence is a sequence that can be derived from the given string by deleting some or no elements without changing the order of the remaining elements.
For example, "abe" is a subsequence of "abcde".

Example 1:
Input: n = 6, str1 = ABCDGH and m = 6, str2 = AEDFHR
Output: 3
Explanation: LCS for input strings “ABCDGH” and “AEDFHR” is “ADH” of length 3.

Example 2:
Input: n = 3, str1 = ABC and m = 2, str2 = AC
Output: 2
Explanation: LCS of "ABC" and "AC" is "AC" of length 2.

Example 3:
Input: n = 4, str1 = XYZW and m = 4, str2 = XYWZ
Output: 3
Explanation: There are two common subsequences of length 3 “XYZ”, and”XYW”, and no common subsequence. of length more than 3.
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
  public:
    
    int fn(vector<vector<int>>&dp,int n,int m,string s1,string s2){
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1])  // Characters match
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else  // Characters don't match
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];  // Length of LCS
    }
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string str1, string str2) {
       vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       int ans = fn(dp,n,m,str1,str2);
       return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m; // Take size of both the strings as input
        string str1, str2;
        cin >> str1 >> str2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, str1, str2) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends
