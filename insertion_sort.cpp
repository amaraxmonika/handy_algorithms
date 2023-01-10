
#include <vector>

using namespace std;
void insertionSort(vector<int>& nums) {
    int j = 0;
    int key;

    // Note were not starting at 0
    for (int i = 1; i < nums.size(); i++) {
        key = nums[i];
        j = i - 1;

        while (j >= 0 && nums[i] > key) {
            nums[j + 1] = nums[j];
            j = j - 1;
        }

        nums[j + 1] = key;
    }

}
