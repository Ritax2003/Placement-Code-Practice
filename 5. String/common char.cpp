/*
given 2 string A and B in cpp, task is to find leftover string A after removing all letters common within A and B. there can be repeated characters.
*/
#include <bits/stdc++.h>
using namespace std;
string removeCommonLetters(string& A, string& B) {
    // Create a frequency map for characters in string B
   unordered_map<char, int> freqB;
    for (char c : B) {
        freqB[c]++;
    }

    // Resultant string after removing common letters
    string result;
    for (char c : A) {
        // If the character is not present in B, add it to the result
        if (freqB.find(c) == freqB.end()) {
            result += c;
        }
    }

    return result;
}

int main() {
    std::string A = "apple";
    std::string B = "pear";

    std::string result = removeCommonLetters(A, B);
    std::cout << "Leftover string A: " << result << std::endl;

    return 0;
}
