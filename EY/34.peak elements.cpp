/*
Given an 0-indexed array of integers arr[], find its peak element and return its index. An element is considered to be peak if its value is greater than or equal to the values of its adjacent elements (if they exist).

Note: The output will be "true" if the index returned by your function is correct; otherwise, it will be "false".

Examples :

Input: arr = [1, 2, 3]
Output: true
Explanation: If the index returned is 2, then the output printed will be 1. Since arr[2] = 3 is greater than its adjacent elements, and there is no element after it, we can consider it as a peak element. No other index satisfies the same property, so answer will be printed as 0.
Input: arr = [1, 1, 1, 2, 1, 1, 1]
Output: true
Explanation: In this case there are 5 peak elements with indices as {0,1,3,5,6}. Returning any of them will give you correct answer.
Input: arr = [1, 1, 1]
Output: true
Explanation: In this case, all elements are peak elements.
Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int peakElement(vector<int> &arr) {
        int left=0;
        int right=arr.size()-1;
        
        while(left<right){
            int mid = left+(right-left)/2;
            
            if(arr[mid]<arr[mid+1]){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int A = ob.peakElement(a);
        int n = a.size();
        bool f = 0;
        if (A < 0 and A >= n)
            cout << 0 << endl;
        else {
            if (n == 1 and A == 0)
                f = 1;
            else if (A == 0 and a[0] >= a[1])
                f = 1;
            else if (A == n - 1 and a[n - 1] >= a[n - 2])
                f = 1;
            else if (a[A] >= a[A + 1] and a[A] >= a[A - 1])
                f = 1;
            else
                f = 0;
            if (f)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
