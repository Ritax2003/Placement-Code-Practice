/*
Given an array of strings, return all groups of strings that are anagrams. 
The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.

Note: The final output will be in lexicographic order.

Examples:

Input: arr[] = ["act", "god", "cat", "dog", "tac"]
Output:
act cat tac 
god dog
Explanation: There are 2 groups of anagrams "god", "dog" make group 1. "act", "cat", "tac" make group 2.
Input: arr[] = ["no", "on", "is"]
Output: 
is
no on
Explanation: There are 2 groups of anagrams "is" makes group 1. "no", "on" make group 2.
Constraints:
1<= arr.size() <=100
1<= arr[i].size() <=10
*/
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string,vector<string>>anagramMap;
        vector<string> order;
        for(const string& str: arr){
            string sortedstr = str;
            sort(sortedstr.begin(),sortedstr.end());
            
            if(anagramMap.find(sortedstr)==anagramMap.end()){
                order.push_back(sortedstr);
            }
            
            anagramMap[sortedstr].push_back(str);
        }
        
        vector<vector<string>> res;
        for(const string& entry: order){
            vector<string> grp = anagramMap[entry];
            //sort(grp.begin(),grp.end());
            res.push_back(grp);
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
