#include <bits/stdc++.h>

using namespace std;
bool isArm(int n){
    int num = n;
    int k=0;
    while(num){
        int res = num%10;
        k+=res*res*res;
        num/=10;
    }
    return k == n;
}
int main(){
    int n;
    cin>>n;
    cout<<(isArm(n) ? "true" : "false")<<endl;
}
