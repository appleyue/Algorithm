#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

/**
天平问题：背包问题，状态dp
dp【i】【j】代表前i个物品能不能达到j容量
*/

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for( int i = 0; i < nums.size(); i++ ){
        sum += nums[i];
    }
    if( sum % 2 != 0 )
        return false;
    sum /= 2;
    vector<bool> dp(sum+1, false);
    dp[0] = true;
    for( int i = 0; i < nums.size(); i++ ){
        for( int j = sum; j >= 0; j-- ){
            if( j-nums[i] >= 0 )
                dp[j] = dp[j] | dp[j-nums[i]];
        }
    }
    return dp[sum];
}


bool twod_canPartition(vector<int>& nums) {
    int sum = 0;
    for( int i = 0; i < nums.size(); i++ ){
        sum += nums[i];
    }
    if( sum % 2 != 0 )
        return false;
    sum /= 2;
    vector<vector<bool> > dp(nums.size()+1, vector<bool>(sum+1, false));
    for( int i = 0; i < nums.size()+1; i++ ){
        dp[i][0] = true;
    }
    for( int i = 1; i < nums.size()+1; i++ ){
        for( int j = 0; j < sum+1; j++ ){
            dp[i][j] = dp[i-1][j];
            // 注意下标！！！！！
            if( j-nums[i-1] >= 0 ){
                dp[i][j] = dp[i][j] | dp[i-1][j-nums[i-1]];
            }
        }
    }
    return dp[nums.size()][sum];
}

int main(){
    vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,100};
    cout << canPartition(nums);
    return 0;
}
