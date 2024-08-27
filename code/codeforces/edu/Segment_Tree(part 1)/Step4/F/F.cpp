#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
#define int long long
// #define ll long long
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
const int maxn=1e9+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
const int maxs=5e6+5;
struct Seg {
    int sum,mp;
    int len,t,l,r;
};
int n;
int node_id=2;
Seg s[maxs];
int slc[maxs],src[maxs];
int& lc(int w) {
    if(!slc[w]) {
        slc[w]=node_id++;
        s[slc[w]].sum=s[slc[w]].mp=s[slc[w]].t=0;
        s[slc[w]].len=s[w].len+1>>1;
    }
    return slc[w];
}
int& rc(int w) {
    if(!src[w]) {
        src[w]=node_id++;
        s[src[w]].sum=s[src[w]].mp=s[src[w]].t=0;
        s[src[w]].len=s[w].len>>1;
    }
    return src[w];
}
void init() {
    s[1].len=n+1;
    s[1].sum=s[1].mp=s[1].t=0;
}
struct SEG {
    void addtag(Seg &a,int t) {
        if(t==inf) return;
        a.sum=a.len*t;
        a.mp=max(0ll,a.sum);
        a.t=t;
    }
    void push(int w) {
        Seg &a=s[w],&b=s[lc(w)],&c=s[rc(w)];
        addtag(b,a.t);
        addtag(c,a.t);
        a.t=inf;
    }
    void pull(int w) {
        Seg &a=s[w],&b=s[lc(w)],&c=s[rc(w)];
        a.sum=b.sum+c.sum;
        a.mp=max(b.mp,b.sum+c.mp);
    }
    void _ud(int w,int l,int r,int ql,int qr,int v) {
        if(ql<=l&&r<=qr) {
            addtag(s[w],v);
            return;
        }
        if(ql>r||qr<l) return;
        push(w);
        int m=l+r>>1;
        _ud(lc(w),l,m,ql,qr,v);
        _ud(rc(w),m+1,r,ql,qr,v);
        pull(w);
    }
    void ud(int l,int r,int v) {
        _ud(1,0,n,l,r,v);
    }
    int _qu(int w,int l,int r,int h) {
        if(l==r) return l;
        push(w);
        int m=l+r>>1;
        if(s[lc(w)].mp>h) return _qu(lc(w),l,m,h);
        else return _qu(rc(w),m+1,r,h-s[lc(w)].sum);
    }
    int qu(int h) {
        return _qu(1,0,n,h);
    }
}seg;
signed main() {
    IOS();
    memset(slc,0,sizeof(slc));
    memset(src,0,sizeof(src));
    cin>>n;
    init();
    char opt;
    while(cin>>opt) {
        if(opt=='E') break;
        if(opt=='I') {
            int l,r,v;
            cin>>l>>r>>v;
            l--,r--;
            seg.ud(l,r,v);
        }
        if(opt=='Q') {
            int h;
            cin>>h;
            cout<<seg.qu(h)<<'\n';
        }
    }
    return 0;
}
