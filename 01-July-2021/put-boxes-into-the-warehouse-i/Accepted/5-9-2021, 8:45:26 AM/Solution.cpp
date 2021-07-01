// https://leetcode.com/problems/put-boxes-into-the-warehouse-i


class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        sort(boxes.begin(), boxes.end());
        vector<int> cap;
        cap.reserve(warehouse.size());
        for (int i = 0; i < warehouse.size(); ++i) {
            if (cap.empty()) cap.push_back(warehouse[i]);
            else cap.push_back(min(cap[i - 1], warehouse[i]));
        }
        int ans = 0;
        int right = cap.size() - 1;
        for (int box : boxes) {
            while (right >= 0 && cap[right] < box) right--;
            if (right < 0) break;
            ans++;
            right--;
        } 
        return ans;
    }
};
