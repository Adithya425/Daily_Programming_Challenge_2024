#include <iostream>
#include <unordered_map>
using namespace std;

// Function to count substrings with at most k distinct characters
int countAtMostKDistinct(string s, int k) {
    int n = s.length();
    unordered_map<char, int> freqMap;
    int start = 0, end = 0, count = 0;

    // Sliding window approach
    while (end < n) {
        freqMap[s[end]]++;

        // If we exceed k distinct characters, shrink the window
        while (freqMap.size() > k) {
            freqMap[s[start]]--;
            if (freqMap[s[start]] == 0) {
                freqMap.erase(s[start]);
            }
            start++;
        }

        // Count the number of substrings ending at index 'end'
        count += end - start + 1;
        end++;
    }

    return count;
}

// Function to count substrings with exactly k distinct characters
int countExactKDistinct(string s, int k) {
    return countAtMostKDistinct(s, k) - countAtMostKDistinct(s, k - 1);
}

int main() {
    string s = "pqpqs";
    int k = 2;
    cout << "Number of substrings with exactly " << k << " distinct characters: " 
         << countExactKDistinct(s, k) << endl;
    return 0;
}
