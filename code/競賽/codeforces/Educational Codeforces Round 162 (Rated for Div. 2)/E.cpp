#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
//#define int long long
#define ll long long
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
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
vector<int> g[maxn],qu;
int c[maxn],d[maxn],k[maxn],id[maxn];
int n;
ll ans=0;
void dfs(int u,int p) {
    qu.pb(u);
    int fir_idcu=id[c[u]];
    if(id[c[u]]!=-1) d[qu[id[c[u]]+1]]++;
    else if(p!=-1) k[c[u]]++;
    id[c[u]]=qu.size()-1;
    for(int &v:g[u]) {
        if(v==p) continue;
        dfs(v,u);
        ans+=(d[v]*(ll)(d[v]+1))>>1;
    }
    id[c[u]]=fir_idcu;
    qu.pop_back();
}
void solve() {
    cin>>n;
    ans=0;
    qu.clear();
    REP(i,n) {
        g[i].clear();
        d[i]=0,c[i]=0,k[i]=0,id[i]=-1;
    }
    REP(i,n) {
        cin>>c[i];
        c[i]--;
    }
    REP(i,n-1) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,-1);
    REP(i,n) ans+=(k[i]*(ll)(k[i]-1))>>1;
    cout<<ans<<'\n';
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
