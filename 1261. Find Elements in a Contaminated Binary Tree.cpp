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
class FindElements {
private: 
    unordered_set<int> st;
public:
    FindElements(TreeNode* root) {
        st.clear();
        root->val = 0;
        queue<TreeNode*> qu;
        qu.push(root);

        while(!qu.empty()) {
            TreeNode* node = qu.front();
            qu.pop();
            
            int value = node->val;
            st.insert(value);

            if (node->left) {
                node->left->val = 2*value + 1;
                qu.push(node->left);
            }
            if (node->right) {
                node->right->val = 2*value + 2;
                qu.push(node->right);
            }
        }
    }
    
    bool find(int target) {
        return (st.find(target) != st.end());
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
