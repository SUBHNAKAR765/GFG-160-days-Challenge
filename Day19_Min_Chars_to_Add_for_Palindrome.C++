# QUESTION: Min Chars to Add for Palindrome

# Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.
# Note: A palindrome string is a sequence of characters that reads the same forward and backward.

# Examples:
# Input: s = "abc"
# Output: 2
# Explanation: Add 'b' and 'c' at front of above string to make it palindrome : "cbabc"

# Input: s = "aacecaaaa"
# Output: 2
# Explanation: Add 2 a's at front of above string to make it palindrome : "aaaacecaaaa"

# Constraints:
# 1 <= s.size() <= 106

# Approach :

class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string aux_string = s + "#" + rev_s;
        
        int n = aux_string.size(); // auxiliary string
        vector<int> longest_prefix(n,0);
        int j=0;
        
        for(int i=1; i<n; i++){
            while(j > 0 && aux_string[i] != aux_string[j]){
                j=longest_prefix[j-1];
            }
            if(aux_string[i] == aux_string[j]){
                j++;
            }
            longest_prefix[i] =j;
        }
        return s.size() - longest_prefix[n-1];
    }
};
