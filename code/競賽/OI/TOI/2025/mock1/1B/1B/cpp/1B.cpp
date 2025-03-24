#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define pb push_back
#define pii pair<int,int>
#define Vi vector<int>
#define Vpii vector<pii>
#define f first 
#define s second 
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)((x).size()))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define Graph vector<Vi>
#define Graphw vector<Vpii>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#ifdef LOCAL
#define op(x) cerr<<(#x)<<"="<<(x)<<", ";
#define ope(x) cerr<<(#x)<<"="<<(x)<<endl;
#define oparr(x) {for(auto allen:(x)) cerr<<(allen)<<' ';cout<<endl;}
#define entr cout<<endl;
#else 
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename S,typename T> 
ostream& operator<<(ostream& os,pair<S,T> p) {
    return os<<'{'<<p.first<<','<<p.s<<"}";
}
template<typename S> 
ostream& operator<<(ostream& os,vector<S> p) {
    for(auto x:p) os<<x<<' ';
    os<<'\n';
    return os;
}
const int inf=(1ll<<60);
std::vector<long long> compute_defense(signed _N,const std::vector<signed> &C,const std::vector<signed> &U,const std::vector<signed> &V,const std::vector<signed> &W) {
    int n=_N;
    int m=SZ(U);
    Vi c(n+1);
    REP(i,n) c[i+1]=C[i]-1;
    Graphw g(n+1);
    Vi an(n);
    REP(i,m) {
        g[U[i]].pb({V[i],W[i]});
        g[V[i]].pb({U[i],W[i]});
        if(c[U[i]]!=c[V[i]]) {
            g[0].pb({U[i],W[i]});
            g[0].pb({V[i],W[i]});
        }
    }
    Vi vis(n+1),dis(n+1,inf);
    priority_queue<pii,Vpii,greater<pii>> pq;
    pq.push({0,0});
    dis[0]=0;
    while(pq.size()) {
        auto [dd,u]=pq.top();
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [v,w]:g[u]) {
            if(dis[u]+w<dis[v]) {
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
    REP(i,n) an[i]=dis[i+1];
    return an;
}
