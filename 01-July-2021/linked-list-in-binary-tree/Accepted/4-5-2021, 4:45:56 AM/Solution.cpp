// https://leetcode.com/problems/linked-list-in-binary-tree

class Solution {
public:
    bool found = false;
    bool isSubPath(ListNode* head, TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            if (found) return true;
            auto node = st.top();
            st.pop();
            if (node->val == head->val)
                check(head, node);
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
        return false;
    }
    void check(ListNode* head, TreeNode* root) {
        if (head == nullptr) {
            found = true;
            return;
        }
        if (root == nullptr || head->val != root->val) return;
        check(head->next, root->left);
        check(head->next, root->right);
    }
};