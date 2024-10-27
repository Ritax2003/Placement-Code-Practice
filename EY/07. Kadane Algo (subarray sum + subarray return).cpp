#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, vector<int>> maxSubArraySum(const vector<int>& nums) {
    int maxSum = nums[0], currentSum = nums[0];
    int start = 0, end = 0, tempStart = 0;

    for (size_t i = 1; i < nums.size(); ++i) {
        if (nums[i] > currentSum + nums[i]) {
            currentSum = nums[i];
            tempStart = i;  // Start a new subarray
        } else {
            currentSum += nums[i];  // Extend the current subarray
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;  // Update the start index
            end = i;             // Update the end index
        }
    }

    // Extract the subarray from the start to end index
    vector<int> subarray(nums.begin() + start, nums.begin() + end + 1);

    return {maxSum, subarray};
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    auto [maxSum, subarray] = maxSubArraySum(nums);

    cout << "Maximum Subarray Sum: " << maxSum << endl;
    cout << "Subarray: ";
    for (int num : subarray) {
        cout << num << " ";
    }
    cout << "\nLength: " << subarray.size() << endl;

    return 0;
}
