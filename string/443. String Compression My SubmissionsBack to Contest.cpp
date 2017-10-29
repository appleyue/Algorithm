/*
443. String Compression My SubmissionsBack to Contest
User Accepted: 1210
User Tried: 1446
Total Accepted: 1223
Total Submissions: 3403
Difficulty: Easy
Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.

Example 1:
Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
Example 2:
Input:
["a"]

Output:
Return 1, and the first 1 characters of the input array should be: ["a"]

Explanation:
Nothing is replaced.
Example 3:
Input:
["a","b","b","b","b","b","b","b","b","b","b","b","b"]

Output:
Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].

Explanation:
Since the character "a" does not repeat, it is not compressed. "bbbbbbbbbbbb" is replaced by "b12".
Notice each digit has it's own entry in the array.
Note:
All characters have an ASCII value in [35, 126].
1 <= len(chars) <= 1000.
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        char last = chars[0];
        vector<char> ans;
        int cnt = 1;
        for( int i = 1; i < chars.size(); i++ ){
            if( chars[i] == last ){
                cnt += 1;
            }else{
                ans.push_back(last);
                if( cnt > 1 ){
                    vector<char> tmp;
                    while( cnt > 0 ){
                        tmp.push_back(cnt%10+'0');
                        cnt /= 10;
                    }
                    for( int j = tmp.size()-1; j >= 0 ; j-- ){
                        ans.push_back(tmp[j]);
                    }
                    cnt = 1;
                }
                last = chars[i];
            }
        }
        ans.push_back(last);
        if( cnt > 1 ){
            vector<char> tmp;
            while( cnt > 0 ){
                tmp.push_back(cnt%10+'0');
                cnt /= 10;
            }
            for( int j = tmp.size()-1; j >= 0 ; j-- ){
                ans.push_back(tmp[j]);
            }
            cnt = 0;
        }

        chars = ans;
        return ans.size();
    }
};
