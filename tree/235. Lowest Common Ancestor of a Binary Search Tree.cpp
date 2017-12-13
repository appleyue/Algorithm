#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;
/**
计算二叉搜索树的中两节点的最低公共父节点
hint:
当前节点>p和q值，p和q一定在其左子树上
当前节点<p和q值，p和q一定在其右子树上
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
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while( root ){
            if( root->val > p->val && root->val > q->val ){
                root = root->left;
            }else if( root->val < p->val && root->val < q->val ){
                root = root->right;
            }else{
                return root;
            }
        }
        return root;
    }
};
