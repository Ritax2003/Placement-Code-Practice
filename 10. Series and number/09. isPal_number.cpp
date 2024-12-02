#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int temp = n;
    int rev = 0;
    while(temp!=0){
        int rem = temp%10;
        rev = rev*10 +rem;
        temp/=10;
    }
    if(n==rev) cout<<"Pal";
    else cout<<"Non Pal";

}
