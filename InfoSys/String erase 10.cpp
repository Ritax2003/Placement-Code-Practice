/*
You are given a binary string S.
You can perform the following operations on S any number of
times (possibly zero):
• Select an index i such that S[i] is equal to
1 and S[i+1] is equal to 0 for 0 ≤ i < len(S) -1.
• Remove exactly one of the character from S.
Find the smallest string S that you can get after performing
operations on S.

Note:
• If there are multiple smallest strings possible then return the
string which is lexicographically smallest.

Constraints:
• 1 <= len(s) <= 10^5
• 1 <= 𝐴[𝑖] <= 10^5

Sample Input 10000111111
Sample output 1
0000111111
Explanation-1
Here, S = "0000111111" We cannot perform any operation on S so it
remains unchanged

Sample Input 2
1111111
Sample output 2
1111111
Explanation 2
Here, S = "1111111" There exists no 0 in S so we
can not perform any operation on S. Hence, S is
equal to "1111111".


Sample Input 3
110
Sample output 3
0
Explanation 3
Here, S = "110" We can perform two operations on S as :- 1. Select the
index 1 and 2 and remove the character at index 1. Then S becomes
"10". 2. Select the index 0 and 1 and remove the character at index 0.
Then S becomes "0". Hence, S after performing operations is equal to
"0"
*/
// 1st way
#include<bits/stdc++.h>
using namespace std;
string smallestString(string s){
    int i =0;
    while(i<s.length()-1){
        if(s[i]=='1' and s[i+1]=='0'){
            s.erase(i,1);
            i = max(0,i-1);
        }
        else{
            i++;
        }
    }
    return s;
}
int main(){
    string s;
    getline(cin,s);
    string ans = smallestString(s);
    cout<<ans;
}
//2nd way
#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    stack<char> st;
    for(int i = 0; i < s.size(); i++) {
        if(!st.empty() && s[i] == '0') {
            while(st.top() == '1') {
                st.pop();
            }
        }
        st.push(s[i]);

    }
    string ans = "";
    while(!st.empty()) {
        auto curr = st.top();
        ans += curr;
        st.pop();

    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}
