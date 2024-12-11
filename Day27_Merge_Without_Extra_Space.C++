# QUESTION: Merge Without Extra Space

# Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in sorted order without using any extra space. Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements.

# Examples:
# Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
# Output:
# 2 2 3 4
# 7 10
# Explanation: After merging the two non-decreasing arrays, we get, 2 2 3 4 7 10

# Input: a[] = [1, 5, 9, 10, 15, 20], b[] = [2, 3, 8, 13]
# Output:
# 1 2 3 5 8 9
# 10 13 15 20
# Explanation: After merging two sorted arrays we get 5 10 12 18 20.

# Input: a[] = [0, 1], b[] = [2, 3]
# Output:
# 0 1
# 2 3
# Explanation: After merging two sorted arrays we get 0 1 2 3.

# Constraints:
# 1 <= a.size(), b.size() <= 105
# 0 <= a[i], b[i] <= 107

# SOULTION : 

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size();
        int m = b.size();
        int gap = (n + m + 1) / 2; // The Initial gap size

        while (gap > 0) {
            int i = 0, j = gap;
            while (j < n) {   // To Compare elements within `a`
                if (a[i] > a[j]) {
                    swap(a[i], a[j]);
                }
                i++;
                j++;
            }
            // To Compare elements between `a` and `b`
            j = j - n; // Adjust index `j` for array `b`
            while (i < n && j < m) {
                if (a[i] > b[j]) {
                    swap(a[i], b[j]);
                }
                i++;
                j++;
            }
            // To Compare elements within `b`
            i = 0; // Reset `i` for `b`
            while (j < m) {
                if (b[i] > b[j]) {
                    swap(b[i], b[j]);
                }
                i++;
                j++;
            }
            if (gap == 1) break; // To Reduce the gap for the next iteration
            gap = (gap + 1) / 2;
        }
    }
};
