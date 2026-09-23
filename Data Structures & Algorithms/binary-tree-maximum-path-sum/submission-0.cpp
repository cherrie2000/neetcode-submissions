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
int maxSum;
int solve(TreeNode* root){
    if(root==NULL) return 0;
    int left = solve(root->left);
    int right = solve(root->right);

    int sum =root->val;
    sum+=left>0?left:0;
    sum+=right>0?right:0;
    if(left<0) left=0;
    if(right<0) right=0;
    
    maxSum = max(maxSum,sum);
    return root->val+max(left,right);
}
    int maxPathSum(TreeNode* root) {
    maxSum = INT_MIN;
    solve(root);
    return maxSum;
    }
};
