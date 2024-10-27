#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
#define Vi vector<int>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e5+5;
const int maxb=20;
const int inf=(1ll<<62); 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) r=r*x%mod;
        x=x*x%mod;
        p>>=1;
    }
    return r;
}
int n;
Graph g;
Vi inc,a,dep,vis;
int dfs1(int u,int fa,int ori) {
    vis[u]=1;
    int ret=-1;
    for(int v:g[u]) {
        if(v==fa) continue;
        if(v==ori) {
            inc[u]=1;
            ret=1;
            continue;
        }
        int rr=dfs1(v,u,ori);
        if(rr!=-1) ret=rr+1;
        if(inc[v])inc[u]=1;
    }
    return ret;
}
void dfs2(int u,int fa,int ori) {
    vis[u]=1;
    if(inc[u]) dep[u]=0;
    for(int v:g[u]) {
        if(v==fa||v==ori) continue;
        dep[v]=dep[u]+1;
        dfs2(v,u,ori);
    }
}
Vi lpf(maxn);
void init_lpf() {
    lpf[0]=lpf[1]=1;
    for(int i=2;i<maxn;i++) {
        if(!lpf[i]) {
            for(int j=i;j<maxn;j+=i) {
                if(!lpf[j]) lpf[j]=i;
            }
        }
    }
}
signed main() {
    IOS(); 
    init_lpf();
    cin>>n;
    g=Graph(n);
    inc=a=vis=dep=Vi(n);
    REP(i,n) {
        cin>>a[i],a[i]--;
        g[a[i]].pb(i);
    }
    Vi t;
    REP(i,n) if(!vis[i]) t.pb(dfs1(i,-1,i));
    vis=Vi(n);
    REP(i,n) if(inc[i]&&!vis[i])  {
        dfs2(i,-1,i);
    }
    int mxd=0;
    REP(i,n) chmax(mxd,dep[i]);
    unordered_map<int,int> lcm;
    REP(i,t.size()) {
        if(t[i]<=1) continue;
        int tt=0,r=1;
        unordered_map<int,int> mp;
        while(!mp[r]) {
            ope(r)
            mp[r]=1;
            r=r*2%t[i];
            tt++;
        }
        while(tt>1) {
            int f=lpf[tt];
            int cnt=0;
            while(tt%f==0) {
                tt/=f;
                cnt++;
            }
            chmax(lcm[f],cnt);
        }
    }
    int an=1;
    for(auto [x,y]:lcm) {
        an=an*pw(x,y)%mod;
    }
    an=(an+(mxd>1?__lg(mxd-1)+1:mxd))%mod;
    cout<<an<<'\n';
    return 0;
}