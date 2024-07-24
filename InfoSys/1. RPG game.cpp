/*
While playing an RPG game, you were assigned to complete one of the hardest quests in this game. 
There are n monsters you'll need to defeat in this quest. Each monster i is described with two integer 
numbers - poweri 
and bonusi
 . To defeat this monster, you'll need at least poweri
 experience points. If 
you try fighting this monster without having enough experience points, you lose immediately. You will 
also gain bonusi 
experience points if you defeat this monster. You can defeat monsters in any order. 
The quest turned out to be very hard - you try to defeat the monsters but keep losing repeatedly. Your 
friend told you that this quest is impossible to complete. Knowing that, you're interested, what is the 
maximum possible number of monsters you can defeat? 

*/
#include<bits/stdc++.h>
using namespace std;
int helper(vector<int> &power,vector<int> &bonus, int n, int exp){
    vector<pair<int,int>> res;
    for(int i=0;i<n;i++){
        res.push_back({power[i],bonus[i]});
    }
    sort(res.begin(),res.end(),[](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first > b.first;
    });

    int ans =0;
    while(res.size()!=0){
        if(res[res.size()-1].first <= exp){
            exp +=res[res.size()-1].second;
            ans++;
            res.pop_back();
        }
        else{
            break;
        }
    }
    return ans;
    
    }
int main(){
    int n ,exp;
    cin>>n>>exp;
    vector<int>power(n);
    vector<int>bonus(n);
    for(int i=0;i<n;i++) cin>>power[i];
    for(int i=0;i<n;i++) cin>>bonus[i];
    int ans = helper(power,bonus,n,exp);
    cout<<ans;
}
