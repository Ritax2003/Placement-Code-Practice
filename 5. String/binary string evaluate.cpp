/*you are given a string like 0A1B1C0D1 of a finite length. 
where 0 and 1 are binary digit and alphabets mean bitwise binary operations like A is and , B is or, C is XOR and D is Not. 
write a code to evaluate the value of a such given string*/
#include <bits/stdc++.h>
using namespace std;
int fn(string b){
    stack<int>st;
    int i = 0;
    while(i<b.length()){
        char ch = b[i];
        if(ch=='0' or ch=='1') st.push(ch-'0');
        else if(ch=='A'){
            int op1 = st.top();
            st.pop();
            int op2 = b[i+1];
            int res = op1&op2;
            st.push(res);
            i++;
        }
        else if(ch=='B'){
            int op1 = st.top();
            st.pop();
            int op2 = b[i+1];
            int res = op1|op2;
            st.push(res);
            i++;
        }
        else if(ch=='C'){
            int op1 = st.top();
            st.pop();
            int op2 = b[i+1];
            int res = op1^op2;
            st.push(res);
            i++;
        }
        else if(ch=='D'){
            int op1 = st.top();
            st.pop();
            int op2 = b[i+1];
            int res = op1&op2;
            st.push(res);
            i++;
        }
        i++;
    }
    return st.top();
}
int main() {
    string b;
    cin>>b;
    cout<<fn(b)<<endl;

    return 0;
}
