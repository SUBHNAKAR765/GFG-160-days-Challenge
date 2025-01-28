// PROBLEM : Implement Pow

// Implement the function power(b, e), which calculates b raised to the power of e (i.e. be).

// Examples:

// Input: b = 3.00000, e = 5
// Output: 243.00000

// Input: b = 0.55000, e = 3
// Output: 0.16638

// Input: b = -0.67000, e = -7
// Output: -16.49971

// Constraints:

// -100.0 < b < 100.0
// -109 <= e <= 109
// Either b is not zero or e > 0.
// -104 <= be <= 104

// SOLUTION :

class Solution {
  public:
    double power(double b, int e) {
        // code here
        // Here e is expoenent 
        if(e == 0) return 1.0; 
        // case: if any number raised to the power of 0 is 1
        
        double half = power(b,e/2);
        // using here recursive call for half exponent
        
        if(e%2 == 0){
            return half*half; // exponent is even
        }else{
            if(e>0){ 
                return b * half * half; // exponent is odd and +ve
            }else{ 
                return (half*half)/b; // exponent is odd and -ve
            }
        }
    }
};
