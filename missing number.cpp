#include <iostream>
#include <vector>

using namespace std;

int findMissingNumber(vector<int> arr) {
    int n = arr.size() + 1;
    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;

    for (int num : arr) {
        actualSum += num;
    }

    return expectedSum - actualSum;
}

int main() {
    vector<int> arr = {1,2,4,5};
    int missingNumber = findMissingNumber(arr);
    cout << "The missing number is: " << missingNumber << endl;
    return 0;
}