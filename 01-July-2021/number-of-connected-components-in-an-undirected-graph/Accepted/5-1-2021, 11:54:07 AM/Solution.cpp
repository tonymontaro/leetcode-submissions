// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph

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
};


class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (auto vec: edges) {
            uf.unify(vec[0], vec[1]);
        }
        return uf.groups;
    }
};