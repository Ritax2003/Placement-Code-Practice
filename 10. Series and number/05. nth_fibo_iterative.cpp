#include <bits/stdc++.h>
using namespace std;

int fib(int n) {
  
      // For 0th and 1st term
    if (n <= 1)
        return n;
    
      // Variable to store the last two terms
    int prev1 = 1, prev2 = 0;
      
      // Variable that stores the current fibonacci term
      int curr;

    // Calculating the next fibonacci number by using
      // the previous two number
    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

int main() {
    int n = 5;
    
      // Finding the nth fibonacci number
    cout << fib(n);
    return 0;
}
