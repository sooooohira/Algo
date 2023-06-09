#include <iostream>
#include <vector>
using namespace std;

template<class Abel> struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;//根つき木とみて一つ上の要素との距離だよ

    UnionFind(int n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(int n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x) {//経路圧縮しながら重み更新
        root(x);
        return diff_weight[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) {//weight[x]-weight[y]=wとなるようにx,yをマージ
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(int x, int y) {//同じ集合に含まれている時のみ使ってね、それ以外は未定義
        return weight(y) - weight(x);
    }
};

//UnionFind<int> uf(N);みたいなかんじでインスタンス化してね！

