/*
Given an array a[ ] of n integers, find the Length of the Longest Strictly Increasing Subsequence.

A sequence of numbers is called "strictly increasing" when each term in the sequence is smaller than the term that comes after it.

Example 1:

Input: n = 6, a[ ] = {5,8,3,7,9,1}
Output: 3
Explanation: There are more than one LIS in this array.  
One such Longest increasing subsequence is {5,7,9}.
Example 2:

Input: n = 16, a[ ] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15}
Output: 6
Explanation: There are more than one LIS in this array. 
One such Longest increasing subsequence is {0,2,6,9,13,15}.
Your Task:
You do not need to read input or print anything.
Complete the function longestSubsequence() which takes the given array and its size as input parameters and returns the length of the longest increasing subsequence.

Expected Time Complexity : O( n*log(n) )
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ n ≤ 104
0 ≤ a[i] ≤ 106


*/
// Function to find the first element in `lis` that is greater than or equal to `key`
int binarySearch(vector<int>& lis, int key) {
    int left = 0, right = lis.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (lis[mid] >= key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int longestIncreasingSubsequence(int a[], int n) {
    vector<int> lis;

    for (int i = 0; i < n; i++) {
        int pos = binarySearch(lis, a[i]);
        if (pos == lis.size()) {
            // Element is greater than all elements in lis, extend the subsequence
            lis.push_back(a[i]);
        } else {
            // Element can replace an existing element to maintain smaller tails
            lis[pos] = a[i];
        }
    }

    return lis.size();
}
