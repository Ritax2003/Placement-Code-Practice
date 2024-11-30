#include <bits/stdc++.h>
using namespace std;

// Function to check if a number is an Armstrong number
bool isArm(int n) {
    int num = n;
    int k = 0;
    int digits = 0;

    // Count the number of digits in the number
    while (num) {
        num /= 10;
        digits++;
    }

    num = n;

    // Calculate the sum of each digit raised to the power of 'digits'
    while (num) {
        int res = num % 10;
        k += pow(res, digits);
        num /= 10;
    }

    return k == n; // Return true if it matches the original number
}

// Function to find the Nth Armstrong number
int NthArm(int n) {
    int count = 0;  // Counter for Armstrong numbers
    int i = 1;      // Start checking from 1

    // Loop until we find the Nth Armstrong number
    while (count < n) {
        if (isArm(i)) {
            count++;
            if (count == n) return i; // Return the Nth Armstrong number
        }
        i++;
    }

    return -1; // Fallback case (should not be reached for valid 'n')
}

int main() {
    int n;
    cin >> n; // Input: Find the Nth Armstrong number
    cout << NthArm(n) << endl; // Output the result
}
