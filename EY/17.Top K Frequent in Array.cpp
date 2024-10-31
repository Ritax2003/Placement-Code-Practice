/*
Given a non-empty array arr[] of integers, find the top k elements which have the highest frequency in the array. If two numbers have the same frequencies, then the larger number should be given more preference.

Examples:

Input: arr[] = [3, 1, 4, 4, 5, 2, 6, 1], k = 2
Output: [4, 1]
Explanation: Frequency of 4 = 2, Frequency of 1 = 2. These two have the maximum frequency and 4 is larger than 1.
Input: arr[] = [7, 10,11, 5, 2, 5, 5, 7, 11, 8, 9], k = 4
Output: [5, 11, 7, 10]
Explanation: Frequency of 5 = 3, Frequency of 11 = 2, Frequency of 7 = 2, Frequency of 10 = 1. These four have the maximum frequency and 5 is largest among rest.
Constraints:
1 <= arr.size() <= 105
1<= arr[i] <=105
1 <= k <= no. of distinct elements
*/
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> topKFrequent(vector<int>& arr, int k) {
         unordered_map<int,int>mp;
         for(auto x : arr) mp[x]++;
         
         vector<pair<int,int>>maps;
         for(auto x:mp){
             maps.push_back({x.first,x.second});
         }
          // Sort by frequency first (descending), then by value (descending)
         sort(maps.begin(),maps.end(),[](const pair<int,int>&a, const pair<int,int>&b){
             if(a.second == b.second) return a.first>b.first; // Larger number preference
             return a.second > b.second; // Higher frequency first
             
         });
         
         vector<int>res;
         int i =0;
         while(i!=k){
             res.push_back(maps[i].first);
             i++;
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

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.topKFrequent(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
