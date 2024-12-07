# PROBLEM : Overlapping Intervals

#Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.

# Examples:
# Input: arr[][] = [[1,3],[2,4],[6,8],[9,10]]
# Output: [[1,4], [6,8], [9,10]]
# Explanation: In the given intervals we have only two overlapping intervals here, [1,3] and [2,4] which on merging will become [1,4]. Therefore we will return [[1,4], [6,8], [9,10]].

# Input: arr[][] = [[6,8],[1,9],[2,4],[4,7]]
# Output: [[1,9]]
# Explanation: In the given intervals all the intervals overlap with the interval [1,9]. Therefore we will return [1,9].

# Constraints:
# 1 ≤ arr.size() ≤ 105
# 0 ≤ starti ≤ endi ≤ 105


# SOLUTION :

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(), arr.end());  // Sort the intervals based on the start time
        
        vector<vector<int>> merged;
        
        for (auto& interval : arr) {
            if (merged.empty() || merged.back()[1] < interval[0]) { // If merged is empty or no overlap with the last interval
                merged.push_back(interval);
            } else {
                merged.back()[1] = max(merged.back()[1], interval[1]); // Overlapping intervals; merge by updating the end time
            }
        }
        return merged;
    }
};


