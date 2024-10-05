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
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    struct Seg {
        int sum=0,wsum=0,len,l,t;
    };
    void addtag(Seg &a,int t) {
        a.sum+=t*a.len;
        a.wsum+=t*(a.len*((a.l<<1)+a.len-1)>>1);
        a.t+=t;
    }
    void push(Seg &a,Seg &b,Seg &c) {
        addtag(b,a.t);
        addtag(c,a.t);
        a.t=0;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a.sum=b.sum+c.sum;
        a.wsum=b.wsum+c.wsum;
    }
    int n;
    vector<Seg> s;
    void build(int w,int l,int r,vector<int> &a) {
        if(l==r) {
            s[w]={a[l],a[l]*l,1,l,0};
            return;
        }
        s[w].len=r-l+1;
        s[w].l=l;
        int m=l+r>>1;
        build(w<<1,l,m,a);
        build(w<<1|1,m+1,r,a);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void init(int _n,vector<int> a) {
        n=_n;
        s=vector<Seg>(n<<2);
        build(1,0,n-1,a);
    }
    void _add(int w,int l,int r,int ql,int qr,int v) {
        if(ql<=l&&r<=qr) {
            addtag(s[w],v);
            return;
        }
        if(ql>r||qr<l) return;
        push(s[w],s[w<<1],s[w<<1|1]);
        int m=l+r>>1;
        _add(w<<1,l,m,ql,qr,v);
        _add(w<<1|1,m+1,r,ql,qr,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void add(int l,int r,int v) {
        _add(1,0,n-1,l,r,v);
    }
    int _sum(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w].wsum-(ql-1)*s[w].sum;
        if(ql>r||qr<l) return 0;
        push(s[w],s[w<<1],s[w<<1|1]);
        int m=l+r>>1;
        return _sum(w<<1,l,m,ql,qr)+_sum(w<<1|1,m+1,r,ql,qr);
    }
    int sum(int l,int r) {
        return _sum(1,0,n-1,l,r);
    }
}seg;
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    seg.init(n,a);
    REP(i,q) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int l,r,v;
            cin>>l>>r>>v;
            l--,r--;
            seg.add(l,r,v);
        }
        else {
            int l,r;
            cin>>l>>r;
            l--,r--;
            cout<<seg.sum(l,r)<<'\n';
        }
    }
    return 0;
}