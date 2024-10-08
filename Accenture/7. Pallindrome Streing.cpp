#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	
	
	int isPalindrome(string S){
	    int start = 0;
	    int end = S.size()-1;
	    while(start<=end){
	        if(S[start]!=S[end]) return false;
	        start++;
	        end--;
	    }
	    return true;
	}
	

};

int main() {
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
