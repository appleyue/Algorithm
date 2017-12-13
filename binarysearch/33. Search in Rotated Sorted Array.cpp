#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>

using namespace std;

/**
第一想法是找pivot，把数组顺序调整好，然后二分。

这里出现第一个优化的点，不需要调整数组顺序，只需要判断target在pivot的前段还是后段，直接二分。

针对找pivot又出现一个优化的点，二分查找，若
nums[mid] > nums[end]
则pivot一定在[mid+1, end]之间
*/

int mysearch(vector<int>& nums, int target){
    int ans = -1;
    int n = nums.size();

    int fs = 0, fe = n-1;
    while(fs < fe){
        int fm = (fs+fe)/2;
        if( nums[fm] > nums[fe] ){
            fs = fm+1;
        }else{
            fe = fm;
        }
    }
    cout << fs << " " << fe << endl;
    int start = fs;
    /*
    for( int i = 1; i < n; i++ ){
        if( nums[i] < nums[i-1] ){
            start = i;
            break;
        }
    }
    */
    int s = 0, e = n-1;
    if( start > 0 ){
        if( target >= nums[0] && target <= nums[start-1] ){
            e = start-1;
        }else if( target >= nums[start] && target <= nums[n-1] ){
            s = start;
        }else{
            return ans;
        }
    }
    while( s <= e ){
        int mid = (s+e)/2;
        if( nums[mid] == target ){
            return mid;
        }else if( target > nums[mid] ){
            s = mid+1;
        }else{
            e = mid-1;
        }
    }
    /*
    vector<int> renum(nums.begin(), nums.end());
    if( start != 0 ){
        for( int i = 0; i < n; i++ ){
            cout << i << " " << (i+n-start)%n << " " << ((i+n-start)%n+start)%n << endl;
            renum[(i+n-start)%n] = nums[i];
        }
    }
    int s = 0, e = n-1;
    while( s >= 0 && s <= e ){
        int m = (s+e)/2;
        //cout << s << " " << e << " " << m << " " << renum[m] << endl;
        if( renum[m] == target ){
            return (m+start)%n;
        }else if( renum[m] < target ){
            s = m+1;
        }else{
            e = m-1;
        }
    }
    */
    return ans;
}

int main(){
    vector<int> nums = {4, 5, 0, 1, 2};
    cout << mysearch(nums, 6);
    return 0;
}
