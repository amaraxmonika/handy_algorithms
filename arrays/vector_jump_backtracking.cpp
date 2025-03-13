#include <vector>
#include <unordered_set>
#include <iostream>
#include <assert.h>


using namespace std;


// This is an example of a backtracking algorithm used to determine
// if there exists a path in the vector such that a sequence of jumps
// starting from index 0 will end at the last element.
// Note the usage of a set to track indices we have already seen.
//
bool can_jump(vector<int>& nums, unordered_set<int>& seen, int index) {
    if (index >= nums.size() - 1) {
        // Base case where a solution is found
        return true;
    }

    if (nums[index] == 0) {
        // Base case where there are no moves left and we
        // are not at the last index
        return false;
    }

    if (!seen.insert(index).second) {
        // If we have already seen this index and not returned true
        // then a solution including it does not exsit, so skip.
        return false;
    }

    int current_jump = nums[index];

    for (int i = current_jump; i > 0; i--) {
        if (can_jump(nums, seen, index + i)) {
            return true;
        }
    }

    // All options are exhausted
    return false;
}

int main() {
    vector<int> nums{2, 3, 1, 1, 4};
    unordered_set<int> seen;
    assert(can_jump(nums, seen, 0) == true);
    return 0;
}
