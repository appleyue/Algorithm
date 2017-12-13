#include<iostream>
#include<string>
#include<stdio.h>
#include<vector>
#include<limits.h>

using namespace std;

/**
dp[i][k]
最后一个位置是
ring[k]
时，得到
key[0-i]
的最短步数
*/

int findRotateSteps(string ring, string key) {
    int rsize = ring.size(), ksize = key.size();
    vector<vector<int>> pos(26, vector<int>(0, 0));
    for( int i = 0; i < ring.size(); i++ ){
        pos[ring[i]-'a'].push_back(i);
    }

    vector<int> pre(1, 0);
    vector<vector<int>> dp(ksize+1, vector<int>(rsize, INT_MAX));
    dp[0][0] = 0;

    for( int i = 1; i <= key.size(); i++ ){
        for( auto j: pre ){
            for( auto k: pos[key[i-1]-'a'] ){
                dp[i][k] = min(dp[i][k], dp[i-1][j]+min(abs(j-k), rsize-abs(j-k)));
            }
        }
        pre = pos[key[i-1]-'a'];
    }
    int ans = INT_MAX;
    for( auto v: dp[ksize] ){
        ans = min(ans, v);
    }
    return ans+ksize;
}


int dp_findRotateSteps(string ring, string key) {
    int rsize = ring.size(), ksize = key.size();
    vector<vector<int>> pos(26, vector<int>(0, 0));
    for( int i = 0; i < ring.size(); i++ ){
        pos[ring[i]-'a'].push_back(i);
    }

    vector<int> pre(1, 0);
    vector<int> dp(rsize, INT_MAX);
    dp[0] = 0;
    for( int i = 0; i < ksize; i++ ){
        //for( int j = 0; j < pos[key[i]-'a'].size(); j++ ){
        vector<int> tmp_dp(rsize, INT_MAX);
        for( auto k: pre ){
            //for( int k = 0; k < pre.size(); k++ ){
            //cout << key[i] << " pre " << k << endl;
            for( auto j: pos[key[i]-'a']){
                tmp_dp[j] = min(tmp_dp[j], dp[k]+min(abs(j-k), rsize-abs(j-k)));
                //cout << "\t" << j << " dp:" << tmp_dp[j] << endl;
            }
        }
        dp = tmp_dp;
        pre = pos[key[i]-'a'];
    }
    int ans = INT_MAX;
    for( auto v: dp ){
        ans = min(v, ans);
    }
    return ans+ksize;
}

int main(){
    string ring, key;
    vector<int> a(10, 0);
    while( cin >> ring >> key ){
        cout << findRotateSteps(ring, key) << endl;
    }

    return 0;
}
