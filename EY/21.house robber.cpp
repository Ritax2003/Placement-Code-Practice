/*
Stickler the thief wants to loot money from a society having n houses in a single line. 
He is a weird person and follows a certain rule when looting the houses.
According to the rule, he will never loot two consecutive houses. 
At the same time, he wants to maximize the amount he loots. 
The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy.
He asks for your help to find the maximum money he can get if he strictly follows the rule. ith house has a[i] amount of money present in it.

Example 1:

Input:
n = 5
a[] = {6,5,5,7,4}
Output: 
15
Explanation: 
Maximum amount he can get by looting 1st, 3rd and 5th house. Which is 6+5+4=15.
Example 2:

Input:
n = 3
a[] = {1,5,3}
Output: 
5
Explanation: 
Loot only 2nd house and get maximum amount of 5.
Your Task:
Complete the functionFindMaxSum() which takes an array arr[] and n as input which returns the maximum money he can get following the rules.

Expected Time Complexity:O(N).
Expected Space Complexity:O(1).

Constraints:
1 ≤ n ≤ 105
1 ≤ a[i] ≤ 104


*/
/*
Explanation:
iterating through each house starting from the third house (index 2) to decide whether Stickler should loot it or skip it. Let's break down the logic:

For each house i, we have two choices to maximize the amount Stickler can loot up to that house:

Skip the Current House i:
If Stickler skips house i, then the maximum amount he can loot up to this house is the same as the maximum amount he could loot up to the previous house, dp[i-1].
This is because if he skips house i, he simply inherits the best result from looting up to house i-1.

Loot the Current House i:
If Stickler loots house i, he cannot loot the previous house i-1 (since he can't loot two consecutive houses).
In this case, he adds the money in house i (a[i]) to the maximum amount looted up to house i-2 (two houses back).
This value is a[i] + dp[i-2], representing the maximum loot amount if he chooses to loot house i.
We then take the maximum of these two choices to find the optimal loot amount up to house i:
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n){
        if(n==0) return 0;
        if(n==1) return arr[0];
        if(n==2) return max(arr[0],arr[1]);
        vector<int> dp(n);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        for(int i=2;i<n;i++){
            int iiskipped = dp[i-1];
            int iistaken = arr[i]+dp[i-2];
            
            dp[i]=max(iiskipped,iistaken);
        }
        
        return dp[n-1];
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends
