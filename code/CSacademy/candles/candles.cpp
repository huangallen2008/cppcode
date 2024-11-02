#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("Ofast,unroll-loops,fast-math")
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
#define ALL1(x) (x).begin()+1,(x).end()
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
const int maxn=1e5+5;
const int maxn2=2e5+5;
const int maxb=19;
const int inf=(1ll<<62); 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    struct Seg {
        int mn,t;
    };
    vector<Seg> s;
    int n;
    void addtag(Seg &a,int t) {
        a.mn+=t;
        a.t+=t;
    }
    void push(Seg &a,Seg &b,Seg &c) {
        addtag(b,a.t);
        addtag(c,a.t);
        a.t=0;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a.mn=min(b.mn,c.mn);
    }
    void build(int w,int l,int r,Vi &a) {
        if(l==r) {
            s[w]={a[l],0};
            return;
        }
        int m=l+r>>1;
        build(w<<1,l,m,a);
        build(w<<1|1,m+1,r,a);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void init(int _n,Vi a) {
        n=_n;
        s=vector<Seg>(n<<2);
        build(1,0,n-1,a);
    }
    void _ud(int w,int l,int r,int ql,int qr,int v) {
        if(ql<=l&&r<=qr) {
            addtag(s[w],v);
            return;
        }
        if(ql>r||qr<l) return;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        _ud(w<<1,l,m,ql,qr,v);
        _ud(w<<1|1,m+1,r,ql,qr,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void ud(int l,int r,int v) {
        _ud(1,0,n-1,l,r,v);
    }
    int _mn(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w].mn;
        if(ql>r||qr<l) return inf;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        return min(_mn(w<<1,l,m,ql,qr),_mn(w<<1|1,m+1,r,ql,qr));
    }
    int mn(int l,int r) {
        return _mn(1,0,n-1,l,r);
    }
    int _val(int w,int l,int r,int u) {
        if(l==r) {
            return s[w].mn;
        }
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        if(u<=m) return _val(w<<1,l,m,u);
        else return _val(w<<1|1,m+1,r,u);
    }
    int val(int u) {
        return _val(1,0,n-1,u);
    }
    int _qu(int w,int l,int r,int k) {//first i , a[i]<=k
        if(l==r) return l;
        int m=l+r>>1;
        push(s[w],s[w<<1],s[w<<1|1]);
        if(s[w<<1].mn<=k) return _qu(w<<1,l,m,k);
        else return _qu(w<<1|1,m+1,r,k);
    }
    int qu(int k) {
        return _qu(1,0,n-1,k);
    }
}seg;
signed main() {
    IOS(); 
    int n,m;
    cin>>n>>m;
    Vi h(n),c(m);
    REP(i,n) cin>>h[i];
    REP(i,m) cin>>c[i];
    sort(ALL(h),greater<int>());
    seg.init(n,h);
    REP(i,m) {
        if(c[i]>n) {
            cout<<i<<'\n';
            return 0;
        }
       // REP(j,n) cout<<seg.val(j)<<' ';entr
        int v=seg.val(c[i]-1);
        if(v==0) {
            cout<<i<<'\n';
            return 0;
        }
        int lv=seg.qu(v),lv2=seg.qu(v-1);
        if(seg.val(n-1)==v) lv2=n;
        seg.ud(0,lv-1,-1);
        int len=c[i]-lv;
        seg.ud(lv2-len,lv2-1,-1);
    }
    cout<<m<<'\n';
    return 0;
}