/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
int solve(TreeNode* root, int maxi){
    if(root==NULL) return 0;
    maxi = max(root->val,maxi);
    int ans=0;
    if(maxi==root->val) ans+=1;
    int left = solve(root->left,maxi);
    int right=solve(root->right, maxi);
    return ans+left+right;
}
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        return solve(root,root->val);
    }
};
