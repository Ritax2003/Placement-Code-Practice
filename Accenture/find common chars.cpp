/*
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 

Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters
*/
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>res;
        for(char st='a';st<='z';st++){
            int mincount = INT_MAX;
            for(string s: words){
                int count=0;
                for(char c:s){
                    if(c==st) count++;
                }
                mincount = min(mincount,count);
            }
            
            for(int i=1;i<=mincount;i++){
                string s(1,st);
                res.push_back(s);
            }
        }
        return res;
    }
};
