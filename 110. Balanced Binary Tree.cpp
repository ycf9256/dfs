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
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        if(!root)   return flag;
        isBalanced(flag, root);
        return flag;
    }
    int isBalanced(bool& flag, TreeNode* node){
        if(!node->left && !node->right) return 1;
        int h1 = 1, h2 = 1;     // 每个分支(左右)至少存在一个结点
        if(node->left && !node->right)  h1 = isBalanced(flag, node->left) + 1;
        else if(!node->left && node->right)  h2 = isBalanced(flag, node->right) + 1;
        else{
            h1 = isBalanced(flag, node->left) + 1;
            h2 = isBalanced(flag, node->right) + 1;
        }
        if(abs(h1 - h2) > 1) flag = false;
        return max(h1, h2);
    }
};
