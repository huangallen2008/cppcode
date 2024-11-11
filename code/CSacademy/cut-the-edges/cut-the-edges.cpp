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
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n;
Graphw g;
Vi vis,pre,inc,lev,dep,dp;
void dfs(int u,int fa) {
    vis[u]=1;
    for(auto [v,id]:g[u]) {
        if(v==fa) continue;
        if(vis[v]) {
            int t=u;
            inc[v]=1;
            while(t!=v) {
                inc[t]=1;
                t=pre[t];
            }
            continue;;
        }
        pre[v]=u;
        dfs(v,u);
    }
}
void dfs1(int u,int fa) {
    int mx=0,mx2=0;
    for(auto [v,id]:g[u]) {
        if(v==fa) continue;
        if(inc[v]) continue;
        lev[v]=lev[u]+1;
        dfs1(v,u);
        chmax(dep[u],dep[v]+1);
        chmax(dp[u],dp[v]);
        int dv=dep[v]+1;
        if(dv+1>mx) {
            mx2=mx;
            mx=dv;
        }
        else if(dv>mx2) mx2=dv;
    }
    chmax(dp[u],mx+mx2);
}
vector<pii> a;
void dfs2(int u,int fa) {
    vis[u]=1;
    for(auto [v,id]:g[u]) {
        if(v==fa) continue;
        if(!inc[v]) continue;
        if(vis[v]) {
            a.pb({id,dp[v]});
            continue;
        }
        a.pb({id,dp[v]});
        dfs2(v,u);
    }
}
struct mys {
    Vi stk,a;
    void push(int x) {
        if(a.size()) {
            stk.pb(max(stk.back(),x));
        }
        else stk.pb(x);
        a.pb(x);
    }
    int pop() {
        int val=a.back();
        stk.pop_back();
        a.pop_back();
        return val;
    }
    int size() { return a.size(); }
    int mx() { return a.size()?stk.size():0; }
};
struct myq {
    mys s1,s2;
    void push(int x) {
        s1.push(x);
    }
    int pop() {
        if(s2.size()) return s2.pop();
        else {
            while(s1.size()) s2.push(s1.pop());
            return s2.pop();
        }
    }
    int size() { return s1.size()+s2.size(); }
    int mx() { return size()?-inf:max(s1.mx(),s2.mx()); };
};
signed main() {
    IOS(); 
    cin>>n;
    g=Graphw(n);
    lev=dep=dp=vis=inc=pre=Vi(n);
    REP(i,n) {
        int u,v;
        cin>>u>>v,u--,v--;
        g[u].pb({v,i});
        g[v].pb({u,i});
    }
    dfs(0,-1);
    ope("ok")
    REP(i,n) if(inc[i]) dfs1(i,-1);
    int id=-1;
    REP(i,n) if(inc[i]) id=i;
    vis=Vi(n);  
    dfs2(id,-1);
    int nn=a.size();
    REP(i,nn) a.pb(a[i]);
    int n2=nn<<1;
    Vi p(n2),s(n2);
    REP(i,n2) {
        p[i]=i+a[i].s;
        s[i]=n2-i+a[i].s;
    }
    myq qp,qs;
    REP(i,nn) {
        qp.push(p[i]);
        qs.push(s[i]);
    }
    int an=0;
    chmax(an,qp.mx()+qs.mx());
    for(int i=nn;i<n2;i++) {
        qp.pop(),qs.pop();
        qp.push(p[i]),qs.push(s[i]);
        chmax(an,qp.mx()+qs.mx());
    }
    cout<<an<<'\n';
    return 0;
}