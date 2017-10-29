#include<iostream>
#include<vector>

/*
dp

https://discuss.leetcode.com/topic/107998/most-consistent-ways-of-dealing-with-the-series-of-stock-problems

最重要的是这个剪枝！！！
if( dp[i] > prices[i]+dp[j]-div ){
    break;
}

714. Best Time to Buy and Sell Stock with Transaction Fee My SubmissionsBack to Contest
User Accepted: 440
User Tried: 1131
Total Accepted: 453
Total Submissions: 2986
Difficulty: Medium
Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Note:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.
*/



using namespace std;

class Solution {
public:
    int new_maxProfit(vector<int>& prices, int fee) {
        // Two kinds of solution states are possible.
        // buy_sol
        // buy_sell_sol
        // prices[0] is unique because it can't be sold it can only be bought.
        int buy_sol = -prices[0]; // loss of money
        int buy_sell_sol = 0;     // we haven't made any profit yet.
        int i = 1, size = prices.size();
        while (i < size) {
            buy_sell_sol = max(buy_sell_sol, prices[i] + buy_sol - fee);
            buy_sol = max(buy_sol, buy_sell_sol - prices[i]);
            i++;
        }
        return buy_sell_sol;
    }

    int maxProfit(vector<int>& prices, int fee) {
        vector<int> dp(prices.size(), 0);
        vector<int> sell(prices.size(), -1);
        int div;
        for( int i = 1; i < prices.size(); i++ ){
            dp[i] = dp[i-1]; sell[i] = sell[i-1];
            for( int j = i-1; j >=0 ; j-- ){
                if( sell[j] == j ){
                    div = 0;
                }else{
                    div = fee;
                }
                if( dp[i] > prices[i]+dp[j]-div ){
                    break;
                }
                if( prices[i]-prices[j]+dp[j]-div > dp[i] ){
                    dp[i] = prices[i]-prices[j]+dp[j]-div;
                    sell[i] = i;
                    //cout << i+1 << " " << dp[i] << " " << sell[i]+1 << endl;
                }
            }
        }
        /*
        for( int i = 0; i < dp.size(); i++ ){
            cout << dp[i] << endl;
        }
        */
        return dp[prices.size()-1];
    }
};

int main(){
    vector<int> prices = {};

    Solution s;
    cout << s.maxProfit(prices, 6806);
    return 0;
}
