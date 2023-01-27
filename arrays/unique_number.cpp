
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

// This function assumes that there is a single element in the
// list the is unique. This isn't a very practical algorithm,
// but I really liked this solution because it isn't obvious.
// The reason it works is because if an element occurs more than
// once we have the following a ^ b ^ a == (a ^ a) ^ b = 0 ^ b = b
int findUniqueElement(const vector<int>& nums) {
    int result = 0;
    for (auto i : nums) {
        result ^= i;
    }
    return result;
}

int main(int argc, char **argv) {

    vector<int> data{1, 1, 2, 2, 3, 3, 4, 5, 5};
    printArray(data);
    cout << "result: " << findUniqueElement(data) << endl;
    return 0;
}
