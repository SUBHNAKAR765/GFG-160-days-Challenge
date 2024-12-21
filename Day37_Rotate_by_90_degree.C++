// QUESTION: Rotate by 90 degree

// Rotate by 90 degree
// Given a square matrix mat[][] of size n x n. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space. 

// Examples:

// Input: mat[][] = [[1, 2, 3],
//               [4, 5, 6]
//             [7, 8, 9]]
// Output: Rotated Matrix:
// [3, 6, 9]
// [2, 5, 8]
// [1, 4, 7]

// Input: mat[][] = [[1, 2],
               //  [3, 4]]
// Output: Rotated Matrix:
// [2, 4]
// [1, 3]

// Constraints:
// 1 ≤ n ≤ 102
// 0 <= mat[i][j] <= 103


// SOLUTION: 

class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(); // STL
        
        for(int i =0; i<n; ++i){ // to make transpose the matrix
            for(int j = i+1; j<n; ++j){
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        for(int j=0; j<n; ++j){ // resverse the columns
            int top = 0, bottom = n-1;
            while(top<bottom){
                swap(mat[top][j], mat[bottom][j]);
                ++top;
                --bottom;
            }
        }
    }
};


