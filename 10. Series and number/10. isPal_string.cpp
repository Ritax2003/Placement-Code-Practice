#include <iostream>
using namespace std;

int checkPalindrome(string& s) {
    int len = s.length();

    for (int i = 0; i < len / 2; i++) {

        
        if (s[i] != s[len - i - 1])
            return false;
    }
  
   
    return true;
}

int main() { 
    string s;
    cin>>s;
    if (checkPalindrome(s) == true)
        cout << "true";
    else
        cout << "false";
    return 0;
}
