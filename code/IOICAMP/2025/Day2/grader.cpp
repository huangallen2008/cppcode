#include "lib0906.h"
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

namespace {
const int maxn = 1505;
const int AC_cost = 10100;
const int max_cost = 2000000;

int n;
int cost = 0;

void WA(const string &msg) {
    printf("Wrong Answer: %s\n", msg.c_str());
    exit(0);
}

void ensureImpl(bool condition, const char* conditionStr) {
    if (condition)
        return;
    WA(conditionStr);
}

vector<int> T[maxn];
int dis[maxn][maxn];

void get_distances(int n, int par, int root) {
    if (par) dis[root][n] = dis[root][par] + 1;
    for (int v:T[n]) {
        if (v != par) {
            get_distances(v, n, root);
        }
    }
}
}

int query(int p, vector<int> S) {
    ensureImpl(1 <= p && p <= n, "p must be between 1 and n");
    ensureImpl(S.size() > 0, "S must be nonempty");
    for (int i:S) ensureImpl(1 <= i && i <= n, "elements in S must be between 1 and n");
    int d = maxn;
    for (int i:S) {
        d = min(d, dis[p][i]); 
    }
    cost += 1;
    if (cost > max_cost) {
        WA("Too many queries\n");
    }
    return d;
}

int main() {
    cin >> n;
    vector<pair<int, int>> ans;
    for (int i = 0;i < n - 1;i++) {
        int u, v;
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
        ans.push_back({u, v});
    }
    for (int i = 1;i <= n;i++) {
        get_distances(i, 0, i);
    }
    vector<pair<int, int>> edges = treeguessr(n);
    ensureImpl((int)edges.size() == n-1, "invalid answer");
    printf("Accepted: %d\n", cost);
    for (auto [u, v]:edges) printf("%d %d\n", u, v);
    return 0;
}