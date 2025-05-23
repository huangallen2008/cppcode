#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
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
#define Vpii vector<pii>
#ifdef LOCAL_
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) {cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;}
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
template<typename T1,typename T2>
istream& operator>>(istream& os,pair<T1,T2> &p) { return os>>p.f>>p.s; }
template<typename S>
ostream& operator<<(ostream& os,vector<S> p) { for(auto allen:p) os<<allen<<' ';return os<<'\n'; }
template<typename S>
istream& operator>>(istream& os,vector<S> &p) { for(auto &allen:p) os>>allen;return os; }
template<typename T1,typename T2>
pair<T1,T2> operator+(pair<T1,T2> p1,pair<T1,T2> p2) { return pair<T1,T2>(p1.f+p2.f,p1.s+p2.s); }
const int mod=998244353;
const int maxn=5;
const int maxb=25;
const int inf=(1ll<<60);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<Vi> st(maxb,Vi(n));
    Graphw g(n);
    REP(i,m) {
        int u,v,w;
        cin>>u>>v>>w,u--,v--;
        g[u].pb({v,w});
        // g[v].pb({u,w});
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,0});
    Vi dis(n,inf);
    Vi vis(n);  
    dis[0]=0;
    while(pq.size()) {
        int u=pq.top().s;
        op(u)ope(dis[u])
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [v,w]:g[u]) {
            op(u)ope(v)
            if(dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                op(u)op(v)op(w)ope(dis[v])
                pq.push({dis[v],v});
            }
        }
    }
    oparr(dis)
    Graph ng(n);
    Graph ngb(n);
    Vi deg(n);
    REP(i,n) {
        for(auto [v,w]:g[i]) {
            if(dis[v]==dis[i]+w) {
                // op(i)op(v)ope(w)
                ng[i].pb(v),deg[v]++;
                ngb[v].pb(i);
            }
        }
    }
    Vi tps;
    queue<int> q;
    // REP(i,n) {
        // if(deg[i]==0) q.push(i);
    // }
    q.push(0);
    // op(ngb)
    while(q.size()) {
        int u=q.front();
        q.pop();
        tps.pb(u);
        for(auto v:ng[u]) {
            if(--deg[v]==0) {
                q.push(v);
            }
        }
    }
    oparr(tps)
    Vi nok(n);
    REP(i,n) if(ngb[i].size()>1) nok[i]=1;
    int nn=tps.size();
    Vi dp(n),dep(n);
    auto glca=[&](int a,int b) {
        // op(a)op(b)
        if(dep[a]>dep[b]) swap(a,b);
        int cc=dep[b]-dep[a];
        REP(i,maxb) if(cc>>i&1) b=st[i][b];
        RREP(i,maxb) {
            if(st[i][a]!=st[i][b]) {
                a=st[i][a],b=st[i][b];
            }
        }
        if(a!=b) a=st[0][a];
        // ope(a)
        return a;
    };
    REP(i,nn) {
        int u=tps[i];
        if(u==0||dis[u]==inf) continue;
        int lca=-1;
        for(int x:ngb[u]) {
            // op(u)ope(x)
            if(lca!=-1)lca=glca(lca,x);
            else lca=x;
            // dp[u]=dp[x]+1;
            // op(u)ope(x)
        }
        op(u)ope(lca)
        dp[u]=dp[lca]+(!nok[i]);
        dep[u]=dep[lca]+1;
        //lca
        st[0][u]=lca;
        REP1(j,maxb-1) st[j][u]=st[j-1][st[j-1][u]];
    }
    REP(i,n) {
        if(dis[i]==inf) cout<<"-1 ";
        else {
            cout<<dp[i]<<' ';
        }
    }
    cout<<'\n';
    return 0;
}
/*
6 7
1 2 1
2 3 1
2 4 1
3 5 1
4 5 1
5 6 1
3 6 2
*/