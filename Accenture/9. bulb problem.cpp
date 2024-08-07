/*
There are n bulbs that are initially off. You first turn on all the bulbs, then you turn off every second bulb.
On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). 
For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb.
Return the number of bulbs that are on after n rounds.

 
Example 1:
Input: n = 3
Output: 1
Explanation: At first, the three bulbs are [off, off, off].
After the first round, the three bulbs are [on, on, on].
After the second round, the three bulbs are [on, off, on].
After the third round, the three bulbs are [on, off, off]. 
So you should return 1 because there is only one bulb is on.

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 1
 

Constraints:
0 <= n <= 109

To solve the problem of determining how many bulbs are on after n rounds, we can use an observation related to the properties of the bulb toggling pattern:
A bulb will end up being toggled in rounds that correspond to its divisors.
A bulb ends up on if it is toggled an odd number of times. This happens if and only if the number has an odd number of divisors.
A number has an odd number of divisors if and only if it is a perfect square. This is because divisors usually come in pairs, except when the number is a perfect square (e.g., for 9, the divisors are 1, 3, and 9).
From the above, it follows that the bulbs that remain on are those in the positions of perfect squares (1, 4, 9, 16, ...).

Given n, the number of bulbs that remain on is the number of perfect squares less than or equal to n. This is equivalent to counting the integers k such that 
𝑘
2
≤
𝑛
k 
2
 ≤n. The number of such integers is the integer part of the square root of n.

Here's the implementation of this logic in Python:

*/
class Solution {
public:
    int bulbSwitch(int n) {
        return pow(n,0.5);
    }
};
