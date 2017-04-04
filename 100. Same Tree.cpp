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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)    return true;
        if(p && !q || !p && q)  return false;
        if(p->val != q->val)    return false;
        bool isSame = true;
        if(p->left || q->left)   isSame = isSameTree(p->left, q->left);
        if(!isSame) return false;
        if(p->right || q->right) isSame = isSameTree(p->right, q->right);
        return isSame;
    }
};
