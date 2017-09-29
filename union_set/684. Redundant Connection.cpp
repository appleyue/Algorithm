#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>

using namespace std;

/*
684. Redundant Connection My SubmissionsBack to Contest

无向图寻找构成环的边，返回输入中的最后一条应该删除的边

方法：并查集

User Accepted: 381
User Tried: 963
Total Accepted: 390
Total Submissions: 1995
Difficulty: Medium
In this problem, a tree is an undirected graph that is connected and has no cycles.

The given input is a graph that started as a tree with N nodes (with distinct values 1, 2, ..., N), with one additional edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] with u < v, that represents an undirected edge connecting nodes u and v.

Return an edge that can be removed so that the resulting graph is a tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array. The answer edge [u, v] should be in the same format, with u < v.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given undirected graph will be like this:
  1
 / \
2 - 3
Example 2:
Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
Output: [1,4]
Explanation: The given undirected graph will be like this:
5 - 1 - 2
    |   |
    4 - 3

Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.

Update (2017-09-26):
We have overhauled the problem description + test cases and specified clearly the graph is an undirected graph. For the directed graph follow up please see Redundant Connection II). We apologize for any inconvenience caused.
*/

class Solution {
public:
    int findfather(vector<int>& father, int son){
        if( father[son] != son ){
            father[son] = findfather(father, father[son]);
        }
        return father[son];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> father(2010);
        vector<vector<int>> ans;
        for( int i = 0; i < father.size(); i++ ){
            father[i] = i;
        }

        for( int i = 0; i < edges.size(); i++ ){
            int index1 = findfather(father, edges[i][0]);
            int index2 = findfather(father, edges[i][1]);
            cout << edges[i][0] << " " << edges[i][1] << " -> " << index1 << " " << index2 << endl;

            if( index1 == index2 )
                ans.push_back(edges[i]);
            else
                father[index2] = index1;
            /*
            for( int j = 0; j < 10; j++ ){
                cout << "union[" << j << "]=" << father[j] << "  ";
            }
            cout << endl;
            */
        }
        return ans[ans.size()-1];
    }
};

int main(){
    freopen("data.in", "r", stdin);
    Solution s;
    vector<vector<int> > edges;
    int a, b;
    while(cin >> a ){
        if(a == -1)
            break;
        cin >> b;
        vector<int> tmp;
        tmp.push_back(a); tmp.push_back(b);
        edges.push_back(tmp);
    }
    vector<int> ans = s.findRedundantConnection(edges);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
