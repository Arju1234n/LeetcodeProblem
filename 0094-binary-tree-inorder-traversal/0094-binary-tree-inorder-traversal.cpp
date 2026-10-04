class Solution {
public:
    vector<int> ans;

    void inorder(TreeNode* root) {
        if(root == NULL)
            return;

        inorder(root->left);   // LEFT

        ans.push_back(root->val); // ROOT

        inorder(root->right);  // RIGHT
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
};