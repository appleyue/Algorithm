class Solution {
public:
    /**
    找出最小的一段使得数组非递增的区间：
    画一个折线图，递增应该是上升或平行的趋势，所以
    从左往右看，当前值必为最大值，否则为右区间
    从右往左看，当前值必为最小值，否则为左区间
    */
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int mmax = nums[0], mmin = nums[n-1];
        int start = -1, end = -2;
        for( int i = 0; i < n; i++ ){
            mmax = max(mmax, nums[i]);
            mmin = min(mmin, nums[n-i-1]);
            if( nums[i] < mmax ){
                end = i;
            }
            if( nums[n-i-1] > mmin ){
                start = n-i-1;
            }
        }
        return end-start+1;
    }
    
    int ben_findUnsortedSubarray(vector<int>& nums) {
        vector<int> rec(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        int s = -1, e = -1;
        for(int i = 0; i < nums.size(); i++){
            if( s == -1 || e == -1 ){
                if( s == -1 && nums[i] != rec[i] ){
                    s = i;
                }
                if( e == -1 && nums[nums.size()-i-1] != rec[nums.size()-i-1] ){
                    e = nums.size()-1-i;
                }
            }
        }
        cout << s << " " << e << endl;
        if( s == -1 || e == -1 )
            return 0;
        return e-s+1;
    }
};
