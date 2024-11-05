/*
Given two sorted arrays a and b of size m and n respectively. You need to find and return the median of the two sorted arrays.

Note: Assume that the two sorted arrays are merged and then median is selected from the combined array.

Examples:

Input: a[] = [1, 5, 9], b[] = [2, 3, 6, 7]
Output: 5
Explanation: If we merge the arrays and sort them then it will become [1, 2, 3, 5, 6, 7, 9] The middle element for [1, 2, 3, 5, 6, 7, 9] is 5
Input: a[] = [4, 6], b[] = [1, 2, 3, 5]
Output: 3.5
Explanation: If we merge the arrays and sort them then it will become [1, 2, 3, 4, 5, 6]. Since the arrays size of now even, hence the median is the average of the two middle elements.
The two middle elements here are 3 and 4 hence the median is (3+4)/2 = 3.5
Input: a[] = [4], b[] = [1, 2]
Output: 2
Explanation: If we merge the arrays then it will become [1, 2, 4]. The median of the resultant array is the middle element after sorting it. Hence the answer is 2.

Constraints: 
1 ≤ a.size(), b.size() ≤ 106
1 ≤ a[i], b[i] ≤ 109


*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    double medianOfSortedArrays(vector<int>& a, vector<int>& b) {
       int asize=a.size();
       int bsize=b.size();
       int i=0;
       int j=0;
       vector<int>res;
       while(i<asize and j<bsize){
           if(a[i]<b[j]){
               res.push_back(a[i]);
               i++;
           }
           else{
               res.push_back(b[j]);
               j++;
           }
       }
       
       while(i<asize){
           res.push_back(a[i]);
           i++;
       }
       while(j<bsize){
           res.push_back(b[j]);
           j++;
       }
       
       int size = res.size();
       int mid = size/2;
       
       if(size%2==1) return res[mid];
       return (res[mid]+res[mid-1])/2.0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline after reading `t`

    while (t--) {
        // Read the first array
        string line1;
        getline(cin, line1);
        stringstream ss1(line1);

        vector<int> array1;
        int num;
        while (ss1 >> num) {
            array1.push_back(num);
        }

        // Read the second array
        string line2;
        getline(cin, line2);
        stringstream ss2(line2);

        vector<int> array2;
        while (ss2 >> num) {
            array2.push_back(num);
        }

        // Create a Solution object and calculate the median
        Solution ob;
        if (array2.size() == 1 && array2[0] == 0) {
            array2.pop_back();
        }

        double ans = ob.medianOfSortedArrays(array1, array2);
        if (ans == (int)ans) {
            cout << (int)ans << endl;
        } else {
            cout << ans << endl;
        }
    }

    return 0;
}

// } Driver Code Ends
