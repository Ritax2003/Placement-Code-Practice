/*
Ques 2. Find Maximum Element and its index
A function accepts an array and length, implement the function to find the maximum element of
of array and print mximum element and its index.
The maximum element and its index should be printed in next line.
Conditions:
1. Array index starts with O
2.Maximum element and its index should be separated by new line.
3. Assume there is only 1 maximum element in array.
Sample Input:
1 2 3 4 5 6 7
Output: 7 6
Example 2: 23 45 82 71
output: 8 2
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> largest_number(vector<int>res){
    vector<int>ans;
    int max = INT_MIN;
    int indx = 0;
    for(int i=0;i<res.size();i++){
        if(res[i]>max){
            max = res[i];
            indx = i;
        }
    }
    return {max,indx};
}
int main() {
    vector<int>res;
    for(int i=0;i<6;i++){
        int n;
        cin>>n;
        res.push_back(n);
    }
    
    vector<int>p = largest_number(res);
    cout<<p[0]<<" "<<p[1]<<endl;
    return 0;
}
