#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> findSubarraysWithSumK(const vector<int>& nums, int k) {
    unordered_map<int, vector<int>> prefixMap;  // Map to store prefix sums and their ending indices
    prefixMap[0].push_back(-1);  // Handle case where prefix sum itself is equal to k

    vector<vector<int>> result;  // To store the result subarrays
    int prefixSum = 0;

    for (int i = 0; i < nums.size(); ++i) {
        prefixSum += nums[i];  // Calculate the prefix sum

        // Check if (prefixSum - k) exists in the map
        if (prefixMap.find(prefixSum - k) != prefixMap.end()) {
            // Collect all subarrays ending at the current index with sum k
            for (int startIdx : prefixMap[prefixSum - k]) {
                vector<int> subarray(nums.begin() + startIdx + 1, nums.begin() + i + 1);
                result.push_back(subarray);  // Add the subarray to the result
            }
        }

        // Add the current prefix sum with the current index to the map
        prefixMap[prefixSum].push_back(i);
    }

    return result;  // Return the result containing all found subarrays
}

// Example usage
int main() {
    vector<int> nums = {10, 2, -2, -20, 10};
    int k = -10;

    vector<vector<int>> subarrays = findSubarraysWithSumK(nums, k);

    // Print the result
    for (const auto& subarray : subarrays) {
        cout << "Subarray with sum " << k << ": [";
        for (size_t j = 0; j < subarray.size(); ++j) {
            cout << subarray[j] << (j < subarray.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    }

    return 0;
}
