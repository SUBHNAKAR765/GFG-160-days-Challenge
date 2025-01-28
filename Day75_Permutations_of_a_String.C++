// PROBLEM : Permutations of a String

// Given a string s, which may contain duplicate characters, your task is to generate and return an array of all unique permutations of the string.
// You can return your answer in any order.

// Examples:

// Input: s = "ABC"
// Output: ["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"]
// Explanation: Given string ABC has 6 unique permutations.

// Input: s = "ABSG"
// Output: ["ABGS", "ABSG", "AGBS", "AGSB", "ASBG", "ASGB", "BAGS", "BASG", "BGAS", "BGSA", "BSAG", "BSGA", "GABS", "GASB", "GBAS", "GBSA", "GSAB", "GSBA", "SABG", "SAGB", "SBAG", "SBGA", "SGAB", "SGBA"]
// Explanation: Given string ABSG has 24 unique permutations.

// Input: s = "AAA"
// Output: ["AAA"]
// Explanation: No other unique permutations can be formed as all the characters are same.

// Constraints:
// 1 <= s.size() <= 9
// s contains only Uppercase english alphabets

// SOLUTION :

class Solution {
  public:
    void backtrack(string &s, vector<string> &result, string &current, vector<bool> &used){
        if(current.size() == s.size()){
            result.push_back(current);
            return;
        }
        for(int i=0; i<s.size(); i++){
            if(used[i] || (i>0 && s[i]== s[i-1] && !used[i-1]))
                continue;
            used[i] = true;
            current.push_back(s[i]);
            backtrack(s, result, current, used);
            current.pop_back();
            used[i] = false;
        }
    }
    
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string> result;
        string current = "";
        vector<bool> used(s.size(), false);
        sort(s.begin(), s.end());
        backtrack(s, result, current, used);
        return result;
    }
};
