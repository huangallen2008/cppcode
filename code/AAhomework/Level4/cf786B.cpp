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
//const int mod=1e9+7;
const int maxn=1e5+5;
const int inf=(1ll<<62);
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//int rd(int l,int r) {
//    return uniform_int_distribution<int>(l,r)(rng);
//}
////shuffle(a,a+n,rng)
struct SEG {
    int node_id,n,N;
    vector<vector<pii>> g;
    vector<int> in_id,out_id,dis;
    vector<bool> vis;
//    priority_queue<pii,vector<pii>,greater<pii>> pq;
    void build(int w,int l,int r) {
        if(l==r) {
            in_id[w]=l;
            out_id[w]=l;
            return;
        }
        in_id[w]=node_id++;
        out_id[w]=node_id++;
        int m=(l+r)>>1;
        build(w<<1,l,m);
        build(w<<1|1,m+1,r);
        g[in_id[w<<1]].pb({in_id[w],0});
        g[in_id[w<<1|1]].pb({in_id[w],0});
        g[out_id[w]].pb({out_id[w<<1],0});
        g[out_id[w]].pb({out_id[w<<1|1],0});
    }
    void init(int &_n,int &q) {
        n=_n;
        int n4=n<<2;
        N=(n4)+(n)+(q<<1);
        g=vector<vector<pii>>(N);
        in_id=vector<int>(n4);
        out_id=vector<int>(n4);
        node_id=n;
        build(1,0,n-1);
    }
    void ins_in(int w,int l,int r,int ll,int rr,int u) {
        if(ll<=l&&r<=rr) {
            g[in_id[w]].pb({u,0});
            return;
        }
        if(ll>r||rr<l) return;
        int m=(l+r)>>1;
        ins_in(w<<1,l,m,ll,rr,u);
        ins_in(w<<1|1,m+1,r,ll,rr,u);
    }
    void ins_out(int w,int l,int r,int ll,int rr,int u) {
        if(ll<=l&&r<=rr) {
            g[u].pb({out_id[w],0});
            return;
        }
        if(ll>r||rr<l) return;
        int m=(l+r)>>1;
        ins_out(w<<1,l,m,ll,rr,u);
        ins_out(w<<1|1,m+1,r,ll,rr,u);
    }
    void add_edges(int ul,int ur,int vl,int vr,int w) {
        g[node_id].pb({node_id+1,w});
        ins_in(1,0,n-1,ul,ur,node_id++);
        ins_out(1,0,n-1,vl,vr,node_id++);
    }
    void dijk(int &s) {
        dis=vector<int>(N,inf);
        vis=vector<bool>(N);
        dis[s]=0;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
//        while(pq.size()) pq.pop();//clear pq
        pq.push({dis[s],s});
        while(pq.size()) {
            auto [tt,u]=pq.top();
            pq.pop();
            if(vis[u]) continue;
            vis[u]=1;
            for(auto &[v,d]:g[u]) {
                if(dis[v]<=dis[u]+d) continue;
                dis[v]=dis[u]+d;
                pq.push({dis[v],v});
            }
        }
    }
    int get_dis(int &u) {
        if(dis[u]==inf) return -1;
        return dis[u];
    }
} seg;
signed main() {
    IOS();
    int n,q,s;
    cin>>n>>q>>s;
    s--;
    seg.init(n,q);
    REP(i,q) {
        int ty;
        cin>>ty;
        if(ty==1) {
            int v,u,w;
            cin>>v>>u>>w;
            v--,u--;
            seg.add_edges(v,v,u,u,w);
        }
        if(ty==2) {
            int v,l,r,w;
            cin>>v>>l>>r>>w;
            v--,l--,r--;
            seg.add_edges(v,v,l,r,w);
        }
        if(ty==3) {
            int v,l,r,w;
            cin>>v>>l>>r>>w;
            v--,l--,r--;
            seg.add_edges(l,r,v,v,w);
        }
    }
    seg.dijk(s);
    REP(i,n) cout<<seg.get_dis(i)<<' ';
    cout<<'\n';
    return 0;
}
