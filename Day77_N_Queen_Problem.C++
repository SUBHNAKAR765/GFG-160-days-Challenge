//  PROBLEM: N-Queen Problem

// The n-queens puzzle is the problem of placing n queens on a (n × n) chessboard such that no two queens can attack each other. 
// Note that two queens attack each other if they are placed on the same row, the same column, or the same diagonal.

// Given an integer n, find all distinct solutions to the n-queens puzzle.
// You can return your answer in any order but each solution should represent a distinct board configuration of the queen placements, where the solutions are represented as permutations of [1, 2, 3, ..., n]. 
// In this representation, the number in the ith position denotes the row in which the queen is placed in the ith column.
// For eg. below figure represents a chessboard [3 1 4 2].


// Examples:

// Input: n = 1
// Output: [1]
// Explaination: Only one queen can be placed in the single cell available.

// Input: n = 4
// Output: [[2 4 1 3 ] [3 1 4 2 ]]
// Explaination: There are 2 possible solutions for n = 4.

// Input: n = 2
// Output: []
// Explaination: There are no possible solutions for n = 2.

// Constraints:
// 1 ≤ n ≤ 10

//SOLUTION: 

class Solution {
  public:
    vector<vector<int>> results;
    
    void solve(int col, int n, vector<int>& board, vector<bool>& column, vector<bool>& diag1, vector<bool>& diag2){
        if(col == n){
            results.push_back(board);
            return;
        }
        
        for(int row =0; row<n; row++){
            if(!column[row] && !diag1[row + col] && !diag2[row-col+n-1]){
                board[col] = row + 1;
                column[row] = diag1[row + col] = diag2[row - col + n-1] = true;
                
                solve(col + 1, n, board, column, diag1, diag2);
                
                column[row] = diag1[row + col] = diag2[row - col + n - 1] = false;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        results.clear();
        vector<int> board(n);
        vector<bool> column(n, false), diag1(2*n-1, false), diag2(2*n-1, false);
        
        solve(0, n, board, column, diag1, diag2);
        return results;
        
    }
};
