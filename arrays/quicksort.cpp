
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


int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left + ((right - left) / 2)]; 
    while (left <= right) {
        while (nums[left] < pivot) {
            left++;
        }
        while (nums[right] > pivot) {
            right--;
        }

        if (left <= right) {
            int tmp = nums[right];
            nums[right] = nums[left];
            nums[left] = tmp;
            left++;
            right--;
        }
    }
    return left;
}
void quickSort(vector<int>& nums, int left, int right) {
    int index = partition(nums, left, right);
    if (left < index - 1) {
        // sort left half
        quickSort(nums, left, index - 1);
    }
    if (index < right) {
        // sort right half
        quickSort(nums, index, right);
    }
}

int main() {
    vector<int> nums {9, 8, 7, 6, 5, 4, 3, 1, 2};
    printArray(nums);
    quickSort(nums, 0, nums.size() - 1);
    printArray(nums);
}
