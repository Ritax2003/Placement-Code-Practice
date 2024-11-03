/*
In daily share trading, a buyer buys shares in the morning and sells them on the same day. 
If the trader is allowed to make at most 2 transactions in a day, the second transaction can only start after the first one is complete (buy->sell->buy->sell).
The stock prices throughout the day are represented in the form of an array of prices. 

Given an array price of size n, find out the maximum profit that a share trader could have made.

Example 1:

Input:
n = 6
prices[] = {10,22,5,75,65,80}
Output:
87
Explanation:
Trader earns 87 as sum of 12 and 75. Buy at 10, sell at 22, Buy at 5 and sell at 80.

Explanation
Initialization:

leftProfit[i] stores the maximum profit achievable by making a single transaction from day 0 to day i.
rightProfit[i] stores the maximum profit achievable by making a single transaction from day i to the last day.
Calculate Left Profits:

Loop from the beginning to the end, tracking the minimum price seen so far.
For each day i, leftProfit[i] will hold the maximum profit that could have been achieved by completing a transaction by that day.
Calculate Right Profits:

Loop from the end to the beginning, tracking the maximum price seen so far.
For each day i, rightProfit[i] will hold the maximum profit that could have been achieved by starting a transaction on that day.
Combine Profits:

For each day i, combine leftProfit[i] and rightProfit[i] to get the maximum profit possible with two transactions.
The maximum of these sums across all days will be the answer.
Complexity Analysis
Time Complexity: 
𝑂
(
𝑛
)
O(n), where 
𝑛
n is the number of prices, since we make three passes over the array.
Space Complexity: 
𝑂
(
𝑛
)
O(n) for the leftProfit and rightProfit arrays.
*/
//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            int n= price.size();
            if(n==0) return 0;
            
            vector<int>leftprofit(n,0);
            vector<int>rightprofit(n,0);
            
            int min_price=price[0];
            
            for(int i=1;i<n;i++){
                min_price=min(min_price,price[i]);
                leftprofit[i]=max(leftprofit[i-1],price[i]-min_price);
            }
            
            int max_price= price[n-1];
            
            for(int i=n-2;i>=0;i--){
                max_price=max(max_price,price[i]);
                rightprofit[i]=max(rightprofit[i+1],max_price-price[i]);
            }
            int max_profit = 0;
            for(int i=0;i<n;i++){
                max_profit = max(max_profit,leftprofit[i]+rightprofit[i]);
            }
            
            return max_profit;
        }
        
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    
cout << "~" << "\n";
}

}

// } Driver Code Ends
