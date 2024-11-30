
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    if(n<2) return false;
    for(int i=2;i*i<n;i++){
        if(n%i==0) return false;
    }
    return true;
}
vector<int>primeSeries(int n,int e){
    vector<int>v;
    for(int i=n;i<=e;i++){
        if(isPrime(i)) v.push_back(i);
    }
    return v;
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<int> v= primeSeries(n,e);
    for(auto x: v){
        cout<<x<<" ";
    }
}
