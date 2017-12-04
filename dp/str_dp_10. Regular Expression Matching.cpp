/**10. Regular Expression Matching
*/
#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
/**
1.p.charAt(j) == s.charAt(i) : dp[i][j] = dp[i-1][j-1]
2.If p.charAt(j) == ‘.’ : dp[i][j] = dp[i-1][j-1];
3.If p.charAt(j) == ‘*’:
    here are two sub conditions:
    if p.charAt(j-1) != s.charAt(i) : dp[i][j] = dp[i][j-2] //in this case, a* only counts as empty
    if p.charAt(i-1) == s.charAt(i) or p.charAt(i-1) == ‘.’:
    dp[i][j] = dp[i-1][j] //in this case, a* counts as multiple a
    dp[i][j] = dp[i][j-1] // in this case, a* counts as single a
    dp[i][j] = dp[i][j-2] // in this case, a* counts as empty
*/
using namespace std;

bool isMatch(string s, string p) {
    // p cover s

    int ns = s.size(), np = p.size();
    s = ' '+s;
    p = ' ' + p;
    vector<vector<int>> dp(ns+1, vector<int>(np+1, 0));
    dp[0][0] = true;
    for( int j = 1; j <= np; j++ ){
        dp[0][j] = j > 1 && p[j] == '*' && dp[0][j-2];
        cout << "0:" << 0 << " " << j << " " << dp[0][j] << endl;
    }

    for( int i = 1; i <= ns; i++ ){
        for( int j = 1; j <= np; j++ ){
            if( p[j] == '*' ){
                dp[i][j] = dp[i][j-2] || ((s[i] == p[j-1] || p[j-1] == '.') && (dp[i-1][j] || dp[i][j-1]));
                cout << "1:" << i << " " << j << " " << dp[i][j] << endl;
            }else{
                dp[i][j] = dp[i-1][j-1] && (s[i] == p[j] || p[j] == '.');
                cout << "2:" << i << " " << j << " " << dp[i][j] << endl;
            }
        }
    }
    return dp[ns][np];
}

int main(){
    string s;
    string p;
    while( cin >> s >> p ){
        cout << isMatch(s, p) << endl;
    }

    return 0;
}
