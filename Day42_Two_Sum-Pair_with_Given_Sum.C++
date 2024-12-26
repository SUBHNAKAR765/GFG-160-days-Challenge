// QUESTION: Two Sum-Pair with GIven Sum

// Given an array arr[] of positive integers and another integer target. Determine if there exists two distinct indices such that the sum of there elements is equals to target.

// Examples:
// Input: arr[] = [1, 4, 45, 6, 10, 8], target = 16
// Output: true
// Explanation: arr[3] + arr[4] = 6 + 10 = 16.

// Input: arr[] = [1, 2, 4, 3, 6], target = 11
// Output: false
// Explanation: None of the pair makes a sum of 11.

// Constraints:
// 1 ≤ arr.size ≤ 105
// 1 ≤ arr[i] ≤ 105
// 1 ≤ target ≤ 2*105


// SOLUTION: 

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        unordered_set<int> seen; // To store seen elements
        for (int n : arr) {
            int comp = target - n; // Calculate the complement
            if (seen.find(comp) != seen.end()) {
                return true; // If complement is found then return true
            }
            seen.insert(n); // Add the current number to the set of seen 
        }
        return false; // If no pair is found of the array 
    }
};

