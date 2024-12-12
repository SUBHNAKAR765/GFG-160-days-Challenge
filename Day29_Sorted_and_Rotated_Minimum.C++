# QUESTION: Sorted and Rotated Minimum

# A sorted array arr[] (may contain duplicates) is rotated at some unknown point, the task is to find the minimum element in it. 

# Examples:

# Input: arr[] = [5, 6, 1, 2, 3, 4]
# Output: 1
# Explanation: 1 is the minimum element in the array.
  
# Input: arr[] = [3, 2, 2, 2]
# Output: 2
# Explanation: Here 2 is the minimum element.
  
# Input: arr[] = [4, 4, 4]
# Output: 4
# Explanation: Here 4 is the only minimum element.
  
# Constraints:
# 1 ≤ arr.size() ≤ 106
# 1 ≤ arr[i] ≤ 109


# SOLUTION: 

class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int left =0, right=arr.size()-1;
        while(left < right){
            int mid = left + (right - left) /2 ;
            
            //if mid element is greater than the rightmost, minimum is in the right half
            if(arr[mid] > arr[right]){
                left = mid +1;
            }
            //if mid element is smaller than the rightmost, minimum is in the left half or at mid
            else if(arr[mid] < arr[right]){
                right = mid;
            }
            // Decrement right to skip duplicates
            else{
                right--;
            }
        }
        return arr[left];
    }
};
