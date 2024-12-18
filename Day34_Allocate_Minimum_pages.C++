# QUESTION: Allocate Minimum Pages 

# You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

# Each student receives atleast one book.
# Each student is assigned a contiguous sequence of books.
# No book is assigned to more than one student.
# The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, 
# find the arrangement where the student who receives the most pages still has the smallest possible maximum.

# Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

# Examples:

# Input: arr[] = [12, 34, 67, 90], k = 2
# Output: 113
# Explanation: Allocation can be done in following ways:
# [12] and [34, 67, 90] Maximum Pages = 191
# [12, 34] and [67, 90] Maximum Pages = 157
# [12, 34, 67] and [90] Maximum Pages = 113.
# Therefore, the minimum of these cases is 113, which is selected as the output.
  
# Input: arr[] = [15, 17, 20], k = 5
# Output: -1
# Explanation: Allocation can not be done.
# Input: arr[] = [22, 23, 67], k = 1
# Output: 112
  
# Constraints:
# 1 <=  arr.size() <= 106
# 1 <= arr[i] <= 103
# 1 <= k <= 103 


# SOLUTION 1: With 2 variables 
  
  class Solution {
  public:
  bool isPossible(vector<int> &arr, int n, int k, int maxPages) {
        int studentCount = 1;  // Start with the first student
        int currentPages = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > maxPages) {
                // A single book has more pages than maxPages, not possible
                return false;
            }
            if (currentPages + arr[i] > maxPages) {
                // Allocate to the next student
                studentCount++;
                currentPages = arr[i];
                if (studentCount > k) {
                    return false;  // Exceeds the number of students
                }
            } else {
                currentPages += arr[i];
            }
        }
        return true;
    }
    
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) {
            // Not enough books for each student
            return -1;
        }

        int low = *min_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(arr, n, k, mid)) {
                result = mid;  // Update result
                high = mid - 1;  // Try for a smaller maximum
            } else {
                low = mid + 1;  // Increase the maximum
            }
        }
        return result;
    }
}; 


# SOLUTION 2: Approach No.2 with 3 variables 
  class Solution {
  public:
   bool isPossible(vector<int> &arr, int n, int k, int mid) {
        int studentCount = 1;
        int pagesum = 0;

        for (int i = 0; i < n; i++) {
            if (pagesum + arr[i] <= mid) {
                pagesum += arr[i];
            } else {
                studentCount++;
                if (studentCount > k || arr[i] > mid) {
                    return false;
                }
                pagesum = arr[i];
            }
        }
        return true;
    }

    int findPages(vector<int> &arr, int n, int k) {
        int s = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }

        int e = sum;
        int ans = -1;
        int mid = s + (e - s) / 2;

        while (s <= e) {
            if (isPossible(arr, n, k, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }
};
