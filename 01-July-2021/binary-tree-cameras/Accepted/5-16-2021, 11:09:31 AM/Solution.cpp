// https://leetcode.com/problems/binary-tree-cameras

#define pi pair<int, int>
#define v vector

int minArr(vector<int>& arr){
    int ans = arr[0];
    for (int i = 1; i < arr.size(); i++) ans = min(ans, arr[i]);
    return ans;
}

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        auto res = solve(root);
        return min(res[0], res[1]);
    }
    v<int> solve(TreeNode* node) {
        if (!node->left && !node->right) return {1, 1, 0};
        if (!node->right) {
            auto left = solve(node->left);
            return {1 + minArr(left), left[0], min(left[0], left[1])};
        }
        if (!node->left) {
            auto right = solve(node->right);
            return {1 + minArr(right), right[0], min(right[0], right[1])};
        }
        auto left = solve(node->left); auto right = solve(node->right);
        int cam = 1 + minArr(left) + minArr(right);
        int mnLeft = min(left[0], left[1]), mnRight = min(right[0], right[1]);
        int cover = min((left[0] + mnRight), (right[0] + mnLeft));
        int noCover = mnLeft + mnRight;
        return {cam, cover, noCover};
    }
};