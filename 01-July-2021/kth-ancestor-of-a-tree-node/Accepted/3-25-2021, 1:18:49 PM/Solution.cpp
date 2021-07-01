// https://leetcode.com/problems/kth-ancestor-of-a-tree-node

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define v vector


class TreeAncestor {
public:
    v<umap<int, int>> anscestor;
    int n;
    int mx = 16;
    TreeAncestor(int nn, vector<int>& parent) {
        n = nn;
        v<umap<int, int>> ansc(n);
        for (int i = 0; i < n; i++) ansc[i][0] = parent[i];
        for (int i = 1; i <= mx; i++) {
            for (int node = 0; node < n; node++) {
                int p = ansc[node][i - 1];
                if (p == -1) ansc[node][i] = -1;
                else ansc[node][i] = ansc[p][i - 1];
            }
        }
        swap(anscestor, ansc);
    }

    int getKthAncestor(int node, int k) {
        if (k > pow(2, mx)) return -1;
        while (k > 0) {
            int i = 0;
            while (pow(2, i + 1) <= k) i++;
            node = anscestor[node][i];
            if (node == -1) return -1;
            k -= pow(2, i);
        }
        return node;
    }
};