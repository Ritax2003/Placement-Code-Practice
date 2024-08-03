#include<bits/stdc++.h>
using namespace std;

vector<string> partitionlabels(string s){
    unordered_map<char,int> mp;
    vector<string>res;
    for(int i =0;i<s.size();i++){
        mp[s[i]]=i;
    }

    int start = 0,end=0;
    for(int i=0;i<s.size();i++){
        end = max(end,mp[s[i]]);
        if(i==end){
            res.push_back(s.substr(start,end-start+1));
            start = i+1;
        }
    }
    return res;
}
int main(){
    string s;
    getline(cin,s);
    vector<string> res = partitionlabels(s);
    for(auto x: res){
        cout<<x<<" ";
    }
}
