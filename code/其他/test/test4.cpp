#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll inf = 1ll << 60;

int n;
vector<pair<ll, ll>> x; // x : (a, b)

void read() {
    cin >> n;
    x.resize(n);
    for (auto &[a, b] : x) {
        cin >> a >> b;
    }
    sort(x.begin(), x.end(), [&](const auto &a, const auto &b) {
        return a.second < b.second;
    });
}

template <class F>
vector<ll> monotone_maxima(F &f, int h, int w) {
    vector<ll> ret(h);
    auto sol = [&](auto &&self, const int l_i, const int r_i, const int l_j, const int r_j) -> void {
        const int m_i = (l_i + r_i) / 2;
        int max_j = l_j;
        ll max_val = -inf;
        for (int j = l_j; j <= r_j; ++j) {
            const ll v = f(m_i, j);
            if (v > max_val) {
                max_j = j;
                max_val = v;
            }
        }
        ret[m_i] = max_val;

        if (l_i <= m_i - 1) {
            self(self, l_i, m_i - 1, l_j, max_j);
        }
        if (m_i + 1 <= r_i) {
            self(self, m_i + 1, r_i, max_j, r_j);
        }
    };
    sol(sol, 0, h - 1, 0, w - 1);
    return ret;
}

vector<ll> max_plus_convolution(const vector<ll> &a, const vector<ll> &b) {
    const int n = (int)a.size(), m = (int)b.size();
    auto f = [&](int i, int j) {
        if (i < j or i - j >= m) {
            return -inf;
        }
        return a[j] + b[i - j];
    };

    return monotone_maxima(f, n + m - 1, n);
}

vector<ll> sol(const int l, const int r) {
    if (r - l == 1) {
        const vector<ll> ret = {-inf, x[l].first - x[l].second};
        return ret;
    }
    const int m = (l + r) / 2;
    const auto res_l = sol(l, m);
    const auto res_r = sol(m, r);

    vector<ll> sorted_l(m - l);
    for (int i = l; i < m; ++i) {
        sorted_l[i - l] = x[i].first;
    }
    sort(sorted_l.begin(), sorted_l.end(), greater());
    for (int i = 1; i < m - l; ++i) {
        sorted_l[i] += sorted_l[i - 1];
    }
    sorted_l.insert(sorted_l.begin(), -inf);

    auto res = max_plus_convolution(res_r, sorted_l);

    for (int i = 0; i < (int)res_l.size(); ++i) {
        res[i] = max(res[i], res_l[i]);
    }
    for (int i = 0; i < (int)res_r.size(); ++i) {
        res[i] = max(res[i], res_r[i]);
    }
    cout<<l<<" "<<r<<" ";
    for(int i=0;i<res.size();i++) cout<<res[i]<<' ';cout<<'\n';
    return res;
}

void process() {
    auto ans = sol(0, n);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read();
    process();
}
