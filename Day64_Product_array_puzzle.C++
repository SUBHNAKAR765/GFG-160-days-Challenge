// PROBLEM: Product array puzzle

// Given an array, arr[] construct a product array, res[] where each element in res[i] is the product of all elements in arr[] except arr[i]. Return this resultant array, res[].
// Note: Each element is res[] lies inside the 32-bit integer range.

// Examples:

// Input: arr[] = [10, 3, 5, 6, 2]
// Output: [180, 600, 360, 300, 900]
// Explanation: For i=0, res[i] = 3 * 5 * 6 * 2 is 180.
// For i = 1, res[i] = 10 * 5 * 6 * 2 is 600.
// For i = 2, res[i] = 10 * 3 * 6 * 2 is 360.
// For i = 3, res[i] = 10 * 3 * 5 * 2 is 300.
// For i = 4, res[i] = 10 * 3 * 5 * 6 is 900.

// Input: arr[] = [12, 0]
// Output: [0, 12]
// Explanation: For i = 0, res[i] is 0.
// For i = 1, res[i] is 12.

// Constraints:
// 2 <= arr.size() <= 105
// -100 <= arr[i] <= 100

// SOLUTION : 

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // code here
        long long product =1;
        int zero = 0;
        vector<int>res(arr.size());
        for(int i=0; i<arr.size();i++){
            if(arr[i]!=0){
                product*=arr[i];
            }
            else{
                zero++;
            }
        }
        for(int i=0; i<arr.size(); i++){
            if(zero>1){
                res[i] = 0;
            }
            else if(zero ==1){
                res[i] = (arr[i]==0)?static_cast<int>(product):0;
            }
            else{
                res[i] = static_cast<int>(product/arr[i]);
            }
        }
        return res;
    }
};
