/*
There are n farmers in an area. Each farmer owns 'X' number of
land. Find the sum of lands owned by all the farmer's(1 based
indexing). The number of land 'X' is the xor operation of the
land owner by his previous farmer and his number.
Input Format:
One line consist of 'N' which represents the number of farmer in
the given area.
Output Format:
Print total number of lands owned by n farmer.
Testcase:
i) n=1
Output -> 1
ii) n=3
Output -> 4
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n+1,0);
    for(int i=1;i<=n;i++){
        v[i] = v[i-1]^i;
    }
    int sum = 0;
    for(auto x:v){
        sum+=x;
    }
    cout<<sum;
    return 0;
}
