/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 109
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int &num1,int &num2){
           string a = to_string(num1);
           string b = to_string(num2);
            return a+b>b+a;
        });
        
        string ans ="";
        for(auto  n:nums){
            ans+=to_string(n);
        }
        if(ans[0]!='0') return ans;
        return "0";
    }
};
