
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool vectorsEqual(vector<int> v1, vector<int> v2) {
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }

    return true;
}
// returns true if any permutation of s1 occurs in s2. 
// This uses a sliding window to check the frequency of letters
// in a substring.
bool checkSubstringPermutation(string s1, string s2) {
    vector<int> s1Map(26);
    vector<int> s2Map(26);

    // check error case
    if (s1.size() > s2.size()) {
        return false;
    }

    // populate starting window and s1 map
    for (int i = 0; i < s1.size(); i++) {
        s1Map[s1[i] - 'a']++;
        s2Map[s2[i] - 'a']++;
    }

    for (int i = 0; i < s2.size() - s1.size(); i++) {
        if (vectorsEqual(s1Map, s2Map)) {
            return true;
        }
        // shift window by adding rightmost letter and removing leftmost
        s2Map[s2[i + s1.size()] - 'a']++;
        s2Map[s2[i] - 'a']--;
    }

    return vectorsEqual(s1Map, s2Map);

}

bool checkSubstringPermutationOptimized(string s1, string s2) {
    vector<int> s1Map(26);
    vector<int> s2Map(26);

    // check error case
    if (s1.size() > s2.size()) {
        return false;
    }

    // populate starting window and s1 map
    for (int i = 0; i < s1.size(); i++) {
        s1Map[s1[i] - 'a']++;
        s2Map[s2[i] - 'a']++;
    }

    int count = 0;
    // build count so we can track the 'state' of matching
    for (int i = 0; i < s1Map.size(); i++) {
        if (s1Map[i] == s2Map[i]) {
            count++;
        }
    }

    for (int i = 0; i < s2.size() - s1.size(); i++) {
        int left = s2[i] - 'a';
        int right = s2[i + s1.size()] - 'a';
        
        if (count == 26) {
            return true;
        }

        // add right side of window to frequency map
        s2Map[right]++;

        if (s2Map[right] == s1Map[right]) {
            count++;
        } else if (s2Map[right] == s1Map[right] + 1) {
            count--;
        }
        // remove left side of windwo from frequency map
        s2Map[left]--;

        if (s2Map[left] == s1Map[left]) {
            count++;
        } else if (s2Map[left] == s1Map[left] - 1) {
            count--;
        }
    }

    return count == 26;
}
int main() {
    string s1("ab");
    string s2("llllllllballllll");
    string shouldFail("booooo");

    assert(checkSubstringPermutation(s1, s2) == true);
    assert(checkSubstringPermutation(s1, s2) == true);

    assert(checkSubstringPermutationOptimized(s1, shouldFail) == false);
    assert(checkSubstringPermutationOptimized(s1, shouldFail) == false);
    return 0;
}
