# QUESTION: Number of occurrence

# Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 

# Examples :

# Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
# Output: 4
# Explanation: target = 2 occurs 4 times in the given array so the output is 4.

# Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
# Output: 0
# Explanation: target = 4 is not present in the given array so the output is 0.

# Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
# Output: 3
# Explanation: target = 12 occurs 3 times in the given array so the output is 3.

# Constraints:
# 1 ≤ arr.size() ≤ 106
# 1 ≤ arr[i] ≤ 106
# 1 ≤ target ≤ 106


# SOLUTION: 

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        auto lower = lower_bound(arr.begin(), arr.end(), target);  // Use lower_bound to find the first occurrence of target
        auto upper = upper_bound(arr.begin(), arr.end(), target);  // Use upper_bound to find the position after the last occurrence of target

        if (lower == arr.end() || *lower != target) {  // If the target is not found, return 0
            return 0;
        }
        return upper - lower; // To Calculate the count as the difference between upper and lower bounds
    }
};
