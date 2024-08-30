/*
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/
#include <bits/stdc++.h>
using namespace std;
string fn(string st){
    if(st.size()==0) return st;
    unordered_map<char,int>mp;
    int i=0,j=0,ans=0;
    int start =0;
    while(j<st.size()){
        mp[st[j]]++;
        if(mp.size() == j-i+1){
            if(j-i+1>ans){
                ans = j-i+1;
                start = i;
            }
        }
        else if(mp.size()<j-i+1){
            while(mp.size()<j-i+1){
                mp[st[i]]--;
                if(mp[st[i]]==0) mp.erase(st[i]);
                i++;
            }
        }
        j++;
    }
    return st.substr(start,ans);
}
int main() {
    string st;
    cin>>st;
    cout<<fn(st)<<endl;

    return 0;
}
