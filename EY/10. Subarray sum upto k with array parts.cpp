#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void printSubarraysWithSumK(const vector<int>& nums, int k) {
    unordered_map<int, vector<int>> prefixMap;  // Map to store prefix sums and their indices
    prefixMap[0].push_back(-1);  // Handle case where prefix sum itself is equal to k

    int prefixSum = 0;

    for (int i = 0; i < nums.size(); ++i) {
        prefixSum += nums[i];  // Calculate the prefix sum

        // Check if (prefixSum - k) exists in the map
        if (prefixMap.find(prefixSum - k) != prefixMap.end()) {
            // Print all subarrays ending at the current index with sum k
            for (int startIdx : prefixMap[prefixSum - k]) {
                cout << "Subarray with sum " << k << ": [";
                for (int j = startIdx + 1; j <= i; ++j) {
                    cout << nums[j] << (j < i ? ", " : "");
                }
                cout << "]\n";
            }
        }

        // Add the current prefix sum with the current index to the map
        prefixMap[prefixSum].push_back(i);
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 5;
    cout << "Subarrays with sum " << k << ":\n";
    printSubarraysWithSumK(nums, k);
    return 0;
}
