#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define int ll
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) for (int i = (n)-1; i >= 0; i--)
#define RREP1(i, n) for (int i = (n); i >= 1; i--)
#define REP1(i, n) FOR(i, 1, n+1)
#define pii pair<int, int>
#define ppi pair<pii, int>
#define pip pair<int, pii>
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)((x).size())
#define endl '\n'
#define IOS() ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

const ll maxn = 1005;
const ll mod = 998244353;
const ll inf = (1ll<<60);

ll pw(ll x, ll p, ll m){
    ll ret = 1;
    while(p > 0){
        if (p & 1){
            ret *= x;
            ret %= m;
        }
        x *= x;
        x %= m;
        p >>= 1;
    }
    return ret;
}
ll inv(ll x, ll m){
    return pw(x, m-2, m);
}

int n, m, k;

char arr[maxn][maxn];
int smr[maxn], smc[maxn];
int smt = 0;
vector<int> A, B;

int mp[maxn][maxn];
bool check(int a, int b){
    A.clear(); B.clear();
    if (a >= n || b >= m) return 0;
    int ndr = smt / (a+1), ndc = smt / (b+1), ndcell = smt / ((a+1)*(b+1));

    int cur = 0;
    REP1(i, n){
        cur += smr[i];
        if (cur > ndr) return 0;
        if (cur == ndr && SZ(A) < a){
            A.pb(i);
            cur = 0;
        }
    }
    if (cur != ndr) return 0;
    A.pb(n);

    cur = 0;
    REP1(i, m){
        cur += smc[i];
        if (cur > ndc) return 0;
        if (cur == ndc && SZ(B) < b){
            B.pb(i);
            cur = 0;
        }
    }
    if (cur != ndc) return 0;
    B.pb(m);

    REP(i, SZ(A)) REP(j, SZ(B)) mp[i][j] = 0;

    int Aptr = 0;
    REP1(i, n){
        int Bptr = 0;
        REP1(j, m){
            mp[Aptr][Bptr] += (arr[i][j] == '0');
            if (B[Bptr] == j) Bptr++;
        }
        if (A[Aptr] == i) Aptr++;
    }

    REP(i, SZ(A)) REP(j, SZ(B)) if (mp[i][j] != ndcell) return 0;
    return 1;
}
signed main(){
    IOS();
    int T; cin>>T;
    while(T--){
        cin>>n>>m>>k;
        REP1(i, n) smr[i] = 0;
        REP1(i, m) smc[i] = 0;

        smt = 0;
        REP1(i, n){
            REP1(j, m){
                cin>>arr[i][j];
                smr[i] += (arr[i][j] == '0');
                smc[j] += (arr[i][j] == '0');
                smt += (arr[i][j] == '0');
            }
        }

        vector<vector<int>> cands;
        for (int pa = k; pa >= 0; pa--){
            int pb = k-pa;
            if (smt % ((pa+1)*(pb+1)) != 0) continue;
            if (check(pa, pb)){
                vector<int> tmp;
                REP(i, pa){
                    tmp.pb(A[i]);
                }
                REP(i, pb){
                    tmp.pb(B[i]+n-1);
                }
                cands.pb(tmp);
            }
        }

        sort(ALL(cands));
        if (SZ(cands) == 0){
            cout<<"Impossible"<<endl;
        }
        else {
            REP(i, k) cout<<cands[0][i]<<' ';
            cout<<endl;
        }
    }

}