# QUESTION: Count Inversions

# Given an array of integers arr[]. Find the Inversion Count in the array.
# Two elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

# Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
# If an array is sorted in the reverse order then the inversion count is the maximum. 

# Examples:
# Input: arr[] = [2, 4, 1, 3, 5]
# Output: 3
# Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

# Input: arr[] = [2, 3, 4, 5, 6]
# Output: 0
# Explanation: As the sequence is already sorted so there is no inversion count.

# Input: arr[] = [10, 10, 10]
# Output: 0
# Explanation: As all the elements of array are same, so there is no inversion count.

# Constraints:
# 1 ≤ arr.size() ≤ 105
# 1 ≤ arr[i] ≤ 104


# SOLUTION: 

class Solution {
  public:
     int sorts(vector<int> &arr, int left, int mid, int right) {
        int i = left, j = mid, k = 0;
        vector<int> temp(right - left + 1);
        int invCount = 0;

        while (i < mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                // All remaining elements in left half are greater than arr[j]
                invCount += (mid - i);
            }
        }

        // Copy remaining elements of left half
        while (i < mid) {
            temp[k++] = arr[i++];
        }

        // Copy remaining elements of right half
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        // Copy sorted subarray back to original array
        for (i = left, k = 0; i <= right; i++, k++) {
            arr[i] = temp[k];
        }

        return invCount;
    }
    int inv(vector<int>&arr,int low,int high)
    {
        int cnt=0;
        if(low<high)
        {
            int mid= low+ (high-low)/2;
            cnt+=inv(arr,low,mid);
            cnt+=inv(arr,mid+1,high);
            cnt+=sorts(arr,low,mid+1,high);
        }
        return cnt;
    }
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        return inv(arr,0,arr.size()-1);
    }
};
