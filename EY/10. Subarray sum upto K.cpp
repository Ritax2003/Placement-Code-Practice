/*
Given an unsorted array of integers, find the number of continuous subarrays having sum exactly equal to a given number k.


Examples:

Input: k = -10, arr = [10, 2, -2, -20, 10]
Output: 3
Explaination: 
Subarrays: arr[0...3], arr[1...4], arr[3..4]
have sum exactly equal to -10.
Input: k= 33, arr = [9, 4, 20, 3, 10, 5]
Output: 2
Explaination: 
Subarrays : arr[0...2], arr[2...4] have sum
exactly equal to 33.
Constraints:
1 ≤ arr.size() ≤ 2*104
-103 ≤ arr[i] ≤ 103
-107 ≤ k ≤ 107
*/
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findSubArraySum(int k, vector<int> &nums) {
       unordered_map<int, int> prefixCount;  // Store the frequency of prefix sums
    prefixCount[0] = 1;  // Handle the case when prefix sum equals k initially

    int prefixSum = 0;
    int count = 0;

    for (int num : nums) {
        prefixSum += num;  // Calculate the prefix sum

        // Check if (prefixSum - k) exists in the map
        if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
            count += prefixCount[prefixSum - k];
        }

        // Update the frequency of the current prefix sum
        prefixCount[prefixSum]++;
    }

    return count;
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
        cout << obj.findSubArraySum(k, arr);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
