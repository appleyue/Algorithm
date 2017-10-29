#include<iostream>
#include<vector>

/*
区间问题：最重要的是二分条件！！！？？？

合并区间，删除区间，搜索区间问题

715. Range Module
DescriptionHintsSubmissionsDiscussSolution
Discuss Pick One
A Range Module is a module that tracks ranges of numbers. Your task is to design and implement the following interfaces in an efficient manner.

addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) that are not already tracked.
queryRange(int left, int right) Returns true if and only if every real number in the interval [left, right) is currently being tracked.
removeRange(int left, int right) Stops tracking every real number currently being tracked in the interval [left, right).
Example 1:
addRange(10, 20): null
removeRange(14, 16): null
queryRange(10, 14): true (Every number in [10, 14) is being tracked)
queryRange(13, 15): false (Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
queryRange(16, 17): true (The number 16 in [16, 17) is still being tracked, despite the remove operation)
Note:

A half open interval [left, right) denotes all real numbers left <= x < right.
0 < left < right < 10^9 in all calls to addRange, queryRange, removeRange.
The total number of calls to addRange in a single test case is at most 1000.
The total number of calls to queryRange in a single test case is at most 5000.
The total number of calls to removeRange in a single test case is at most 1000.

*/

using namespace std;

class RangeModule {
private:
    vector<pair<int, int>> interval;
public:
    RangeModule() {
    }

    void addRange(int left, int right) {
        vector<pair<int, int>> add;
        for( int i = 0; i <= interval.size(); i++ ){
            if( i == interval.size() || interval[i].first > right ){
                add.push_back(make_pair(left, right));
                while( i < interval.size() ){
                    add.push_back(interval[i]);
                    i++;
                }
            }else if( interval[i].second < left ){
                add.push_back(interval[i]);
            }else{
                left = min(left, interval[i].first);
                right = max(right, interval[i].second);
            }
        }
        swap(interval, add);
    }

    bool queryRange(int left, int right) {
        int n = interval.size();
        int l = 0, r = n-1;
        while(l <= r){
            int mid = (l + r)/2;
            if( interval[mid].first >= right ){
                r = mid-1;
            }else if( interval[mid].second <= left ){
                l = mid+1;
            }else{
                return interval[mid].first <= left && interval[mid].second >= right;
            }
        }
        return false;
    }

    void removeRange(int left, int right) {
        vector<pair<int, int>> del;
        for( int i = 0; i < interval.size(); i++ ){
            if( interval[i].first >= right || interval[i].second <= left ){
                del.push_back(interval[i]);
            }else{
                if( interval[i].first < left ){
                    del.push_back(make_pair(interval[i].first, left));
                }
                if( interval[i].second > right ){
                    del.push_back(make_pair(right, interval[i].second));
                }
            }
        }
        swap(interval, del);
    }
};

int main(){
    RangeModule obj;
    obj.addRange(3, 5);
    obj.addRange(1, 2);
    obj.addRange(-1, 0);
    obj.addRange(7, 9);
    //obj.addRange(2, 8);
    //obj.removeRange(2, 8);
    int param_2 = obj.queryRange(7,8);
    cout << param_2;
    obj.removeRange(1, 2);
    return 0;
}
