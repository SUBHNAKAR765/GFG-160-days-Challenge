// QUESTION: FIND ALL TRIPLETS WITH ZERO SUM

// Given an array arr[], find all possible triplets i, j, k in the arr[] whose sum of elements is equals to zero. 
// Returned triplet should also be internally sorted i.e. i<j<k.

// Examples:
// Input: arr[] = [0, -1, 2, -3, 1]i
// Output: [[0, 1, 4], [2, 3, 4]]
// Explanation: Triplets with sum 0 are:
// arr[0] + arr[1] + arr[4] = 0 + (-1) + 1 = 0
// arr[2] + arr[3] + arr[4] = 2 + (-3) + 1 = 0

// Input: arr[] = [1, -2, 1, 0, 5]
// Output: [[0, 1, 2]]
// Explanation: Only triplet which satisfies the condition is arr[0] + arr[1] + arr[2] = 1 + (-2) + 1 = 0

// Input: arr[] = [2, 3, 1, 0, 5]
// Output: [[]]
// Explanation: There is no triplet with sum 0.

// Constraints:
// 3 <= arr.size() <= 103
// -104 <= arr[i] <= 104


// SOLUTION: 

class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
       vector<vector<int>> res;
        
        // Iterate through the array
        for(int i = 0; i < arr.size(); i++) {
            unordered_map<int, unordered_set<int>> mp;
            
            // Map elements from i+1 to the rest of the array
            for(int j = i + 1; j < arr.size(); j++) {
                mp[arr[j]].insert(j);
            }
            
            // Find triplets
            for(int j = i + 1; j < arr.size(); j++) {
                int target = (-arr[i]) - arr[j]; // This is the target sum we need to find in the map
                if(mp.find(target) != mp.end()) {
                    // Iterate through possible k indices in the map
                    for(auto it : mp[target]) {
                        // Ensure the triplet is in valid order i < j < k
                        if(it > i && it > j) {
                            res.push_back({i, j, it});
                        }
                    }
                }
            }
        }

        return res;
    }
};
