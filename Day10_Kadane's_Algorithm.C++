# Question :

# Kadane's Algorithm
#Given an integer array arr[]. You need to find the maximum sum of a subarray.

#Examples:
#Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
#Output: 11
#Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.

#Input: arr[] = [-2, -4]
#Output: -2
#Explanation: The subarray {-2} has the largest sum -2.

#Input: arr[] = [5, 4, 1, 7, 8]
#Output: 25
#Explanation: The subarray {5, 4, 1, 7, 8} has the largest sum 25.

#Constraints:
#1 ≤ arr.size() ≤ 105
#-109 ≤ arr[i] ≤ 104


#Solution : 

class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        int max_result = INT_MIN; // for initalizing the smallest array element
        int max_ending_sum = 0;  // starting subarray
        
        //Kaden's algorithm
        for(int i=0 ;i< arr.size(); i++){
            max_ending_sum +=arr[i];  // to add the current array element
            max_result = max(max_result, max_ending_sum); // To update max_sum
            
            if(max_ending_sum < 0){ // to reset max_sum if it becomes negative
                max_ending_sum = 0;
            }
        }
        
        return max_result;
    }
};
