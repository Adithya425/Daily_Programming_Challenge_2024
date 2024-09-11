#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int>& nums) {
    int slow = 0, fast = 0;

    // Detect a cycle
    while (true) {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast) {
            break;
        }
    }

    // Find the starting point of the cycle
    int start = 0, cycle = slow;

    while (start != cycle) {
        start = nums[start];
        cycle = nums[cycle];
    }

    return start;
}

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    int duplicate = findDuplicate(nums);
    cout << "Duplicate number: " << duplicate << endl;
    return 0;
}