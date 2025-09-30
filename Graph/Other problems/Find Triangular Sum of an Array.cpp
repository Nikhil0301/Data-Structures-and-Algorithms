//Brute force approach
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // TC -> O(N*N) SC->O(N)
    int triangularSum(vector<int>& nums) {
        
        vector<int> newNums(nums);
        int n = newNums.size();
        if(n == 1) return nums[0];
        int i = 0, idx = 1;
        while(n - idx > 0){
            for(int i = 0; i < n - idx; i++){
                newNums[i] = (newNums[i] + newNums[i + 1]) % 10;
            }
            idx++;
        }
        return newNums[0];
    }
};

//optimal approach
class Solution2 {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        long long result = 0;
        long long coef = 1; // Start with C(n-1, 0) = 1
        for (int i = 0; i < n; ++i) {
            result = (result + coef * nums[i]) % 10; // Add contribution
            // Update coef to C(n-1, i+1)
            coef = coef * (n - 1 - i) / (i + 1);
            coef %= 10;
        }
        return result;
    }
};

/*
Optimal Approach to Find Triangular Sum of an Array

Problem Description

Given a 0-indexed integer array nums where each element is a digit between 0 and 9, compute the triangular sum by iteratively:





If the array has one element, return it.



Create a new array of size n-1 where each element is the sum of adjacent elements modulo 10.



Replace the original array with the new array and repeat until one element remains.



Return the final element.

Constraints:





( 1 \leq nums.length \leq 1000 )



( 0 \leq nums[i] \leq 9 )

Optimal Approach

The optimal solution computes the triangular sum in ( O(n) ) time by recognizing that the final result is a weighted sum of the input array elements, where the weights are binomial coefficients ( \binom{n-1}{i} \mod 10 ). This avoids the ( O(n^2) ) brute-force method of simulating each iteration.

Key Insight





The final element is: [ \sum_{i=0}^{n-1} \binom{n-1}{i} \cdot nums[i] \mod 10 ]



( \binom{n-1}{i} ) represents the contribution of ( nums[i] ) to the final result, derived from the number of paths through the iterative summing process.



Since we need the result modulo 10, we compute binomial coefficients modulo 10 iteratively to avoid overflow.

Algorithm Steps





Base Case: If ( n = 1 ), return ( nums[0] ).



Initialize:





Set result = 0 to accumulate the sum.



Set coef = 1 for ( \binom{n-1}{0} ).



Loop:





For each index ( i ) from 0 to ( n-1 ):





Add ( coef \cdot nums[i] \mod 10 ) to result.



Update coef to ( \binom{n-1}{i+1} ) using: [ coef = coef \cdot \frac{n-1-i}{i+1} \mod 10 ]



Return: result % 10.

Example

For ( nums = [1, 2, 3, 4, 5] ) (( n = 5 )):





Binomial coefficients for ( n-1 = 4 ): ( [1, 4, 6, 4, 1] ).



Compute: [ (1 \cdot 1 + 4 \cdot 2 + 6 \cdot 3 + 4 \cdot 4 + 1 \cdot 5) \mod 10 = (1 + 8 + 18 + 16 + 5) \mod 10 = 48 \mod 10 = 8 ]



Output: 8.

Time and Space Complexity

Time Complexity: ( O(n) ), as we process each element once with constant-time operations.
Space Complexity: ( O(1) ), using only a few variables.
*/