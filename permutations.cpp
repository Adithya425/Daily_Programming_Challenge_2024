#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> generatePermutations(const std::string& str) {
    std::vector<std::string> permutations;
    std::vector<char> chars(str.begin(), str.end());

    do {
        permutations.push_back(std::string(chars.begin(), chars.end()));
    } while (std::next_permutation(chars.begin(), chars.end()));

    return permutations;
}

int main() {
    std::string input = "abc";
    std::vector<std::string> permutations = generatePermutations(input);

    std::cout << "Permutations of " << input << ":\n";
    for (const std::string& permutation : permutations) {
        std::cout << permutation << std::endl;
    }

    return 0;
}