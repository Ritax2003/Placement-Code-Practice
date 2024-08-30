/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minlength = INT_MAX;
        string small;
        for(string s:strs){
            if(s.size() < minlength){
                minlength = s.size();
                small = s;
            }
        }
        
        string ans;
        stack<char>aleph;
        for(int i=0;i<small.size();i++){
            char current = small[i];
            bool allcommon = true;
            for(int k=0;k<strs.size();k++){
                if(strs[k][i]!=current){
                    allcommon = false;
                    break;
                }
            }
                
            if(allcommon) aleph.push(current);
            else break;
         }
        
       while(aleph.size()!=0){
           ans+=aleph.top();
           aleph.pop();
       }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
