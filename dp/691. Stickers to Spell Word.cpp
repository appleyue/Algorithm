#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<set>

/*
题意：在给定的数组中，寻找最小个字符串，其字符重新拼接能组成目标字符串

做法：1. 状态dp
     2. 记忆化搜索

691. Stickers to Spell Word My SubmissionsBack to Contest
User Accepted: 81
User Tried: 374
Total Accepted: 86
Total Submissions: 948
Difficulty: Hard
We are given N different types of stickers. Each sticker has a lowercase English word on it.

You would like to spell out the given target string by cutting individual letters from your collection of stickers and rearranging them.

You can use each sticker more than once if you want, and you have infinite quantities of each sticker.

What is the minimum number of stickers that you need to spell out the target? If the task is impossible, return -1.

Example 1:

Input:

["with", "example", "science"], "thehat"
Output:

3
Explanation:

We can use 2 "with" stickers, and 1 "example" sticker.
After cutting and rearrange the letters of those stickers, we can form the target "thehat".
Also, this is the minimum number of stickers necessary to form the target string.
Example 2:

Input:

["notice", "possible"], "basicbasic"
Output:

-1
Explanation:

We can't form the target "basicbasic" from cutting letters from the given stickers.
Note:

stickers has length in the range [1, 50].
stickers consists of lowercase English words (without apostrophes).
target has length in the range [1, 15], and consists of lowercase English letters.
In all test cases, all words were chosen randomly from the 1000 most common US English words, and the target was chosen as a concatenation of two random words.
The time limit may be more challenging than usual. It is expected that a 50 sticker test case can be solved within 35ms on average.
Discuss

*/

using namespace std;
class Solution {
public:
    int dp_minStickers(vector<string>& stickers, string target) {
        int n = 1<<target.size();
        vector<uint> dp(n, -1);
        dp[0] = 0;
        for( int i = 0; i < n; i++ ){
            if(dp[i] != -1){
                for( int j = 0; j < stickers.size(); j++ ){
                    int index = i;
                    for( char c: stickers[j] ){
                        for( int k = 0; k < target.size(); k++ ){
                            if( target[k] == c && !((index>>k) & 1)){
                                index |= (1<<k);
                                break;
                            }
                        }
                    }
                    dp[index] = min(dp[index], dp[i]+1);
                }
            }
        }
        return dp[n-1];
    }

    int dfs_minStickers(vector<string>& stickers, string target) {
        int m = stickers.size();
        vector<vector<int>> mp(m, vector<int>(26, 0));
        unordered_map<string, int> dp;
        // count characters a-z for each sticker
        for (int i = 0; i < m; i++)
            for (char c:stickers[i]) mp[i][c-'a']++;
        dp[""] = 0;
        return helper(dp, mp, target);
    }
    int helper(unordered_map<string, int>& dp, vector<vector<int>>& mp, string target) {
        if (dp.count(target)) return dp[target];
        int ans = INT_MAX, n = mp.size();
        vector<int> tar(26, 0);
        for (char c:target) tar[c-'a']++;
        // try every sticker
        for (int i = 0; i < n; i++) {
            // optimization
            if (mp[i][target[0]-'a'] == 0) continue;
            string s;
            // apply a sticker on every character a-z
            for (int j = 0; j < 26; j++)
                if (tar[j]-mp[i][j] > 0) s += string(tar[j]-mp[i][j], 'a'+j);
            int tmp = helper(dp, mp, s);
            if (tmp!= -1) ans = min(ans, 1+tmp);
        }
        dp[target] = ans == INT_MAX? -1:ans;
        return dp[target];
    }


    int norepeated_minStickers(vector<string>& stickers, string target) {
        map<char, int> m;
        set<char> chars;
        for( int i = 0; i < target.size(); i++ ){
            chars.insert(target[i]);
        }
        set<char>::iterator it; int i = 0;
        for(it = chars.begin(); it != chars.end(); it++, i++){
            m[*it] = i;
            //cout << *it << " " << i << endl;
        }
        vector<int> rec;
        for( int i = 0; i < stickers.size(); i++ ){
            int alpha = 0; vector<int> visit(26, 0);
            for( int j = 0; j < stickers[i].size(); j++ ){
                if( m.find(stickers[i][j]) != m.end() && visit[m[stickers[i][j]]] == 0 ){
                    alpha += 1<<m[stickers[i][j]];
                    visit[m[stickers[i][j]]] = 1;
                }
            }
            rec.push_back(alpha);
            //cout << stickers[i] << " " << alpha << endl;
        }

        int n = 1<<chars.size();
        vector<uint> dp(n, -1);
        dp[0] = 0;
        for( int i = 0; i < n; i++ ){
            if(dp[i] != -1){
                for( int j = 0; j < rec.size(); j++ ){
                    int index = i;
                    if( (rec[j]|index) > index ){
                        index |= rec[j];
                        dp[index] = min(dp[index], dp[i]+1);
                        //cout << "\t" << index << " " << dp[index] << endl;
                    }
                }
            }
        }
        return dp[n-1];
    }

    int my_minStickers(vector<string>& stickers, string target) {
        vector<int> rec;
        for( int i = 0; i < stickers.size(); i++ ){
            int alpha = 0;
            for( int j = 0; j < stickers[i].size(); j++ ){
                alpha += 1<<(stickers[i][j] - 'a');
            }
            rec.push_back(alpha);
            cout << stickers[i] << " " << alpha << endl;
        }
        int ans = 0;
        for( int i = 0; i < target.size(); i++ ){
            ans += 1<<(target[i]-'a');
        }

        int n = 1<<26;
        vector<uint> dp(n, -1);
        dp[0] = 0;
        for( int i = 0; i < n; i++ ){
            if(dp[i] != -1){
                cout << i << endl;
                for( int j = 0; j < rec.size(); j++ ){
                    int index = i;
                    if( (rec[j]|index) > index ){
                        index |= rec[j];
                        dp[index] = min(dp[index], dp[i]+1);
                        cout << "\t" << index << " " << dp[index] << endl;
                    }
                }
            }
        }
        return dp[ans];
    }

};

int main(){
    Solution s;
    vector<string> stickers;
    stickers.push_back("notice");
    stickers.push_back("possible");
    cout << s.minStickers(stickers, "basicbasic");
    return 0;
}

