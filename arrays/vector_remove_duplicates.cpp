#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

int remove_duplicates(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int count = 1;
    int i = 1;

    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] == nums[j - 1]) {
            count++;
        } else {
            count = 1;
        }

        if (count <= 2) {
            nums[i++] = nums[j];
        }
    }
    return i;
}

int main() {
    vector<int> dups{1, 2, 2, 2, 2, 2, 3};
    int result_size = remove_duplicates(dups);
    assert(result_size == 4);
    return 0;
}

