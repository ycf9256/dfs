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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tem;
        if(root == NULL) return res;
        int s = 0;
        pathSum(res, root, s, sum, tem);
        return res;
    }
    void pathSum(vector<vector<int>>& result, TreeNode* node, int curSum, int sum, vector<int> temp){
        int val = node->val;
        int n = curSum + val;
        temp.push_back(val);
        if(node->left == NULL && node->right == NULL && n == sum){
            result.push_back(temp);
            return;
        }
        if(node->left)  pathSum(result, node->left, n, sum, temp);
        if(node->right)  pathSum(result, node->right, n, sum, temp);
    }
    
};
