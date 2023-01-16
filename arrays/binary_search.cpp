

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

    while (low <= hi) {
        mid = low + ((hi - low) / 2);
        if (nums[mid] < target) {
            low = mid + 1;
        } else if (nums[mid] > target) {
            hi = mid - 1;
        } else {
            return mid;
        }
    }

    return low;
}

// If the value we are searching for is duplicated, then this
// returns the index of the leftmost or first instance of the
// target. Note that this differs from the the rightmost
// implementation only by the comparison 'nums[mid] < target'
// and by the value returned 'low' instead of 'hi - 1'.
int binarySearchLeftmost(const vector<int>& nums, int target) {

    int low = 0;
    int hi = nums.size();
    int mid;

    while (low < hi) {
        mid = low + ((hi - low) / 2);
        if (nums[mid] < target) {
            low = mid + 1;
        } else {
            hi = mid;
        }
    }

    return low;
}

// If the value we are searching for is duplicated, then this
// returns the index of the rightmost or last instance of the
// target. Note that this implementation differs from the leftmost
// implementation only by the comparison 'nums[mid] <= target' and
// by the value that is returned 'hi - 1'.
int binarySearchRightmost(const vector<int>& nums, int target) {

    int low = 0;
    int hi = nums.size();
    int mid;

    while (low < hi) {
        mid = low + ((hi - low) / 2);
        if (nums[mid] <= target) {
            low = mid + 1;
        } else {
            hi = mid;
        }
    }

    return hi - 1;
}


int main(int argc, char **argv) {

    vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9};

    int result = binarySearch(data, 3);
    printf("result: %d\n", result);
    assert(data[2] == data[result]);
    result = binarySearch(data, 8);
    printf("result: %d\n", result);
    assert(data[7] == data[result]);
    assert(binarySearchLeftmost(data, 8) == binarySearchRightmost(data, 8));

    vector<int> data2{1, 2, 3, 3, 3, 3, 3, 6, 7};
    result = binarySearchLeftmost(data2, 3);
    printf("leftmost result: %d\n", result);
    assert(result == 2);
    result = binarySearchRightmost(data2, 3);
    printf("last result: %d\n", result);
    assert(result == 6);

    return 0;
}
