

#include <vector>
#include <iostream>

using namespace std;

// How to shift elements in an array
void printArray(vector<int>& nums) {
    for (auto &i : nums) {
        cout << i << ",";
    }
    cout << endl;
}

// Returns the indices of the two values in the array whos sum
// is equal to target.
vector<int> twoSum(vector<int>& nums, int target) {
    int low = 0;
    int hi = nums.size() -1;

    while (low < hi) {
        int sum = nums[low] + nums[hi];

        if (sum == target) {
            return {low, hi};
        } else if (sum < target) {
            low++;
        } else {
            hi--;
        }

    }

    // if no solution found
    return {-1 , -1};
}

int main(int argc, char **argv) {

    vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> result = twoSum(data, 16);
    assert(data[result[0]] + data[result[1]] == 16);

    return 0;
}
