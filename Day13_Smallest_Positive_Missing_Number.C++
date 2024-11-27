# QUESTION: Smallest Positive Missing Number

#You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.
#Note: Positive number starts from 1. The array can have negative integers too.

#Examples:
#Input: arr[] = [2, -3, 4, 1, 1, 7]
#Output: 3
#Explanation: Smallest positive missing number is 3.

#Input: arr[] = [5, 3, 2, 5, 1]
#Output: 4
#Explanation: Smallest positive missing number is 4.

#Input: arr[] = [-8, 0, -1, -4, -3]
#Output: 1
#Explanation: Smallest positive missing number is 1.

#Constraints:  
#1 <= arr.size() <= 105
#-106 <= arr[i] <= 106

#SOLUTION: 

#Approach 1: WIth Time effiecient 

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        int n = arr.size();

        // this first for loop for Segregate positive and negative numbers
        for (int i = 0; i < n; ++i) {
            if (arr[i] <= 0 || arr[i] > n) {
                arr[i] = n + 1;  // to Assign a value out of the valid range
            }
        }

        // second for loop to Mark numbers as present by using indices
        for (int i = 0; i < n; ++i) {
            int val = abs(arr[i]);
            if (val <= n) {
                arr[val - 1] = -abs(arr[val - 1]); // to Mark the index as visited
            }
        }

        // third loop for Finding  the missing positive number
        for (int i = 0; i < n; ++i) {
            if (arr[i] > 0) {
                return i + 1; // Return the 1-based index
            }
        }
        // If all numbers are present, return n+1
        return n + 1;
        
    }
};



#Approach 2: Using Brute froce

class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        
        // Start checking from 1 upwards
        for (int i = 1; i <= n + 1; ++i) { // We check up to n+1
            bool found = false;
            
            // Check if `i` exists in the array
            for (int j = 0; j < n; ++j) {
                if (arr[j] == i) {
                    found = true;
                    break;
                }
            }
            
            // If not found, return the missing number
            if (!found) {
                return i;
            }
        }
        
        return -1; // Should not reach here
    }
};


