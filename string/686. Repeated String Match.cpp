#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>

/*
KMP
问题1：如何求next数组
问题2：如何应用到该题

686. Repeated String Match My SubmissionsBack to Contest
User Accepted: 1218
User Tried: 1657
Total Accepted: 1248
Total Submissions: 6003
Difficulty: Easy
Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

Note:
The length of A and B will be between 1 and 10000.
*/

using namespace std;

class Solution {
public:
    int kmp_repeatedStringMatch(string A, string B){
        // caluate B next
        vector<int> next(B.size(), 0);
        next[0] = -1;
        int i = 0, j = -1;
        while( i < B.size() ){
            if( j == -1 || B[i] == B[j] ){
                i++; j++; next[i] = j;
            }else{
                j = next[j];
            }
        }
        for( int i = 0; i < B.size(); i++ ){
            cout << next[i] << " ";
        }
        cout << endl;
        // caluate repeat
        for( int i = 0, j = 0; i < A.size(); i += j+1, j = next[j] ){
            while( j < B.size() && A[(i+j)%A.size()] == B[j]) j++;
            if( j == B.size() ){
                return (i+j)%A.size() + ((i+j)%A.size() == 0? 0:1);
            }
        }
    }

    int repeatedStringMatch(string a, string b) {
        vector<int> prefTable(b.size());
        for (auto sp = 1, pp = 0; sp < b.size(); prefTable[sp++] = pp) {
            if (b[pp] == b[sp]) ++pp;
            else pp = prefTable[pp > 0 ? pp - 1 : 0];
        }
        for( int i = 0; i < b.size(); i++ ){
            cout << prefTable[i] << " ";
        }
        cout << endl;
        for (auto i = 0, j = 0; i < a.size(); i += j + 1, j = prefTable[j > 0 ? j - 1 : 0]) {
            while (j < b.size() && a[(i + j) % a.size()] == b[j]) ++j;
            if (j == b.size()) return (i + j) / a.size() + ((i + j) % a.size() != 0 ? 1 : 0);
        }
        return -1;
    }

    int easy_repeatedStringMatch(string A, string B) {
        for( int i = 0; i < A.size(); i++ ){
            int j = 0;
            while( j < B.size() && A[(i+j)%A.size()] == B[j] ) j++;
            if( j == B.size() ){
                return (i+j)/A.size() + ((i+j)%A.size()==0 ? 0 : 1);
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    cout << s.repeatedStringMatch("abcd", "cdabcdab");
    return 0;
}
