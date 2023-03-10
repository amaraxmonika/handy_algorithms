
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

// Shifts every element in the array to the right by 1. The element at the back
// will wrap around and be written to the front. I have not found a good use
// for this one yet.
// Ex. {1, 2, 3, 4, 5} => {5, 1, 2, 3, 4}
void shiftArrayOnce(vector<int>& nums) {

    int prev = nums[nums.size() - 1];
    for (int i = 0; i < nums.size(); i++) {
        int current = nums[i];
        nums[i] = prev;
        prev = current;
    }
}

// Shifts every element in the array to the right by n times. The elemets at
// the back will wrap around and be written to the front.
// Ex. {1, 2, 3, 4, 5}, shift 3 => {3, 4, 5, 1, 2}
// This solution is broken because I exceed the bounds for the input array.
void shiftArrayN(vector<int>& nums, int count) {

    // set to number of rotations and prefill with 0
    vector<int> prev(count,0);
    vector<int> current(count,0);
    // save last n elements from array
    int index = 0;
    for (int i = nums.size() - count; i < nums.size(); i++) {
        prev[index++] = nums[i];
    }

    for (int i = 0; i < nums.size(); i+=count) {
        // int current = nums[i];

        for (int j = 0; j < current.size(); j++) {
            current[j] = nums[i+j];
        }
        // nums[i] = prev;
        for (int j = 0; j < prev.size(); j++) {
            nums[i+j] = prev[j];
        }
        for (int j = 0; j < prev.size(); j++) {
            prev[j] = current[j];
        }
        // prev = current;
    }
}

// This solution works because it brings all the wrapped elements to the front
// by reversing the entire array.
// So first we have count=3 and the array
// {a, b, c, d, e, f} which is then reversed so we have
// {f, e, d, c, b, a} Now the clever part is where the shifted values are
//                    un-reversed in their own sub-array.
// {d, e, f, c, b, a} Finally we un-reverse the second sub-array yielding
// {d, e, f, a, b, c}.
// Note that count % shiftLen is necessary in general because shifting
// the array nums.size() times yields the same array and is wasted work.
void fancyShiftArrayN(vector<int>& nums, int count) {
    int shiftLen = count % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + shiftLen);
    reverse(nums.begin() + shiftLen, nums.end());
}


int main(int argc, char **argv) {

    vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9};

    printArray(data);
    shiftArrayOnce(data);
    printArray(data);
    
    vector<int> data2{1, 2, 3, 4, 5, 6, 7};
    printArray(data2);
    shiftArrayN(data2, 3);
    printArray(data2);

    vector<int> data3{1, 2, 3, 4, 5, 6, 7};
    printArray(data3);
    fancyShiftArrayN(data3, 3);
    printArray(data3);

    return 0;
}
