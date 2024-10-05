#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)((x).size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define Graphw vector<vector<pii>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int qur(int x,int y) {
    cout<<"? "<<x<<' '<<y<<'\n';
    cout.flush();
    int ret;
    cin>>ret;
    return ret;
}
// vector<vector<int>> rr;
// vector<int> r0,dep;
vector<bool> vis;
Graph g;
void find(int x) {
    int l=1,r=x;
    while(1) {
        int m=qur(l,r);
        if(l==m) {
            g[l].pb(r);
            vis[r]=1;
            break;
        }
        if(vis[m]) l=m;
        else r=m;
    }
}
void solve() {
    int n;
    cin>>n;
    g=Graph(n+1);
    vis=vector<bool>(n+1);
    vis[1]=1;
    REP1(i,n) {
        while(!vis[i]) {
            find(i);
        }
    }
    cout<<"! ";
    REP1(i,n) {
        for(int v:g[i]) cout<<i<<' '<<v<<' ';
    }
    cout<<'\n';
    cout.flush();
}
signed main() {
    IOS();
    int T=1;
    cin>>T;while(T--) 
    solve();
    return 0;
}