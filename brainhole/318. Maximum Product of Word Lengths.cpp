/**
寻找一组字符串中，最大的[字符完全没有交集的两个字符串长度的乘积]
hint:
int记录字符串中字母出现位置（不能用+=，要用|=），&操作，若为0则没有字符交集
*/


bool comp(string a, string b){
    return a.size() > b.size();
}

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> rec(words.size(), 0);
        sort(words.begin(), words.end(), comp);
        for( int i = 0; i < words.size(); i++ ){
            //vector<int> visit(26, 0);
            for( int j = 0; j < words[i].size(); j++ ){
                rec[i] |= (1<<words[i][j]-'a');
                /*
                if( !visit[words[i][j]-'a'] ){
                    rec[i] += (1<<(words[i][j]-'a'));
                }
                visit[words[i][j]-'a'] = 1;
                */
            }
        }
        int ans = 0;
        for( int i = 0; i < words.size(); i++ ){
            for( int j = 0; j < words.size(); j++ ){
                if( (rec[i] & rec[j]) == 0 ){
                    int len = words[i].size()*words[j].size();
                    ans = max(ans, len);
                }
            }
        }
        return ans;
    }
};
