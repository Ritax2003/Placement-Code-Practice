/*
You are given a string s. 
We want to partition the string into as many parts as possible so that each letter appears in at most one part. 
Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s. 
Return a list of integers representing the size of these parts.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> partitionlabels(string s){
    unordered_map<char,int> mp;
    vector<int>res;
    for(int i =0;i<s.size();i++){
        mp[s[i]]=i;
    }

    int start = 0,end=0;
    for(int i=0;i<s.size();i++){
        end = max(end,mp[s[i]]);
        if(i==end){
            res.push_back(end-start+1);
            start = i+1;
        }
    }
    return res;
}
int main(){
    string s;
    getline(cin,s);
    vector<int> res = partitionlabels(s);
    for(auto x: res){
        cout<<x<<" ";
    }
}
