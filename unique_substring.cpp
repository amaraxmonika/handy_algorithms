

#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int longestSubstring(string& s) {

    // Using a set here to track all the characters we have seen in the substring
    unordered_set<char> uniqueSubstring;

    int left = 0;
    int right = 0;
    int maxDistance = 0;

    while (right < s.size()) {
        // If the current character has not been seen, then we add it to the set
        // which in turn increases the size of our current substring.
        if (uniqueSubstring.count(s[right]) <= 0) {
            uniqueSubstring.insert(s[right]);
            right++;
        } else {
            // Otherwise, remove the oldest character from the set. This doesn't
            // guarantee that we can still insert the current character pointed
            // by right so we will try that again.
            uniqueSubstring.erase(s[left]);
            left++;
        }
        if (uniqueSubstring.size() > maxDistance) {
            maxDistance = uniqueSubstring.size();
        }
    }

    return maxDistance;

}

int main() {
    string test("aaaaaaaaaatest_hiaaaaaaa");
    int result = longestSubstring(test);
    printf("result was: %d\n", result);
    assert(result == 7);
    return 0;
}
