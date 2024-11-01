/*
You are given a string s representing an expression containing various types of brackets: {}, (), and []. Your task is to determine whether the brackets in the expression are balanced. A balanced expression is one where every opening bracket has a corresponding closing bracket in the correct order.

Examples :

Input: s = "{([])}"
Output: true
Explanation: 
- In this expression, every opening bracket has a corresponding closing bracket.
- The first bracket { is closed by }, the second opening bracket ( is closed by ), and the third opening bracket [ is closed by ].
- As all brackets are properly paired and closed in the correct order, the expression is considered balanced.
Input: s = "()"
Output: true
Explanation: 
- This expression contains only one type of bracket, the parentheses ( and ).
- The opening bracket ( is matched with its corresponding closing bracket ).
- Since they form a complete pair, the expression is balanced.
Input: s = "([]"
Output: false
Explanation: 
- This expression contains only one type of bracket, the parentheses ( and ).
- The opening bracket ( is matched with its corresponding closing bracket ).
- Since they form a complete pair, the expression is balanced.
Constraints:
1 ≤ s.size() ≤ 106
s[i] ∈ {'{', '}', '(', ')', '[', ']'}
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isParenthesisBalanced(string& s) {
         // Declare a stack to hold the previous brackets.
    stack<char> stk;
    for (int i = 0; i < s.length(); i++) {
        
        // Check if the character is an opening bracket
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stk.push(s[i]); 
        } 
      
        else {
            // If it's a closing bracket, check if the stack is non-empty
            // and if the top of the stack is a matching opening bracket
            if (!stk.empty() && 
                ((stk.top() == '(' && s[i] == ')') ||
                 (stk.top() == '{' && s[i] == '}') ||
                 (stk.top() == '[' && s[i] == ']'))) {
                stk.pop(); // Pop the matching opening bracket
            }
            else {
                return false; // Unmatched closing bracket
            }
        }
    }
    
    // If stack is empty, return true (balanced), otherwise false
    return stk.empty();
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isParenthesisBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends
