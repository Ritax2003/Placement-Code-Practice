/*Ques 1. A start up wants to expand their empire so the CEO decided to purchase plots at
various locations. He has already figured out some plots and now he is busy, so he wants that
you will select some plots that are square shaped.
Write a code, to help your CEO for finding the all square shaped
Plots.
Input: First line of input will have the total shortlisted plots by the CEO
Second line represents N space separated integers denoting the area of the plots.
Output: Find out how many plots are there to build a new office
Example:
Input: 6
64
16
38
81
100
25
Output: 4
*/
#include<bits/stdc++.h>
using namespace std;
int perfect_sqr(vector<int>res){
    int count =0;
    for(int i =0;i<res.size();i++){
        if(ceil(sqrt(res[i])) == floor(sqrt(res[i]))) count++;
    }
    return count;
}
int main() {
    vector<int>res;
    for(int i=0;i<6;i++){
        int n;
        cin>>n;
        res.push_back(n);
    }
    
    int ans = perfect_sqr(res);
    cout<<ans;
    return 0;
}
