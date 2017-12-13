#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>

using namespace std;

/**
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4
*/

int longestValidParentheses(string s) {
    /**
    record str position use stack
    */
    if( s.size() < 2 )
        return 0;
    stack<int> sta;
    int i = 1, num = 0, ans = 0;
    for( int i = 0; i < s.size(); i++ ){
        if( s[i] == '(' ){
            sta.push(i);
        }else{
            if( !sta.empty() && s[sta.top()] == '(' ){
                sta.pop();
            }else{
                sta.push(i);
            }
        }
    }

    if( sta.empty() ){
        return s.size();
    }
    int last = s.size();
    while( !sta.empty() ){
        ans = max(ans, last-sta.top()-1);
        last = sta.top();
        sta.pop();
    }
    return max(last, ans);
}

int dp_longestValidParentheses(string s) {
    /**
    dp[i] longest valid length with str[i] end
    */
    int n = s.size();
    if( n < 2 )
        return 0;
    s = " " + s;
    int ans = 0;
    vector<int> dp(n+1, 0);
    for( int i = 1; i <= n; i++ ){
        if( s[i] == '(' ){
            dp[i] = 0;
        }else{
            if( s[i-1] == '(' ){
                dp[i] = 2 + dp[i-2];
            }else{
                if( s[i-dp[i-1]-1] == '(' ){
                    dp[i] = 2 + dp[i-1] + dp[i-dp[i-1]-2];
                }
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int error_longestValidParentheses(string s) {
    int n = s.size();
    if( n < 2 )
        return 0;
    s = " " + s;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= n; j++ ){
            if( s[j] == '(' ){
                dp[i][j] = dp[i][j-1];
            }else{
                for( int k = i; k < j; k++ ){
                    int add = 0;
                    if( k+1 <= j-1 ){
                        add = dp[k+1][j-1];
                    }
                    if( k+1 <= j-1 ){
                        dp[i][j] = max(dp[i][j], 2+add);
                    }
                }
            }
            cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    return dp[1][n];
}

int main(){
    string s;
    while(cin >> s){
        cout << longestValidParentheses(s) << endl;
    }
    return 0;
}
