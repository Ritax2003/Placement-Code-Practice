/*
There are n students and n*n seats. No two students can sit in the same row or same column. Find the number of
ways to seat n students. Test case N=1 ans=1, N=2 ans=2.

it is permutation problem . n!
*/

#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    
    int result = factorial(n);
    cout << "Number of ways to seat " << n << " students is: " << result << endl;
    
    return 0;
}
