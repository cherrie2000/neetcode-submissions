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
TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int st, int en, int&i){
    if(st>en|| i<0 || i>=preorder.size()) return NULL;
    TreeNode* root = new TreeNode(preorder[i]);
    for(int j=st;j<=en;j++){
        if(preorder[i]==inorder[j]){
            i++;
            root->left = solve(preorder,inorder,st,j-1,i);
            root->right = solve(preorder,inorder,j+1,en,i);
            break;
        }
    }
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0, st=0, en=preorder.size()-1;
       return solve(preorder,inorder,st,en,i);
    }
};
