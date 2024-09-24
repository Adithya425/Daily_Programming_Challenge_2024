#include <iostream>
#include <unordered_set>
using namespace std;

int longestSubstringWithoutRepeating(string s) {
    unordered_set<char> charSet;  // To store characters of current window
    int maxLength = 0;            // Stores the length of the longest substring
    int start = 0;                // Left pointer for the sliding window

    for (int end = 0; end < s.length(); end++) {
        // If character at 'end' is already in the set, remove characters from the start
        while (charSet.find(s[end]) != charSet.end()) {
            charSet.erase(s[start]);
            start++;
        }

        // Add the current character to the set
        charSet.insert(s[end]);

        // Calculate the maximum length of the substring
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << "The length of the longest substring without repeating characters is: " 
         << longestSubstringWithoutRepeating(s) << endl;
    return 0;
}