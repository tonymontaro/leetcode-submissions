// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if (k == cardPoints.size()) return  total;
        int remove = 0;
        k = cardPoints.size() - k;
        for (int i = 0; i < k; i++) remove += cardPoints[i];
        int best = remove;
        for (int i = k; i < cardPoints.size(); i++) {
            remove -= cardPoints[i - k];
            remove += cardPoints[i];
            best = min(best, remove);
        } 
        return total - best;
    }
};