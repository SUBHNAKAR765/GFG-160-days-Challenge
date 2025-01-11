// PROBLEM: Longest substring with distinct characters

// Given a string s, find the length of the longest substring with all distinct characters. 

// Examples:
// Input: s = "geeksforgeeks"
// Output: 7
// Explanation: "eksforg" is the longest substring with all distinct characters.

// Input: s = "aaa"
// Output: 1
// Explanation: "a" is the longest substring with all distinct characters.

// Input: s = "abcdefabcbb"
// Output: 6
// Explanation: The longest substring with all distinct characters is "abcdef", which has a length of 6.

// Constraints:
// 1<= s.size()<=3*104
// All the characters are in lowercase.

// SOLUTION:

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        unordered_map<char, int> lastseen;
        int ml =0; // to store the maxlength of the substring 
        int start = 0;  // start index of the sliding window 
        
        for(int end =0; end<s.size(); ++end){
            char currentchar = s[end];
            if(lastseen.find(currentchar) != lastseen.end() && lastseen[currentchar] >= start){
                start = lastseen[currentchar] + 1;
            }
            // update the last seen index of the current character
            lastseen[currentchar] = end;
            // update the maximum length
            ml = max(ml, end - start + 1);
        }
        return ml;
    }
};
