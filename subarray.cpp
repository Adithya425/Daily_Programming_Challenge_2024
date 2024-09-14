#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<pair<int, int>> findZeroSumSubarrays(vector<int>& arr) {
    vector<pair<int, int>> result;
    int prefixSum = 0;
    unordered_map<int, int> sumIndexMap;
    sumIndexMap[0] = -1;

    for (int i = 0; i < arr.size(); ++i) {
        prefixSum += arr[i];
        if (sumIndexMap.count(prefixSum)) {
            int start = sumIndexMap[prefixSum] + 1;
            int end = i;
            result.push_back({start, end});
        }
        sumIndexMap[prefixSum] = i;
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, -3, 3, -1, 2};
    vector<pair<int, int>> subarrays = findZeroSumSubarrays(arr);

    cout << "Subarrays with zero sum: " << endl;
    for (const auto& subarray : subarrays) {
        cout << "[" << subarray.first << ", " << subarray.second << "]" << endl;
    }

    return 0;
}