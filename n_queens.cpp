
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

/*  Diagonals:
 *    0   1   2   3   4   5
 *  ________________________
 * 0| 0 |-1 |-2 |-3 |-4 |-5 |
 * 1| 1 | 0 |-1 |-2 |-3 |-4 |
 * 2| 2 | 1 | 0 |-1 |-2 |-3 |
 * 3| 3 | 2 | 1 | 0 |-1 |-2 |
 * 4| 4 | 3 | 2 | 1 | 0 |-1 |
 * 5| 5 | 4 | 3 | 2 | 1 | 0 |
 *   ------------------------
 *
 *  Anti-Diagonals:
 *    0   1   2   3   4   5
 *  ________________________
 * 0| 0 | 1 | 2 | 3 | 4 | 5 |
 * 1| 1 | 2 | 3 | 4 | 5 | 6 |
 * 2| 2 | 3 | 4 | 5 | 6 | 7 |
 * 3| 3 | 4 | 5 | 6 | 7 | 8 |
 * 4| 4 | 5 | 6 | 7 | 7 | 9 |
 * 5| 5 | 6 | 7 | 8 | 9 |10 |
 *   ------------------------
 *
 *
 *           \|/
 *          --Q--
 *           /|\
 *
 */

// How to shift elements in an array
void printSet(unordered_set<int>& nums) {
    for (auto &i : nums) {
        cout << i << ",";
    }
    cout << endl;
}


/*
 * Given an integer size where size is the number of queens to place and also
 * the width and height of a given chess board, this method will return the
 * number of distinct solutions where queens can be placed without attacking
 * each other. This is known as the N-Queens problem and is an excellent example
 * of a backtracking algorithm.
 */
int backtrack(int row,
                unordered_set<int>& diag,
                unordered_set<int>& anti_diag,
                unordered_set<int>& cols,
                int size) {

    // base case where n queens have been placed
    if (row == size) {
        return 1;
    }

    int solutions = 0;
    for (int col = 0; col < size; col++) {
        int current_diag = row - col;
        int current_anti_diag = row + col;
        if (cols.count(col) || diag.count(current_diag) || anti_diag.count(current_anti_diag)) {
            continue;
        }

        // No other queens can attack the current row & column so we can place
        // the queen, add its index to the diag, anti-diag, and cols sets
        // and trace our way through the rest of the board.
        cols.insert(col);
        diag.insert(current_diag);
        anti_diag.insert(current_anti_diag);

        // Move to the next row with the updated board state
        solutions += backtrack(row + 1, diag, anti_diag, cols, size);

        // Remove the queen from the current row & column. This is done because
        // calling totalNQueens with this index has already explored the rest
        // of the board assuming that a queen was previously placed at this
        // location. The queen is now removed to test for other possibilities
        // without a queen at this location.
        diag.erase(current_diag);
        anti_diag.erase(current_anti_diag);
        cols.erase(col);

    }

    return solutions;
}

int totalNQueens(int size) {
    unordered_set<int> diagonals;
    unordered_set<int> anti_diagonals;
    unordered_set<int> cols;
    return backtrack(0, diagonals, anti_diagonals, cols, size);
}

int main(int argc, char **argv) {
    assert(totalNQueens(1) == 1);
    assert(totalNQueens(3) == 0);
    assert(totalNQueens(4) == 2);
    assert(totalNQueens(5) == 10);
    return 0;
}
