/*
Given two strings str1 and str2. Return the minimum number of operations required to convert str1 to str2.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
Examples:

Input: str1 = "geek", srt2 = "gesek"
Output: 1
Explanation: One operation is required, inserting 's' between two 'e'.
Input : str1 = "gfg", str2 = "gfg"
Output: 0
Explanation: Both strings are same.
Expected Time Complexity: O(|str1|*|str2|)
Expected Space Complexity: O(|str1|*|str2|)

Constraints:
1 ≤ str1.length(), str2.length() ≤ 100
Both the strings are in lowercase.
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int editDistance(string str1, string str2) {
       int m = str1.size();
       int n = str2.size();

    // Create a 2D DP table with (m+1) x (n+1) dimensions
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialize the base cases
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;  // Deleting all characters from str1
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;  // Inserting all characters to str1
    }

    // Fill the DP table using the state transition formula
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // No operation needed
            } else {
                    int insert = dp[i][j-1]+1;
                    int remove = dp[i-1][j]+1;
                    int replace = dp[i-1][j-1]+1;
                    
                    dp[i][j]=min(remove,min(remove,replace));
            }
        }
    }

    // The answer is in the bottom-right corner of the table
    return dp[m][n];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
