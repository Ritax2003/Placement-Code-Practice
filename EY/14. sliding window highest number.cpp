/*
Due to the rise of covid-19 cases in India, this year BCCI decided to organize knock-out matches in IPL rather than a league.
Today is matchday 2 and it is between the most loved team Chennai Super Kings and the most underrated team - Punjab Kings. 
Stephen Fleming, the head coach of CSK, analyzing the batting stats of Punjab. 
He has stats of runs scored by all N players in the previous season and he wants to find the maximum score for each and every contiguous sub-list of size K to strategize for the game.

Example 1:

Input:
N = 9, K = 3
arr[] = 1 2 3 1 4 5 2 3 6
Output: 
3 3 4 5 5 5 6 
Explanation: 
1st contiguous subarray = {1 2 3} Max = 3
2nd contiguous subarray = {2 3 1} Max = 3
3rd contiguous subarray = {3 1 4} Max = 4
4th contiguous subarray = {1 4 5} Max = 5
5th contiguous subarray = {4 5 2} Max = 5
6th contiguous subarray = {5 2 3} Max = 5
7th contiguous subarray = {2 3 6} Max = 6
Example 2:

Input:
N = 10, K = 4
arr[] = 8 5 10 7 9 4 15 12 90 13
Output: 
10 10 10 15 15 90 90
Explanation: 
1st contiguous subarray = {8 5 10 7}, Max = 10
2nd contiguous subarray = {5 10 7 9}, Max = 10 
3rd contiguous subarray = {10 7 9 4}, Max = 10 
4th contiguous subarray = {7 9 4 15}, Max = 15
5th contiguous subarray = {9 4 15 12}, Max = 15 
6th contiguous subarray = {4 15 12 90}, Max = 90 
7th contiguous subarray = {15 12 90 13}, Max = 90 

Your Task:  
You don't need to read input or print anything. 
Complete the function max_of_subarrays() which takes the array, N, and K as input parameters and returns a list of integers denoting the maximum of every contiguous subarray of size K.

Constraints:
1 ≤ N ≤ 106
1 ≤ K ≤ N
0 ≤ arr[i] ≤ 106
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int N, int K) {
         vector<int> result;
    
    // Initial maximum for the first window
    int maxVal = *max_element(arr.begin(), arr.begin() + K);
    result.push_back(maxVal);
    
    // Traverse the array from the second window to the end
    for (int i = 1; i <= N - K; ++i) {
        // If the outgoing element was the maximum, we need to recalculate the max
        if (arr[i - 1] == maxVal) {
            maxVal = *max_element(arr.begin() + i, arr.begin() + i + K);
        } else {
            // If the outgoing element was not the maximum, just compare with the new incoming element
            maxVal = max(maxVal, arr[i + K - 1]);
        }
        
        result.push_back(maxVal);
    }
    
    return result;
    }
};

//or this:
vector<int> maxOfSubarrays(const vector<int>& arr, int N, int K) {
    vector<int> result;
    int maxIdx = -1;  // Store the index of the current max element
    int maxVal = INT_MIN;  // Store the value of the current max element

    // Iterate through the array and slide the window
    for (int i = 0; i <= N - K; ++i) {
        // Check if the previous max is still within the current window
        if (maxIdx < i) {
            // If not, find the new max for the current window
            maxVal = arr[i];
            maxIdx = i;
            for (int j = i + 1; j < i + K; ++j) {
                if (arr[j] > maxVal) {
                    maxVal = arr[j];
                    maxIdx = j;
                }
            }
        } else {
            // If the previous max is still in the window, just compare with the new element entering the window
            if (arr[i + K - 1] > maxVal) {
                maxVal = arr[i + K - 1];
                maxIdx = i + K - 1;
            }
        }

        // Store the max value of the current window
        result.push_back(maxVal);
    }

    return result;
}
//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends
