#include <bits/stdc++.h>
using namespace std;

// Function to check if a number is an Armstrong number
bool isArm(int n) {
     int num = n;
    int k=0;
    while(num){
        int res = num%10;
        k+=res*res*res;
        num/=10;
    }
    return k == n;
}

vector<int>Armseries(int start,int end){
    vector<int> res;
    for(int i=start;i<=end;i++){
        if(isArm(i)) res.push_back(i);
    }
    return res;
}

int main() {
    int s,e;
    cin >>s>>e; // Input: Find the Nth Armstrong number
    vector<int> ans = Armseries(s,e); 
    for(auto i:ans){
        cout<<i<<" ";
    }
}
