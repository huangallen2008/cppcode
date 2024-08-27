//qwq QWQ
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
#ifdef LOCAL_
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
const int maxn=3e5+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
pii mn[maxb][maxn];
pii mx[maxb][maxn];
vector<int> a;
int n;
pii min(pii a,pii b) {
    if(a.f<b.f) return a;
    if(a.f>b.f) return b;
    else return {a.f,min(a.s,b.s)};
}
pii max(pii a,pii b) {
    if(a.f>b.f) return a;
    if(a.f<b.f) return b;
    else return {a.f,min(a.s,b.s)};
}
struct SEG {
    vector<pair<pii,pii>> s;
    int n;
    void pull(int w) {
        s[w].f=min(s[w<<1].f,s[w<<1|1].f);
        s[w].s=max(s[w<<1].s,s[w<<1|1].s);
    }
    void build(int w,int l,int r,vector<int> &a) {
        if(l==r) {
            s[w]={{a[l],l},{a[l],l}};
            return;
        }
        int m=l+r>>1;
        build(w<<1,l,m,a);
        build(w<<1|1,m+1,r,a);
        pull(w);
    }
    void init(int _n,vector<int>&a) {
        n=_n;
        s=vector<pair<pii,pii>>(n<<2);
        build(1,0,n-1,a);
    }
    void _ud(int w,int l,int r,int u,pair<pii,pii> v) {
        if(l==r) {
            s[w]=v;
            return;
        }
        int m=l+r>>1;
        if(u<=m) _ud(w<<1,l,m,u,v);
        else _ud(w<<1|1,m+1,r,u,v);
        pull(w);
    }
    void ud(int u,pii v) {
        _ud(1,0,n-1,u,{{v.f,u},{v.s,u}});
    }
    void del(int u) {
        ud(u,{inf,-inf});
    }
    pii _mn(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w].f;
        if(ql>r||qr<l) return {inf,0};
        int m=l+r>>1;
        return min(_mn(w<<1,l,m,ql,qr),_mn(w<<1|1,m+1,r,ql,qr));
    }
    pii mn(int l,int r) {
        return _mn(1,0,n-1,l,r);
    }
    pii _mx(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w].s;
        if(ql>r||qr<l) return {-inf,0};
        int m=l+r>>1;
        return max(_mx(w<<1,l,m,ql,qr),_mx(w<<1|1,m+1,r,ql,qr));
    }
    pii mx(int l,int r) {
        return _mx(1,0,n-1,l,r);
    }
}seg;
void solve() {
    cin>>n;
    vector<vector<int>> id(n);
    a=vector<int>(n);
    REP(i,n) cin>>a[i],a[i]--,id[a[i]].pb(i);
    seg.init(n,a);
    vector<int> las(n,-1);
    REP(i,n) las[a[i]]=i;
    vector<bool> isl(n);
    int cntd=0;
    REP(i,n) {
        if(las[i]!=-1) {
            isl[las[i]]=1;
            cntd++;
        }
    }
    int it=0;
    REP(i,n) if(isl[i]) {
        it=i;
        break;
    }
    int l=0;
    vector<int> an;
    vector<bool> used(n);//有沒有在vector<int> an裡面
    // oparr(las)
    REP1(rd,cntd) {
        ope(rd)
        if(rd&1) { 
            pii ret=seg.mx(l,it);
            // op(l)op(it)op(ret.f)ope(ret.s)
            l=ret.s+1;
            for(int &x:id[ret.f]) seg.del(x);
            an.pb(ret.f);
            used[ret.f]=1;
            if(it<n&&ret.f==a[it]) {
                it++;
                while(it<n&&(used[a[it]]||!isl[it])) it++;
            }
        }
        else {
            pii ret=seg.mn(l,it);
            op(l)op(it)op(ret.f)ope(ret.s)
            l=ret.s+1;
            for(int &x:id[ret.f]) seg.del(x);
            // if(used[ret.f]) {
            //     rd--;
            //     continue;
            // }
            an.pb(ret.f);
            used[ret.f]=1;
            if(it<n&&ret.f==a[it]) {
                it++;
                while(it<n&&(used[a[it]]||!isl[it])) it++;
            }
        }
    }
    cout<<an.size()<<'\n';
    for(int &x:an) cout<<x+1<<' ';
    cout<<'\n'; 
}
signed main() {
    IOS();
    int T=1;
    cin>>T;while(T--) 
    solve();
    return 0;
}