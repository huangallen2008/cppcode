#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2", "bmi", "bmi2", "lzcnt", "popcnt")

#include <bits/stdc++.h>
using namespace std;

#define int long long

constexpr int MAX = 1e15;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int> > edges(n + 1);
    for (int i = n - 1; i--;) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<array<int, 3> > dp(n + 1);

    auto dfs = [&](auto &&self, int now, int last)-> void {
        {
            for (int next: edges[now]) {
                if (next == last) continue;
                self(self, next, now);
            }
        } {
            dp[now][0] = 1;
            for (int next: edges[now]) {
                if (next == last) continue;
                dp[now][0] += min(dp[next][1], dp[next][2]);
            }
        } {
            vector<int> tmp;
            for (int next: edges[now]) {
                if (next == last) continue;
                tmp.push_back(min(dp[next][2] + 1, dp[next][1]) - dp[next][0]);
                dp[now][1] += dp[next][0];
            }
            if (tmp.empty()) dp[now][1] = MAX;
            else {
                sort(tmp.begin(), tmp.end());
                int cnt = 0;
                for (int x: tmp) if (cnt == 0 || x <= 0) dp[now][1] += x, cnt++;
                dp[now][1] -= (cnt - 1) / 2;
            }
        } {
            vector<int> tmp;
            for (int next: edges[now]) {
                if (next == last) continue;
                tmp.push_back(min(dp[next][2] + 1, dp[next][1]) - dp[next][0]);
                dp[now][2] += dp[next][0];
            }
            sort(tmp.begin(), tmp.end());
            int cnt = 0;
            for (int i = 0; i + 1 < tmp.size(); i += 2)
                if (tmp[i] + tmp[i + 1] <= 0) dp[now][2] += tmp[i] + tmp[i + 1], cnt++;
            dp[now][2] -= cnt;
        }
    };

    dfs(dfs, 1, 0);
    cout << min({dp[1][0], dp[1][1], dp[1][2]}) << '\n';

    return 0;
}