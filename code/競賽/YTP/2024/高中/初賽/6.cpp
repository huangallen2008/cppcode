
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
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
const int maxn=1e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,k;
Graph g;
vector<int> a,v;
void dfs(int u,int p) {
    a.pb(v[u]);
    for(auto v:g[u]) {
        if(v==p) continue;
        dfs(v,u);
    }
};
struct P {
    int val,l,r;
};
struct so {
    bool operator()(P a,P b) {
        return a.val>b.val;
    }
};
signed main() {
    IOS();
    cin>>n>>k;
    a={0};
    g=Graph(n);
    v=vector<int>(n);
    REP(i,n) cin>>v[i];
    vector<int> deg(n);
    REP(i,n-1) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++,deg[v]++;
    }
    int st=0;
    REP(i,n) if(deg[i]==1) st=i;
    dfs(st,-1);
    REP1(i,n) a[i]+=a[i-1];
    priority_queue<P,vector<P>,so> pq;
    REP(i,n) pq.push({a[i+1]-a[i],i,i+1});
    while(k--) {
        if(pq.size()==0) {
            cout<<"-1\n";
            return 0;
        }
        auto [val,l,r]=pq.top();
        if(k==0) {
            cout<<val<<'\n';
            return 0;
        }
        pq.pop();
        if(r<n) {
            val=val-a[r]+a[r+1];
            pq.push({val,l,r+1});
        }
    }
    return 0;
}