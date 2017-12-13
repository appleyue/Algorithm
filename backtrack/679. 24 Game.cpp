#include<iostream>
#include<vector>
#include<list>
#include<stdio.h>
#include<cstdlib>
#include<cmath>
/**
You have 4 cards each containing a number from 1 to 9. You need to judge whether they could operated through *, /, +, -, (, ) to get the value of 24.

Example 1:
Input: [4, 1, 8, 7]
Output: True
Explanation: (8-4) * (7-1) = 24
Example 2:
Input: [1, 2, 1, 2]
Output: False
Note:
The division operator / represents real division, not integer division. For example, 4 / (1 - 2/3) = 12.
Every operation done is between two numbers. In particular, we cannot use - as a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.

hint:
回溯做法
每次取两个数，得到用运算符组合的数字，遍历该数组，每次加进去一个，调用helper函数

注意的点是：
i>j
所以在删除时，先删除后面的i，再删除前面的j
后面插入时，先插入前面的j，后插入后面的i
*/
using namespace std;
double eps = 0.0000001;

bool helper(vector<double>& rec){
    if( rec.size() == 1 ){
        if( fabs(rec[0]-24.0) < eps )
            return true;
        return false;
    }
    bool f = false;
    /*
    for( int iii = 0; iii < rec.size(); iii++ ){
        cout << rec[iii] << " ";
    }
    cout << endl;
    */
    for( int i = 0; i < rec.size(); i++ ){
        for( int j = 0; j < i; j++ ){

            double p1 = rec[i], p2 = rec[j];
            vector<double> next;
            next.push_back(p1+p2);
            next.push_back(p1-p2);
            next.push_back(p2-p1);
            next.push_back(p1*p2);
            if( abs(p1) > eps ){
                next.push_back(p2/p1);
            }
            if( abs(p2) > eps ){
                next.push_back(p1/p2);
            }
            rec.erase(rec.begin()+i);
            rec.erase(rec.begin()+j);
            for( int k = 0; k < next.size(); k++ ){
                rec.push_back(next[k]);
                bool ff = helper(rec);
                f |= ff;
                rec.erase(rec.end()-1);
            }
            rec.insert(rec.begin()+j, p2);
            rec.insert(rec.begin()+i, p1);
        }
    }
    return f;
}

bool judgePoint24(vector<int>& nums) {
    vector<double> rec;
    for( int i = 0; i < nums.size(); i++ ){
        rec.push_back(double(nums[i]));
    }
    return helper(rec);
}

int main(){
    vector<int> nums = {4, 1, 8, 7};
    cout << judgePoint24(nums) << endl;
    return 0;
}
