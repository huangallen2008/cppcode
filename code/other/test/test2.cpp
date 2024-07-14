#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mx = 1e5+5;

int n, m, k;
int gr[mx];
int c[mx];
int g[2][mx];
long long a[1<<23];
long long ans;

signed main() {
    cin >> n >> m >> k;
    for (int i=1;i<=n;i++) cin >> gr[i];
    int l = (k+1)/2, r = k-l;
    for (int i=1;i<=m;i++) {
        int u, v;
        cin >> u >> v;
        u = gr[u]; v = gr[v];
        if (u != v) {
            g[v>l][u] |= (1<<(v-l*(v>l)));
            g[u>l][v] |= (1<<(u-l*(u>l)));
        }
    }
    for (int i=1;i<=k;i++) cin >> c[i];
    if (n==1) {
        cout << c[1] << "\n";
        exit(0);
    }
//    int l = k, r = k-l;

    for (long long i=1;i<1LL<<l;i++) {
        int num = 0;
        for (int j=0;j<l;j++) {
            if (i&(1LL<<j)) num |= (1<<(j+1));
        }
        bool fl = 1;
        for (int j=1;j<=l;j++) {
            if (!(num & (1<<j))) continue;
            if (num & g[0][j]) {
                fl = 0;
                break;
            }
        }
        if (!fl) continue;
        else {
            a[i] = 0;
            for (int j=0;j<l;j++) {
                if (!(i & (1<<j))) continue;
                a[i] += c[j+1];
            }
            ans = max(a[i], ans);
        }
    }
    vector<long long> dp(1<<l);
    for(int i=0;i<1ll<<l;i++) dp[i]=a[i];
    for(int j=0;j<l;j++) {
        vector<long long> ndp(1<<l);
        for(int i=0;i<1ll<<l;i++) {
            if((i>>j)&1) {
                ndp[i]=max(dp[i^(1ll<<j)],dp[i]);
            }
            else ndp[i]=dp[i];
        }
        swap(dp,ndp);
    }
    for (int i=1;i<1<<r;i++) {
        int num = 0;
        for (int j=0;j<r;j++) {
            if (i&(1LL<<j)) num |= (1<<(j+1));
        }
        bool fl = 1;
        int mp = (1<<l) - 1;
        for (int j=1;j<=r;j++) {
            if (!(num & (1<<j))) continue;
            if (num & g[1][j+l]) {
                fl = 0;
                break;
            }
            mp &= ~(g[0][j+l]>>1);
        }
        if (!fl) continue;
        else {
            long long s = 0;
            for (int j=0;j<r;j++) {
                if (!(i & (1<<j))) continue;
                s += c[j+1+l];
            }
//            cout << i << " " << mp << " " << s << "\n";
            ans = max(s + dp[mp], ans);
        }
    }
    cout << ans << "\n";
}