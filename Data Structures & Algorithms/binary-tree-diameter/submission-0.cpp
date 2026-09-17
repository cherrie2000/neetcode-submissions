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
pair<int,int> solve(TreeNode* root){
    if(root==NULL) return {0,0};
    pair<int,int> left=solve(root->left);
    pair<int,int> right = solve(root->right);
    int d = max({left.first,right.first,left.second+right.second});
    int h  = max(left.second,right.second)+1;
    return {d,h};
}
    int diameterOfBinaryTree(TreeNode* root) {
        auto ans = solve(root);
        return ans.first;
    }
};
