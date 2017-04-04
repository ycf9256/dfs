/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        while(root){
            if(!root->left) return;
            root->left->next = root->right;
            TreeLinkNode *p = root;
            while(p->next){
                p->right->next = p->next->left;
                p->next->left->next = p->next->right;
                p = p->next;
            }
            root = root->left;
        }
    }
};
