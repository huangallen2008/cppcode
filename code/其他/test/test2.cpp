#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

const int MAGIC = 8e7;

int main() {
    freopen("in.txt","r",stdin);
    int n, m;
    cin >> n >> m;
    vector <vector <int>> adj(n + 1);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (adj[1].empty()) {
        cout << "No\n";
        return 0;
    }

    bool found = false;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int s = 1;

    for (int j = 0; j < MAGIC; ++j) {
        s = adj[s][rng() % (int)adj[s].size()];
        if (s == n) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
