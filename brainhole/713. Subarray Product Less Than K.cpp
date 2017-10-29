#include<iostream>
#include<vector>

/*
问题：为什么都是n*n ，会TLE呢

Hint : For each j, let opt(j) be the smallest i so that nums[i] * nums[i+1] * ... * nums[j] is less than k. opt is an increasing function.


713. Subarray Product Less Than K
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
Your are given an array of positive integers nums.

Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

Example 1:
Input: nums = [10, 5, 2, 6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Note:

0 < nums.length <= 50000.
0 < nums[i] < 1000.
0 <= k < 10^6.
*/
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0, product = 1, left = 0;
        if( k <= 1 )
            return 0;
        for( int i = 0; i < n; i++ ){
            product *= nums[i];
            while( product >= k ){
                product /= nums[left];
                left++;
            }
            cnt += (i-left+1);
        }
        return cnt;
    }

    int my_numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        vector<vector<int>> dp(n, vector<int>(n, 1));
        for( int i = 0; i < n; i++ ){
            dp[i][i] = nums[i];
            if( dp[i][i] < k )
                cnt++;
            for( int j = i+1; j < n; j++ ){
                dp[i][j] = dp[i][j-1] * nums[j];
                if( dp[i][j] < k ){
                    cnt++;
                    //cout << i << " " << j << " " << dp[i][j] << endl;
                }
                else
                    break;
            }
        }
        return cnt;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 1, 1};
    //21904
    cout << s.numSubarrayProductLessThanK(nums, 1);
    return 0;
}
