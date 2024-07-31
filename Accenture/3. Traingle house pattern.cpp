/*
Ques 1. You have given an integer number N determine the number of bricks needed to
make a house of brick of N levels.
Input: 1
Output: 2
Input: 3
Output: 15
*/

/*
                                                                                                  
2 7 15 ..... series
   2    7    15 ....    
        2    7.....
   2    5    8
     \/    \/
     3      3

2 + (5..8...11 ... series starting with 5 and common AP difference 3, n-1 elements)
2 + [(n-1)/2 [2*5 + (n-1-1)*3]] = n(3n+1)/2

*/
#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int res = n*(3*n+1)/2;
    cout<<res;
}
