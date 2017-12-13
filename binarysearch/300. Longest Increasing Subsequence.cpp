#include<iostream>
#include<stdio.h>
#include<vector>

/**
LIS 最长上升子序列
rec[i] record the smallest end num in all LIS which length is i
rec strict increasement !!!

http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
*/

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> rec;
    for( int i = 0; i < nums.size(); i++ ){
        int l = 0, r = rec.size();
        while( l < r ){
            int m = (l+r)/2;
            if( nums[i] > rec[m] ){
                l = m+1;
            }else{
                r = m;
            }
        }
        if( l == rec.size() ){
            rec.push_back(nums[i]);
        }else{
            rec[l] = nums[i];
        }
    }
    return rec.size();
}

int main(){
    vector<int> nums = {2, 5, 3, 7, 1, 2, 3, 4};
    cout << lengthOfLIS(nums);
    return 0;
}
