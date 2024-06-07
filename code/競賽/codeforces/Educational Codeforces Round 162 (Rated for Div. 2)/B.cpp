#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#ifdef LOCAL
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=998244353;
const int maxn=2e6+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
bool so(pii a,pii b) {
    return abs(a.s)>abs(b.s);
}
void solve() {
    int n,k;
    cin>>n>>k;
    vector<pii> m(n);
    REP(i,n) cin>>m[i].f;
    REP(i,n) cin>>m[i].s;
    sort(ALL(m),so);
    int it=n-1,go=0;
    while(it>=0) {
        int rest=k;
        while(it>=0&&rest>0) {
            if(m[it].f<=rest) {
                rest-=m[it].f;
                it--;
            }
            else {
                m[it].f-=rest;
                break;
            }
//            op(go)op(rest)ope(it)
        }
        if(it<0) {
            cout<<"YES\n";
            return;
        }
        go++;
        if(abs(m[it].s)<=go) {
            cout<<"NO\n";
            return;
        }
//        op(go)ope(it)
    }
    cout<<"YES\n";
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
