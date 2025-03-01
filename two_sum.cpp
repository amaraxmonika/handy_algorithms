#include <vector>
#include <unordered_map>
#include <assert.h>
#include <iostream>

using namespace std;

// Assuming we are allowed to use extra space, this is the simplest solution
// I've found for the 2sum problem. The other, more involved solution requires
// sorting and then binary search.
// Algorithm runs in O(n) time and requires n extra space for the hash map.
vector<int> two_sum(vector<int>& nums, int target) {
    // Track mapping of value : index for what we've seen
    unordered_map<int, int> seen;

    for (int i = 0; i < nums.size(); i++) {
        int compliment = target - nums[i];
        if (seen.find(compliment) != seen.end()) {
            return vector<int> {seen.find(compliment)->second, i};
        }
        // If not seen, save for future testing
        seen.insert({nums[i], i});

    }
    return vector<int>{0, 0};
}

int main(int argc, char **argv) {

    vector<int> test_values{2, 7, 11, 15};
    auto result = two_sum(test_values, 9);
    auto correct_result = vector<int>{0, 1};
    
    assert(result == correct_result);

    return 0;
}
