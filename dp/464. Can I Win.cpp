#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<map>

using namespace std;

/**

In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.

What if we change the game so that players cannot re-use integers?

For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.

Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.

You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.

Example

Input:
maxChoosableInteger = 10
desiredTotal = 11

Output:
false

Explanation:
No matter which integer the first player choose, the first player will lose.
The first player can choose an integer from 1 up to 10.
If the first player choose 1, the second player can only choose integers from 2 up to 10.
The second player will win by choosing 10 and get a total = 11, which is >= desiredTotal.
Same with other integers chosen by the first player, the second player will always win.

hint:

1. memory search -> top down dp

2. how to save bool vector
notice: maxChoosableInteger <= 20 and desiredTotal <= 300.
use int to replace bool vector

*/

int format(vector<bool>& state){
    int num = 1, ans = 0;
    for( int i = 1; i < state.size(); i++ ){
        num <<= 1;
        if( state[i] ){
            ans += num;
        }
    }
    return ans;
}

bool traval(map<int, bool>& rec, vector<bool>& state, int total){
    if( total <= 0 )
        return false;
    int key = format(state);
    if( rec.find(key) != rec.end() ){
        return rec[key];
    }

    for( int i = 1; i < state.size(); i++ ){
        if( !state[i] ){
            state[i] = true;
            if(!traval(rec, state, total-i)){
                rec.insert(make_pair(key, true));
                state[i] = false;
                return true;
            }
            state[i] = false;
        }
    }
    rec.insert(make_pair(key, false));
    return false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if( desiredTotal <= 0 )
        return true;
    int sum = (1+maxChoosableInteger)*maxChoosableInteger/2;
    if( sum < desiredTotal )
        return false;
    map<int, bool> rec;
    vector<bool> state(maxChoosableInteger+1, false);
    return traval(rec, state, desiredTotal);
}

int main(){
    int choose = 10, desired = 40;
    cout << canIWin(choose, desired) << endl;
}
