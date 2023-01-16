
#include <vector>
#include <iostream>

using namespace std;

void printArray(vector<int>& nums) {
    for (auto &i : nums) {
        cout << i << ",";
    }
    cout << endl;
}

void moveZeroes(vector<int>& nums) {
    int zeroCount = 0;

    for (int i = 0; i < nums.size();) {
        if (nums[i] == 0) {
            // move it to the back
            printf("found zero at: %d\n", i);
            zeroCount++;
            for (int j = i; j < nums.size()-1; j++) {
                nums[j] = nums[j+1];
            }
        } else {
            i++;
        }
    }

    // write zeroes to end
    for (int i = nums.size() - 1; i >= nums.size() - zeroCount; i--) {
        nums[i] = 0;
    }
}

// This method is 'fancy' because it requires only a single iteration over
// nums. It has a runtime complexity of O(n) and a space complexity of O(1).
void moveZeroesFancy(vector<int>& nums) {
    int lastNonZeroIndex = 0;
    int tmp;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            tmp = nums[i];
            nums[i] = nums[lastNonZeroIndex];
            nums[lastNonZeroIndex++] = tmp;
        }
    }
}

int main(int argc, char **argv) {

    vector<int> data{1, 0, 3, 0, 0, 6, 7, 8, 9};

    // printArray(data);
    // moveZeroes(data);
    // printArray(data);
    //
    // vector<int> data2{0};
    //
    // printArray(data);
    // moveZeroes(data);
    // printArray(data);
    printArray(data);
    moveZeroesFancy(data);
    printArray(data);
    return 0;
}
