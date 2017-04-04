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
            TreeLinkNode *p = root;
            TreeLinkNode *e = p->next;
            while(e){
                while(!e->left && !e->right){
                    if(e->next) e = e->next;
                    else break;
                }
                if(p->left && p->right){
                    p->left->next = p->right;
                    if(e->left) p->right->next = e->left;
                    else p->right->next = e->right;
                }
                else if(p->left && e->left) p->left->next = e->left;
                else if(p->left && e->right) p->left->next = e->right;
                else if(p->right && e->left) p->right->next = e->left;
                else if(p->right && e->right) p->right->next = e->right;
                p = e;
                e = p->next;
            }
            // 最后一步
            if(p->left && p->right) p->left->next = p->right;
            // 保证所有传人的根结点都至少有一个子节点
            while(!root->left && !root->right){
                if(root->next)  root = root->next;
                else break;  // 对应于最后一个叶结点
            }
            if(root->left) root = root->left;
            else root = root->right;
        }
        
    }
};
