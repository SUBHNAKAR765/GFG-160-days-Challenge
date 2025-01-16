// PROBLEM : Largest subarray of 0's and 1's

// Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s.

// Examples:

// Input: arr[] = [1, 0, 1, 1, 1, 0, 0]
// Output: 6
// Explanation: arr[1...6] is the longest subarray with three 0s and three 1s.

// Input: arr[] = [0, 0, 1, 1, 0]
// Output: 4
// Explnation: arr[0...3] or arr[1...4] is the longest subarray with two 0s and two 1s.

// Input: arr[] = [0]
// Output: 0
// Explnation: There is no subarray with an equal number of 0s and 1s.

// Constraints:
// 1 <= arr.size() <= 105
// 0 <= arr[i] <= 1

// SOLUTION :

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        unordered_map<int, int> prefixsumindex;
        int sum = 0, maxlength = 0;
        
        for(int i=0; i<arr.size(); i++){
            sum += (arr[i] == 0 ? -1 : 1);
            if(sum == 0){
                maxlength = i+1;
            }
            if(prefixsumindex.find(sum) != prefixsumindex.end()){
                maxlength = max(maxlength, i - prefixsumindex[sum]);
            }
            else{
                prefixsumindex[sum] = i;
            }
        }
        return maxlength;
    }
};



