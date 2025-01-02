// PROBLEM: Count Subarrays with given XOR

// Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.

// Examples: 

// Input: arr[] = [4, 2, 2, 6, 4], k = 6
// Output: 4
// Explanation: The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the answer is 4.

// Input: arr[] = [5, 6, 7, 8, 9], k = 5
// Output: 2
//Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]. Hence, the answer is 2.

// Constraints:
// 1 ≤ arr.size() ≤ 105
// 0 ≤ arr[i] ≤105
// 0 ≤ k ≤ 105


// SOLUTION: 

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> freq;
        int XOR = 0;
        long count =0;
        
        for (int num : arr){
            XOR ^= num; // to update the current XOR
            if(XOR == k){
                count++;
            }
            int target = XOR ^ k;
            if(freq.find(target) != freq.end()){
                count += freq[target];
            }
            freq[XOR]++;
        }
        return count;
    }
};
