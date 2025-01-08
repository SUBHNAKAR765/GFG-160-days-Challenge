// PROBLEM: Count the number of possible triangles

// Given an integer array arr[]. Find the number of triangles that can be formed with three different array elements as lengths of three sides of the triangle. 

// A triangle with three given sides is only possible if sum of any two sides is always greater than the third side.

// Examples:

// Input: arr[] = [4, 6, 3, 7]
// Output: 3
// Explanation: There are three triangles possible [3, 4, 6], [4, 6, 7] and [3, 6, 7]. Note that [3, 4, 7] is not a possible triangle.  

// Input: arr[] = [10, 21, 22, 100, 101, 200, 300]
// Output: 6
// Explanation: There can be 6 possible triangles: [10, 21, 22], [21, 100, 101], [22, 100, 101], [10, 100, 101], [100, 101, 200] and [101, 200, 300]

// Input: arr[] = [1, 2, 3]
//Output: 0
  // Explanation: No triangles are possible.

// Constraints:
// 3 <= arr.size() <= 103
// 0 <= arr[i] <= 105

// SOLUTION: 

class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n<3) return 0;
        
        sort(arr.begin(), arr.end());
        int count = 0;
        
        for(int i=n-1; i>=2; i--){
            int left =0, right = i-1;
            while(left<right){
                if(arr[left] + arr[right] > arr[i]){
                    count +=(right -left);
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return count;
    }
};
