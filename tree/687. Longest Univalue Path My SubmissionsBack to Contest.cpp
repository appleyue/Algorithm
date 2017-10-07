/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*
 687. Longest Univalue Path My SubmissionsBack to Contest
User Accepted: 790
User Tried: 1265
Total Accepted: 800
Total Submissions: 3564
Difficulty: Easy
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
 */
class Solution {
public:
    int find(TreeNode* root, int& ans){
        if(root){
            int l = find(root->left, ans);
            int r = find(root->right, ans);
            if( root->left ){
                l = (root->left->val == root->val) ? l+1:0;
            }
            if( root->right ){
                r = (root->right->val == root->val) ? r+1:0;
            }
            ans = max(ans, r+l);
            return l>r?l:r;
        }
        return 0;
    }

    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        find(root, ans);
        return ans;
    }
};

 /*
 // get a repeat value sub-tree, not a path
class Solution {
public:
    void find(map<int, int>& rec, map<int, int>& visit, TreeNode* root, int num){
        if( root != NULL ){
            rec.insert(pair<int, int>(num, root->val));
            visit.insert(pair<int, int>(num, -1));
            find(rec, visit, root->left, num*2);
            find(rec, visit, root->right, num*2+1);
        }
    }

    int count(int index, map<int, int>& rec, map<int, int>& visit, int val){
        if( visit[index] == -1 ){

            //cout << index << " " << rec[index] << " " << val << endl;
            if( rec[index] == val ){
                            visit[index] = 1;

                int num = 1+count(index*2, rec, visit, val) + count(index*2+1, rec, visit, val);
                //cout << num << endl;
                return num;
            }
            return 0;
        }
        return 0;
    }

    int longestUnivaluePath(TreeNode* root) {
        if( root == NULL )
            return 0;
        map<int, int> rec;
        map<int, int> visit;
        find(rec, visit, root, 1);
        int ans = 0;
        map<int, int>::iterator iter;
        for( iter = rec.begin(); iter != rec.end(); iter++ ){
            //cout << iter->first << " " << iter->second << endl;
        }
        for( iter = rec.begin(); iter != rec.end(); iter++ ){
            int index = iter->first;
            int val = iter->second;
            if( visit[index] == -1 ){
                int num = count(index, rec, visit, val);
                cout << index << " " << val << " num:" << num << endl;
                if( num > ans ){
                    ans = num;
                }
            }else{
                cout << index << " " << val << "visit\n";
            }
        }
        return ans-1;
    }
};
*/
