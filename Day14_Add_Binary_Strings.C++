# QUESTION: Add Binary Strings

# Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
#Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

#Input: s1 = "1101", s2 = "111"
#Output: 10100
#Explanation:
#  1101
# + 111
# 10100

# Input: s1 = "00100", s2 = "010"
# Output: 110
# Explanation: 
#   100
# +  10
#  110

# Constraints:
# 1 ≤s1.size(), s2.size()≤ 106

# SOLUTION :- 

# Approach 

class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        // Remove leading zeros
        s1.erase(0, min(s1.find_first_not_of('0'), s1.size() - 1));
        s2.erase(0, min(s2.find_first_not_of('0'), s2.size() - 1));
        
        int n1 = s1.size();
        int n2 = s2.size();
        
        // Make strings equal length by padding with zeros
        if (n1 < n2) {
            s1 = string(n2 - n1, '0') + s1;
        } else if (n2 < n1) {
            s2 = string(n1 - n2, '0') + s2;
        }
        
        int carry = 0;
        string result = "";
        
        // Perform binary addition from right to left
        for (int i = s1.size() - 1; i >= 0; i--) {
            int bit1 = s1[i] - '0'; // Convert char to int
            int bit2 = s2[i] - '0'; // Convert char to int
            int sum = bit1 + bit2 + carry;
            result += (sum % 2) + '0'; // Append result bit (0 or 1)
            carry = sum / 2;          // Update carry
        }
        
        // If there's a carry left, add it to the result
        if (carry) {
            result += '1';
        }
        
        // Reverse the result to get the correct order
        reverse(result.begin(), result.end());
        
        return result;
    }
};
