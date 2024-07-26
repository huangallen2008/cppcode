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
struct edge {
    int u,v;
};
struct DSU {
    vector<int> p,sz;
    vector<pii> stk;
    int n,cc;
    void init(int _n) {
        n=_n;
        p=vector<int>(n);
        sz=vector<int>(n,1);
        REP(i,n) p[i]=i;
        cc=n;
    }
    int find(int u) {
        return p[u]==u?u:find(p[u]);
    }
    void merge(int a,int b) {
        int x=find(a),y=find(b);
        if(x==y) return;
        if(sz[x]>sz[y]) swap(x,y);
        stk.pb({x,y});
        p[x]=y;
        sz[y]+=sz[x];
        cc--;
    }
    void merge(edge e) {
        merge(e.u,e.v);
    }
    void save() {
        stk.pb({-1,-1});
    }
    void revert() {
        while(stk.size()&&stk.back().f!=-1) {
            auto [x,y]=stk.back();
            stk.pop_back();
            p[x]=x;
            sz[y]-=sz[x];
            cc++;
        }
        stk.pop_back();
    }
}dsu_sm,dsu;
vector<edge> e;
int sn;
struct qur {
    int l,r,id;
};
bool so_qur(qur a,qur b) {
    int x=a.l/sn,y=b.l/sn;
    return x==y?a.r<b.r:x<y;
}
int getan(int l,int r) {
    dsu_sm.save();
    for(int i=l;i<=r;i++) dsu_sm.merge(e[i]);
    int an=dsu_sm.cc;
    dsu_sm.revert();
    return an;
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    sn=sqrt(n);
    dsu_sm.init(n);
    dsu.init(n);
    e=vector<edge>(m);
    REP(i,m) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        e[i]={u,v};
    }
    int k;
    cin>>k;
    vector<qur> q(k);
    vector<int> an(k);
    REP(i,k) {
        int l,r;
        cin>>l>>r;
        l--,r--;
        q[i]={l,r,i};
    }
    sort(ALL(q),so_qur);
    vector<int> t(k);
    REP(i,k) t[i]=q[i].l/sn;
    REP(i,k) {
        auto [l,r,id]=q[i];
        int L=t[i]*sn,R=(t[i]+1)*sn;
        if(i>0&&t[i]!=t[i-1]) dsu.init(n);
        if(r<R) an[id]=getan(l,r);
        else {
            int st;
            if(i>0&&t[i]==t[i-1]&&q[i-1].r>=R) st=q[i-1].r+1;
            else st=R+1;
            for(int j=st;j<=r;j++) dsu.merge(e[j]);
            dsu.save();
            for(int j=R;j>=l;j--) dsu.merge(e[j]);
            an[id]=dsu.cc;
            dsu.revert();
        }
    }
    REP(i,k) cout<<an[i]<<'\n';
    return 0;
}