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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL) return res;
        binaryTreePaths(res, root, to_string(root->val));
        return res;
    }
    void binaryTreePaths(vector<string>& result, TreeNode* node, string str){
        if(node->left == NULL && node->right == NULL){
            result.push_back(str);
            return;
        }
        if(node->left)   binaryTreePaths(result, node->left, str + "->" + to_string(node->left->val));
        if(node->right)  binaryTreePaths(result, node->right, str + "->" + to_string(node->right->val));
    }
};
