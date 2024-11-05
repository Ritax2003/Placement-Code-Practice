/*
Given a sorted array arr and an integer k, find the position(0-based indexing) at which k is present in the array using binary search.

Examples:

Input: k = 4, arr= [1, 2, 3, 4, 5]  
Output: 3
Explanation: 4 appears at index 3.
Input: k = 445, arr= [11, 22, 33, 44, 55] 
Output: -1
Explanation: 445 is not present.
Expected Time Complexity: O(logn)
Expected Space Complexity: O(logn) 

Note: Try to solve this problem in constant space i.e O(1)

Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 106
1 <= k <= 106
*/

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  int bin(int start,int end,vector<int>&arr,int k){
      while(start<=end){
          int mid = start+(end-start)/2;
          if(arr[mid]==k) return mid;
          if(arr[mid]>k) end = mid-1;
          else start=mid+1;
      }
      return -1;
  }
    int binarysearch(vector<int> &arr, int k) {
        int n = arr.size();
        return bin(0,n-1,arr,k);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<int> arr;
        string input;
        cin.ignore();
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int res = ob.binarysearch(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
