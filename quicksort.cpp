
#include <vector>

using namespace std;

void quickSort(vector<int>& nums, int left, int right) {
    int i = left;
    int j = right;
    int tmp;
    int pivot = nums[(left + right) / 2];

    // partition step
    while (i <= j) {
        while (nums[i] < pivot) {
            i++;
        }
        while (nums[j] > pivot) {
            j--;
        }
        if (j <= i) {
            tmp = nums[j];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;
            j--;
        }
    }

    // recursive step
    if (left < j) {
        quickSort(nums, left, j);
    }
    if (i < right) {
        quickSort(nums, i, right);
    }
}
