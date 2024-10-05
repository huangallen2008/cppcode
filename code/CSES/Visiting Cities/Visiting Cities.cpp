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
const int maxn=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
const int mod=rd(1e9,3e9);
//shuffle(a,a+n,rng)
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<vector<pii>> g(n);
    REP(i,m) {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        g[u].pb({v,w});
    }
    vector<int> dis(n,inf);
    dis[0]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,0});
    while(pq.size()) {
        auto [tt,u]=pq.top();
        pq.pop();
        for(auto &[v,d]:g[u]) {
            if(dis[v]>dis[u]+d) {
                dis[v]=dis[u]+d;
                pq.push({dis[v],v});
            }
        }
    }
    Graph ng(n),ngb(n);
    vector<int> ind(n);
    REP(u,n) {
        for(auto &[v,d]:g[u]) {
            if(dis[v]==dis[u]+d) {
                ng[u].pb(v);
                ngb[v].pb(u);
                ind[v]++;
            }
        }
    }
    vector<int> pn(n),sn(n),tps;
    pn[0]=1,sn[n-1]=1;
    queue<int> q;
    REP(i,n) if(ind[i]==0) q.push(i);
    while(q.size()) {
        int u=q.front();
        q.pop();
        tps.pb(u);
        for(int &v:ng[u]) {
            ind[v]--;
            if(ind[v]==0) q.push(v);
        }
    }
    REP(i,n) {
        int &u=tps[i];
        for(int &v:ngb[u]) {
            pn[u]=md(pn[u]+pn[v]);
        }
    }
    RREP(i,n) {
        int &u=tps[i];
        for(int &v:ng[u]) {
            sn[u]=md(sn[u]+sn[v]);
        }
    }
    int &c=pn[n-1];
    vector<int> an;
    REP(i,n) if(md(sn[i]*pn[i])==c) an.pb(i);
    cout<<an.size()<<'\n';
    for(int &x:an) cout<<x+1<<' ';
    cout<<'\n';
    return 0;
}
