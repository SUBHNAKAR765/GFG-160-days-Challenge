# Questions: Maximum Product subarray 

#Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr.
#Note: It is guaranteed that the output fits in a 32-bit integer.

#Examples
#Input: arr[] = [-2, 6, -3, -10, 0, 2]
#Output: 180
#Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180.

#Input: arr[] = [-1, -3, -10, 0, 60]
#Output: 60
#Explanation: The subarray with maximum product is {60}.

#Input: arr[] = [2, 3, 4] 
#Output: 24 
#Explanation: For an array with all positive elements, the result is product of all elements. 

#Constraints:
#1 ≤ arr.size() ≤ 106
#-10  ≤  arr[i]  ≤  10



#Solution approach 1: 

class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int n = arr.size();
        if(n==0) return 0;
        
        int leftproduct = 1; 
        int rightproduct =1;
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++){
            leftproduct = (leftproduct == 0) ? 1: leftproduct;
            rightproduct = (rightproduct== 0) ? 1: rightproduct; 
            
            leftproduct *= arr[i];
            rightproduct *= arr[n-1-i];
            
            ans = max(ans, max(leftproduct, rightproduct));
        }
        
        return ans;
    }
    
};



#Solution approach 2: 

class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
       int n = arr.size();
        if (n == 0) return 0;

        // Initialize max product, min product, and result
        int maxProd = arr[0];
        int minProd = arr[0];
        int ans = arr[0];

        for (int i = 1; i < n; i++) {
            // If the current element is negative, swap maxProd and minProd
            if (arr[i] < 0) {
                swap(maxProd, minProd);
            }

            // Update maxProd and minProd for the current element
            maxProd = max(arr[i], maxProd * arr[i]);
            minProd = min(arr[i], minProd * arr[i]);

            // Update the result
            ans = max(ans, maxProd);
        }

        return ans;
    
    }
};
