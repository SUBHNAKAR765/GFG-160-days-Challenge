# QUESTION: Max Circular Subarray Sum

#Given an array of integers arr[] in a circular fashion. Find the maximum subarray sum that we can get if we assume the array to be circular.

#Examples:

#Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
#Output: 22
#Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.

#Input: arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
#Output: 23
#Explanation: Maximum sum of the circular subarray is 23. The subarray is [7, 6, 5, -4, -1, 10].

#Input: arr[] = [-1, 40, -14, 7, 6, 5, -4, -1] 
#Output: 52
#Explanation: Circular Subarray [7, 6, 5, -4, -1, -1, 40] has the maximum sum, which is 52.

#Constraints:
#1 <= arr.size() <= 105
#-104 <= arr[i] <= 104

# SOLUTION :

# Approach 1 : Using Kadane'algorithm.

class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();
        
        // Step 1: Find the maximum subarray sum (Kadane's algorithm)
        int maxNormalSum = kadane(arr);
        
        // If all elements are negative, return the maximum element
        if (maxNormalSum < 0) return maxNormalSum;
        
        // Step 2: Find the total sum of the array
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        // Step 3: Find the minimum subarray sum
        for (int i = 0; i < n; i++) {
            arr[i] = -arr[i];  // Invert the array elements
        }
        int minSubarraySum = kadane(arr);
        for (int i = 0; i < n; i++) {
            arr[i] = -arr[i];  // Restore the original array
        }
        
        // Maximum circular sum
        int maxCircularSum = totalSum + minSubarraySum;
        
        // Step 4: Return the maximum of the two cases
        return max(maxNormalSum, maxCircularSum);
    }

private:
    int kadane(vector<int>& arr) {
        int maxEndingHere = 0, maxSoFar = INT_MIN;
        for (int num : arr) {
            maxEndingHere = max(num, maxEndingHere + num);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }
};


