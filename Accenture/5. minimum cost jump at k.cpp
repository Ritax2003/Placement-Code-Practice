/*
There are n points on the x-axis (1, 2, 3,., n) where the f" point has a cost associated denoted by
cost[i].
Starting from coordinate x = 0, jumps of length k can be taken. Wherever a stop is made, the cost of that
point is incurred. Find the minimum cost to reach the point n taking jumps of length at most k.
Example:
Consider n • 5, cost • [4, 3, 9, 3, 1], and k = 2.
The optimal jump pattern is 0 - 2 - 4 - 5. The cost of stopping at points 2, 4, and 5 is 3 + 3 + 1 = 7,
the minimum possible.
Function Description
Complete the function getMinimumCost in the editor below.
getMinimumCost has the following parameters:
int cost(n]: the cost incurred at each point
int k: the maximum jump length
Returns:
long_ int: the minimum total cost incurred to reach point n
Constraints
• 1 <= n <= 3 * 10$|
• 1 <= k <= n|
• 1 <= cost[i] ≤ 10^9
*/

#include<bits/stdc++.h>
using namespace std;
long int minimum_cost(vector<int>res,int k){
    int n = res.size();
    vector<long int> dp(n + 1, INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=min(i,k);j++){
            dp[i]= min(dp[i],dp[i-j]+res[i-1]);
        }
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<"--------------"<<endl;
    vector<int>cost(n,0);

    for(int i=0;i<n;i++){
        cin >> cost[i];
    }
    int k;
    cout<<"--------------"<<endl;
    cin>>k;
    long int ans = minimum_cost(cost,k);
    cout<<"--------------"<<endl;
    cout<<ans;
}
