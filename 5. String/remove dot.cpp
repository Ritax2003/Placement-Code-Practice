/* you have been given a string like abc.de.f , you have to return a vector of seperated string like {abc,de,f}*/
#include <bits/stdc++.h>
using namespace std;
vector<string>fn(string s){
    if(s.size()==1) return {s};
    int i=0,j=0;
    vector<string>ans;
    for(int i=0;i<s.size();i++){
        if(s[i]=='.'){
            ans.push_back(s.substr(j,i-j));
            j=i+1;
            
        }
    }
    ans.push_back(s.substr(j));
    return ans;
}
int main() {
   string s;
   cin>>s;
   vector<string>ans = fn(s);
   
   for(string s:ans){
       cout<<s<<" ";
   }
}
