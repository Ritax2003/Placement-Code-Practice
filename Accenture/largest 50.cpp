/*
Given an array containing N elements. Each element is either 0 or 5. Find the
largest number divisible by 90 that can be made using any number of elements
of this array and arranging them in any way.
*/
#include<bits/stdc++.h>
using namespace std;
string number(vector<int> v){
    unordered_map<int,int>mp;
    int five=0,zero=0;
    for(int x:v){
        if(x==0) zero++;
        if(x==5) five++;
    }
    if (zero == 0) return "0";
    
    // Find the largest number of 5's that is a multiple of 9
    int max_fives = (five / 9) * 9;
    
    // If we cannot form a number divisible by 9 with the available 5's, return "0"
    if (max_fives == 0) return "0";
    
    // Construct the largest number divisible by 90
    string s(max_fives, '5');  // Add all the 5's
    s.append(zero, '0');       // Append all the 0's at the end
    
    
    return s;

}
int main(){
    
    int size;
    cin>>size;
    vector<int>v(size);
    for(int i=0;i<size;i++){
        cin>>v[i];
    }
    cout<<number(v)<<endl;
}
