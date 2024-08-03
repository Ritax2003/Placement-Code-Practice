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
//using stack
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minlength = INT_MAX;
        string shorts;
        for(string s : strs){
            if(s.size()<minlength){
                shorts =s;
                minlength = s.size();
            }
        }
        
        stack<char>st;
          // Iterate over each character position up to the length of the shortest string
        for (int i = 0; i < minlength; i++) {
            char currentChar = shorts[i];
            bool allMatch = true;

            // Compare the character at position i in all strings
            for (const string& s : strs) {
                if (s[i] != currentChar) {
                    allMatch = false;
                    break;
                }
            }

            if (allMatch) {
                st.push(currentChar);
            } else {
                break;
            }
        }
        string ans="";
        while(st.size()!=0){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//normal
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count=0,min=1000;
        string str;
        for(int i =0;i<strs.size();i++){
            int len = strs[i].length();
            if(len<min){
                min = len;
                str = strs[i];
            }
        }
        for(int i =0;i<min;i++){
            for(int j =0;j<strs.size();j++){
                if(strs[j][i]!=str[i]){
                    return str.substr(0,count);
                }
            }
            count++;
        }
        return str.substr(0,count);
    }
};
