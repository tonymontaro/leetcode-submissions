// https://leetcode.com/problems/redundant-connection

class UnionFind {
    /*
    UnionFind or DisjoinSet data-structure with Path compression. Zero indexed.
    Initialize:
            UnionFind(n)
            Methods:
    unify(p, q)        # unify p and q
    connected(p, q)    # is p connected to q (return bool)
    find(p)            # find the parent of q
    getSize(p)         # return the group size of p
    */
private:
    int size = 0;
    int* sizes;
    int* parents;
public:
    int groups;
    UnionFind(int n) {
        size = n;
        groups = n;
        sizes = new int[size];
        parents = new int[size];
        for(int i=0; i < size; i++) {
            parents[i] = i;
            sizes[i] = 1;
        }
    }
    ~UnionFind() {
        delete [] sizes;
        delete [] parents;
    }

    int find(int p) {
        assert(p >= 0 && p < size);
        int root = p;
        while (root != parents[root])
            root = parents[root];

        // path compression
        while (p != root) {
            int tmp = parents[p];
            parents[p] = root;
            p = tmp;
        }
        return root;
    }
    int getSize(int p) {
        return sizes[find(p)];
    }

    bool connected(int p, int q){
        return find(p) == find(q);
    }
    bool unify(int p, int q) {
        assert(p >= 0 && p < size);
        assert(q >= 0 && q < size);
        int root1 = find(p);
        int root2 = find(q);
        if (root1 == root2) return false;
        if (sizes[root1] < sizes[root2]){
            parents[root1] = root2;
            sizes[root2] += sizes[root1];
        } else {
            parents[root2] = root1;
            sizes[root1] += sizes[root2];
        }
        groups -= 1;
        return true;
    }
    vector<vector<int>> getChildren() {
        vector<vector<int>> rs(size);
        for (int i = 0; i < size; i++) {
            rs[find(i)].push_back(i);
        }
        return rs;
    }
    void print_sets() {
        for(int i=0; i < size; i++) cout << find(i) << " ";
        cout << endl;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(edges.size() + 1);
        for (auto &edge: edges) {
            int a = edge[0], b = edge[1];
            if (!uf.unify(a, b)) return {a, b};
        }
        return {0, 0};
    }
};