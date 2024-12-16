# QUESTION: Aggressive Cows

# You are given an array with unique elements of stalls[], which denote the position of a stall. 
# You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

# Examples :

# Input: stalls[] = [1, 2, 4, 8, 9], k = 3
# Output: 3
# Explanation: The first cow can be placed at stalls[0], 
# the second cow can be placed at stalls[2] and 
# the third cow can be placed at stalls[3]. 
# The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.

# Input: stalls[] = [10, 1, 2, 7, 5], k = 3
# Output: 4
# Explanation: The first cow can be placed at stalls[0],
# the second cow can be placed at stalls[1] and
# the third cow can be placed at stalls[4].
# The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.

# Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
# Output: 1
# Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
# The minimum distance between cows, in this case, is 1, which also is the largest among all possible ways.

# Constraints:
# 2 <= stalls.size() <= 106
# 0 <= stalls[i] <= 108
# 1 <= k <= stalls.size()

# SOLUTION: 

class Solution {
  public:
    bool isPossible(vector<int> &stalls,int k,int mid){
        int cowCount =1;
        int lastPos = stalls[0];
        
        for(int i=0; i<stalls.size(); i++){
            if(stalls[i] - lastPos >= mid){
                cowCount++;
                if(cowCount == k){
                    return true;
                }
                lastPos = stalls[i];
            }
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int s =0; 
        int maxi =-1;
        for(int i=0; i<stalls.size(); i++){
            maxi=max(maxi,stalls[i]);
        }
        int e = maxi;
        int ans = -1;
        int mid = s + (e-s)/2;
        
        while(s<=e){
            if(isPossible(stalls,k,mid)){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};
