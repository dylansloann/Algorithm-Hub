// Time: O(nodes in tree), space: O(n)
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> final;        
    inorderHelper(root, final);
    return final;

}

void inorderHelper(TreeNode* root, vector<int>& final) {
    if (root == nullptr)
        return;
    
    inorderHelper(root->left, final);
    final.push_back(root->val);
    inorderHelper(root->right, final);
}