// https://leetcode.com/problems/construct-binary-tree-from-string

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
#define umap unordered_map

class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.length() == 0) return nullptr;
        vector<int> stack;
        umap<int, int> mp;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                stack.push_back(i);
            else if (s[i] == ')') {
                mp[stack[stack.size() - 1]] = i;
                stack.pop_back();
            }
        }

        return solve(0, s.length() - 1, s, mp);
    }

    TreeNode* solve(int l, int r, string &s, umap<int, int> &mp) {

        int sign = 1;
        if (s[l] == '-') {
            sign = -1;
            l++;
        }
        int num = 0;
        while (isdigit(s[l])) {
            num = num * 10 + (s[l] - '0');
            l++;
        }
        num = num * sign;
        TreeNode* node = new TreeNode(num);
        if (l < r)
            node->left = solve(l + 1, mp[l] - 1, s, mp);
        else
            return node;
        int secondL = mp[l] + 1;
        if (secondL < r)
            node->right = solve(secondL + 1, mp[secondL] - 1, s, mp);
        
        return node;
    }
};