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
            if(inc[u]) continue;
            int t=u;
            inc[v]=1;
            while(t!=v) {
                // ope(t)
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
int anb=0;
vector<pii> a;
void dfs2(int u,int fa) {
    vis[u]=1;
    ope(u)
    for(auto [v,id]:g[u]) {
        if(v==fa) continue;
        if(!inc[v]) continue;
        if(vis[v]) {
            if(fa==-1) continue;
            op(u)op(fa)op(v)op(dp[v])ope(dep[v])
            chmax(anb,dp[v]);
            a.pb({id,dep[v]});
            continue;;
        }
        op(u)ope(v)
            ope(v)ope(dp[v])ope(dep[v])
        chmax(anb,dp[v]);
        a.pb({id,dep[v]});
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
    int mx() { return a.size()?stk.back():0; }
};
struct myq {
    mys s1,s2;
    void push(int x) {
        s1.push(x);
    }
    int pop() {
        // for(int x:s1.a) cout<<x<<' ';
        // for(int x:s2.a) cout<<x<<' ';entr
        if(s2.size()) return s2.pop();
        else {
            while(s1.size()) s2.push(s1.pop());
            return s2.pop();
        }
    }
    int size() { return s1.size()+s2.size(); }
    int mx() { return size()?max(s1.mx(),s2.mx()):-inf; };
};
struct SEG {
    struct Seg {
        int mp,ms,ma;
    }zr={-inf,-inf,-inf};
    Seg merge(Seg b,Seg c) {
        Seg a;
        a.mp=max(b.mp,c.mp);
        a.ms=max(b.ms,c.ms);
        a.ma=max({b.ma,c.ma,b.mp+c.ms,b.ms+c.mp});
        return a;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a=merge(b,c);
    }
    vector<Seg> s;
    int n;
    void init(int _n) {
        n=_n;
        s=vector<Seg>(n<<2);
    }
    void _ud(int w,int l,int r,int u,pii v) {
        if(l==r) {
            s[w].mp=v.f;
            s[w].ms=v.s;
            return;
        }
        int m=l+r>>1;
        if(u<=m) _ud(w<<1,l,m,u,v);
        else _ud(w<<1|1,m+1,r,u,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void ud(int u,pii v) {
        _ud(1,0,n-1,u,v);
    }
    Seg _qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return zr;
        int m=l+r>>1;
        return merge(_qu(w<<1,l,m,ql,qr),_qu(w<<1|1,m+1,r,ql,qr));
    }
    int qu(int l,int r) {
        return _qu(1,0,n-1,l,r).ma;
    }
}seg;
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
    seg.init(n2);
    REP(i,n2) seg.ud(i,{p[i],s[i]});
    // REP(i,nn<<1) cout<<a[i].s<<' ';entr
    oparr(p)oparr(s)
    myq qp,qs;
    REP(i,nn) {
        qp.push(p[i]);
        qs.push(s[i]);
    }
    Vi an(n,-1);
    // int an=0;
    // an[a[0].f]=qp.mx()+qs.mx()-n2;
    //     op(qp.mx())ope(qs.mx())
    for(int i=nn;i<n2;i++) {
        // qp.pop(),qs.pop();
        // qp.push(p[i]),qs.push(s[i]);
        // op(qp.mx())ope(qs.mx())
        // an[a[i-nn+1].f]=qp.mx()+qs.mx()-n2;
        an[a[i-nn].f]=seg.qu(i-nn,i-1)-n2;
        ope(seg.qu(i-nn,i-1))
    }
    REP(i,n) if(an[i]!=-1) chmax(an[i],anb);
    REP(i,n) cout<<an[i]<<' ';cout<<'\n';
    // cout<<an<<'\n';
    return 0;
}