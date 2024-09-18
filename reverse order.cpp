#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string reverseWords(string s) {
    
    reverse(s.begin(), s.end());

   
    int start = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            reverse(s.begin() + start, s.begin() + i);
            start = i + 1;
        }
    }
    reverse(s.begin() + start, s.end());

    
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    return s;
}

int main() {
    string s = "the sky is blue";
    string reversed = reverseWords(s);
    cout << reversed << endl;
    return 0;
}