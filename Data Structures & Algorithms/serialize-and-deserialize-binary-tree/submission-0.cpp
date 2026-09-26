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

class Codec {
public:

   void encode(TreeNode* root, string&s){
        if(root==NULL){
            s+="N";
            s+=",";
            return;
        }
        s+=to_string(root->val);
        s+=",";
        encode(root->left,s);
        encode(root->right,s);
    }
    string serialize(TreeNode* root) {
        string s="";
        encode(root,s);
       return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* solve(string&data, int&i){
        int j = data.find(',', i);

        string value = data.substr(i, j - i);
        i=j+1;

        if(i==data.size() || value=="N")  {  return NULL;}

        TreeNode* root=new TreeNode(stoi(value));
        root->left = solve(data,i);
        root->right = solve(data,i);
        return root;
    }
    TreeNode* deserialize(string data) {
        int i=0;
        return solve(data,i);
    }
};
