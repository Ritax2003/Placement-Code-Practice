/*
You are given the weights and values of items, and you need to put these items in a knapsack of capacity capacity to achieve the maximum total value in the knapsack. Each item is available in only one quantity.

In other words, you are given two integer arrays val[] and wt[], which represent the values and weights associated with items, respectively.
You are also given an integer capacity, which represents the knapsack capacity. Your task is to find the maximum sum of values of a subset of val[] such that the sum of the weights of the corresponding subset is less than or equal to capacity. You cannot break an item; you must either pick the entire item or leave it (0-1 property).

Examples :

Input: capacity = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
Input: capacity = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).
Input: capacity = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 6, 3] 
Output: 90
Explanation: Choose the second item (value 40, weight 4) and the fourth item (value 50, weight 3) for a total weight of 7,
which exceeds the capacity. Instead, pick the first item (value 10, weight 5) and the second item (value 40, weight 4) for a total value of 50.
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
       int n = wt.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

        // Build the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= capacity; j++) {
                if (wt[i - 1] <= j) {
                    //including item i if weight j allows
                    dp[i][j] = max(
                        dp[i - 1][j], //excluding item i
                        dp[i - 1][j - wt[i - 1]] + val[i - 1] //including item i
                        //to include ith item adding val[i-1] 
                        //and reducing current weight j  by wt[i-1]
                        );
                } else {
                    //excluding item i
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        // Maximum value for given capacity
        return dp[n][capacity];
    }
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
