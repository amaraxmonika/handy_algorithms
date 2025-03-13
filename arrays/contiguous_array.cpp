#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>

using namespace std;

// Example of how to use a prefix-array (kind of)
// The key here is to keep a running count of the values seen in the array
// input[i] == 0 -> Decrement count by 1
// input[i] == 1 -> Increment count by 1
// If there exists 2 places in the array where the count is the same:
// counts[a] == counts[b], then the sub-array of range input[a:b] contains
// a balanced count of 0's and 1's
// Insight:
// We only keep track of max and not all indices for all counts b/c
// If sub array  (A, B) has same range and 
// the sub array (B, C) have the same count
// then the array(A, C) has the same count
// (Why is this true)
int find_max_length(vector<int>& input) {
    unordered_map<int, int> m;
    m[0] = -1;
    int max_length = 0;
    int count = 0;

    for (int i = 0; i < input.size(); i++) {
        count += input[i] == 1 ? 1 : -1;
        if (m.find(count) != m.end()) {
            max_length = max(max_length, i - m[count]);
        } else {
            m[count] = i;
        }
    }

    return max_length;
}

int main() {
    vector<int> test_a{0, 1, 1, 1, 1, 1, 0, 0, 0};

    auto result = find_max_length(test_a);

    /*cout << "result: " << result << endl;*/
    assert(result == 6);

    return 0;
}
