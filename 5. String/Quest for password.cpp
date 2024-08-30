/*
Quest for the Hidden Code
In a remote village, there existed two mystical strings S, and 52. in
these strings was hidden a secret encoded in their characters.
Your task is to find and return an integer value representing the
encoded secret of the strings by finding the sum of the ASGIl values
of the characters in the
longest common substring betwed
hese
two strings. Return 0 if there is no common substring
Note:
Strings 5, and 52 contain English alphabets in lower case only.
• If there are multiple longest common substrings, then return the ASCI!
sum of the substring that occurs first.
*/
#include <bits/stdc++.h>
using namespace std;
string fn1(string &s1,string &s2){
    int n = s1.size();
    int m = s2.size();
    
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int max_len = 0;
    int end = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                if(dp[i][j]>max_len){
                    max_len = dp[i][j];
                    end = i;
                }
            }
            else dp[i][j]=0;
        }
    }
    return s1.substr(end-max_len,max_len);
}
int fn2(string s){
    int res=0;
    for(char c:s){
        res+=int(c);
    }
    return res;
}
int main() {
    // Write C++ code here
    string s1,s2;
    cin>>s1>>s2;
    cout<<fn2(fn1(s1,s2))<<endl;
}
