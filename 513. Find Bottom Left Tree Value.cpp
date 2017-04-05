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
    int findBottomLeftValue(TreeNode* root) {
        int result = root->val;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            result = q.front()->val;
            int size = q.size();
            while(size--){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return result;
    }
};
