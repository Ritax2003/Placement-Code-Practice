/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1) return s;
        int n = s.length();
        int maxsize=1;
        int start=0;
        int end=0;
        vector<vector<bool>>dp(n,vector<bool>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i] =1;
            for(int j=0;j<i;j++){
                if(s[i]==s[j] and (i-j==1 or dp[j+1][i-1])){
                    dp[j][i]=1;
                    if(i-j+1 > maxsize){
                        maxsize = i-j+1;
                        start = j;
                        end= i;
                    }
                }
            }
        }
        return s.substr(start,end-start+1);
    }
};
