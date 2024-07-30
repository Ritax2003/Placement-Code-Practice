#include<bits/stdc++.h>
using namespace std;

vector<int>maxSubArray(vector<int> res){
    vector<int>res2;
    int max = INT_MIN;
    int start =0,end=0;
    int sum =0;
    for(int i=0;i<res.size();i++){
        sum+=res[i];
        if(max<sum){
            max = sum;
            end = i;
        }
        if(sum<0){
            start = i+1;
            end = i+1;
            sum = 0;
        }
    }

    res2.push_back(start);
    res2.push_back(end);
    return res2;
    }
int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int>res;
    for(int i=0;i<n;i++){
        int key;
        cin>>key;
        res.push_back(key);
    }
    vector<int>res2 = maxSubArray(res);
    cout<<"start index "<<res2[0]<<endl;
    cout<<"end index "<<res2[1]<<endl;
    cout<<"The SubArray"<<endl;
    for(int i=res2[0];i<=res2[1];i++){
        cout<<res[i]<<" ";
    }
}
