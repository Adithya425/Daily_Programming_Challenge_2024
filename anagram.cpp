#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGroups;

    for (const string& str : strs) {
        string key = "";
        int count[26] = {0};
        for (char c : str) {
            count[c - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            key += to_string(count[i]) + "-";
        }
        anagramGroups[key].push_back(str);
    }

    vector<vector<string>> result;
    for (const auto& pair : anagramGroups) {
        result.push_back(pair.second);
    }

    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groupedAnagrams = groupAnagrams(strs);

    for (const vector<string>& group : groupedAnagrams) {
        for (const string& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}