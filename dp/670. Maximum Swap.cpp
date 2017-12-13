/**
只交换两个字符能得到的最大整数

不需要交换的情况是从前往后数字递减！

dp 从后往前，记录当前最大值的下标
从前往后，依次对比，若记录下标对应的值 > 当前值，则替换
*/

class Solution {
public:
    int maximumSwap(int num) {
        string snum = to_string(num);
        vector<int> rec(snum.size(), 0);
        int maxind = snum.size()-1;
        for( int i = snum.size()-1; i >= 0; i-- ){
            if( snum[i]-'0' > snum[maxind]-'0' ){
                maxind = i;
            }
            rec[i] = maxind;
        }
        
        for( int i = 0; i < snum.size(); i++ ){
            if( snum[rec[i]] != snum[i] ){
                char tmp = snum[i];
                snum.replace(i, 1, 1, snum[rec[i]]);
                snum.replace(rec[i], 1, 1, tmp);
                return std::atoi(snum.c_str());
            }
        }
        return num;
    }
};

/*
bool comp(pair<int, int> a, pair<int, int> b){
    if( a.first == b.first ){
        return a.second < b.second;
    }
    return a.first > b.first;
}
class Solution {
public:
    int getnum(vector<int>& vnum, int i, int j){
        int num = 0, mul = 1;
        for( int t = 0; t < vnum.size(); t++ ){
            if( t == i )
                num += vnum[j]*mul;
            if( t == j )
                num += vnum[i]*mul;
            if( t != i && t != j )
                num += vnum[t]*mul;
            mul *= 10;
        }
        cout << num << endl;
        return num;
    }
    int maximumSwap(int num) {
        vector<pair<int, int> > rec;
        vector<int> vnum;
        int i = 0, tnum = num;
        while( num > 0 ){
            rec.push_back(make_pair(num%10, i));
            vnum.push_back(num%10);
            i += 1;
            num /= 10;
        }
        sort(rec.begin(), rec.end(), comp);
        int index = 0;
        for( int i = vnum.size()-1; i >= 0; i-- ){
            while( vnum[i] <= rec[index].first && rec[index].second > i ){
                index += 1;
            }
            if( vnum[i] < rec[index].first ){
                cout << i << " " << vnum[i] << " " << rec[index].second << " " << vnum[rec[index].second] << endl;
                return getnum(vnum, i, rec[index].second);
            }
        }
        return tnum;
    }
};
*/
