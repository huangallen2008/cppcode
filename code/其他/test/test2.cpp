#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge &e) const {
        return w > e.w; // 大到小
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i)
        cin >> edges[i].u >> edges[i].v >> edges[i].w, --edges[i].u, --edges[i].v;

    sort(edges.begin(), edges.end());

    vector<vector<int>> g(n);
    vector<int> topo(n), inv(n);
    iota(topo.begin(), topo.end(), 0); // 初始拓撲排序
    iota(inv.begin(), inv.end(), 0);   // topo位置的反查表

    auto can_add = [&](int u, int v) {
        return topo[u] < topo[v]; // 拓撲順序合法才可以加入
    };

    int total = 0;
    for (auto [u, v, w] : edges) {
        if (can_add(u, v)) {
            g[u].push_back(v);
            total += w;
        }
    }

    cout << total << '\n';
}