#include <iostream>
#include <stack>
#include <unordered_map>

bool isValid(const std::string& s) {
    std::stack<char> parentheses;
    std::unordered_map<char, char> mappings = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : s) {
        if (mappings.count(c)) {  // If it's a closing bracket
            if (parentheses.empty() || parentheses.top() != mappings[c]) {
                return false;
            }
            parentheses.pop();
        } else {  // If it's an opening bracket
            parentheses.push(c);
        }
    }

    return parentheses.empty();
}

int main() {
    std::string input = "[{()}]";
    if (isValid(input)) {
        std::cout << "Valid parentheses" << std::endl;
    } else {
        std::cout << "Invalid parentheses" << std::endl;
    }

    return 0;
}
