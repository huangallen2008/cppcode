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
const int mod=1e9+7;
const int maxn=1e5+5;
const int maxv=4e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
void solve() {
    int n;
    cin>>n;
    vector<int> deg(n);
    REP(i,n) cin>>deg[i];
    int sum=0;
    REP(i,n) sum+=deg[i];
    if(sum!=(n-1)<<1) {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    queue<int> d1;
    vector<int>dn1;
    REP(i,n) {
        if(deg[i]==1) d1.push(i);
        else dn1.pb(i);
    }
    vector<pii> edges;
    REP(rd,n-2) {
        int u=d1.front();
        d1.pop();
        int v=dn1.back();
        deg[v]--;
        if(deg[v]==1) {
            dn1.pop_back();
            d1.push(v);
        }
        edges.pb({u,v});
    }
    int u=d1.front();d1.pop();
    int v=d1.front();
    edges.pb({u,v});
    cout<<edges.size()<<'\n';
    for(auto [x,y]:edges) cout<<x+1<<' '<<y+1<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
