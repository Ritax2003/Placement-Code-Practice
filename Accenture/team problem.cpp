/*
Alice is planning to organize a contest with 4 players in each team. 
There are two types of player name Experienced and Fresheres to make the
contest unbiased alice wants to have a team in such a way that each team must contain atleast 1 experienced and 1 freshers.

You are given N number of experienced and M number of freshers. 
Your task is determine the maximum number of team formation possible.
NOTE: No member can join more than one team.

Input format:the first line contain the two separated integer N and M.
Ouput format:print the number that represents the maximum number of team formation possible.

TESTCASE INPUT N=5, M=5 OUPUT is 2
TESTCASE INPUT N=3, M=5 OUTPUT is 2
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int exp,fresh;
    cin>>exp>>fresh;
    int ans = (exp+fresh)/4;

    if(ans<=min(exp,fresh)) cout<<ans<<endl;
    else cout<<min(exp,fresh)<<endl;
    return 0;
}
