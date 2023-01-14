

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

// Note: The mid calculation isn't simplified to (low + hi) / 2 because that
// has the potential to overflow.
// Note: If the result is not found, then the index of where the result should
// be inserted is returned.
int binarySearch(const vector<int>& nums, int target) {

    int low = 0;
    int hi = nums.size() - 1;
    int mid;

    while (low < hi) {
        mid = low + ((hi - low) / 2);
        if (nums[mid] < target) {
            low = mid + 1;
        } else {
            hi = mid;
        }
        printf("low, mid, hi: %d, %d, %d\n", low, mid, hi);
    }

    return low;
}


int main(int argc, char **argv) {

    vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9};

    int result = binarySearch(data, 3);
    printf("result: %d\n", result);
    assert(data[2] == data[result]);
    result = binarySearch(data, 8);
    printf("result: %d\n", result);
    assert(data[7] == data[result]);

    return 0;
}
