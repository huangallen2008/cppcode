#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx,avx2,sse4,sse4.1,sse4.2,bmi,bmi2,popcnt")
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
const int inf=1ll<<62;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG {
    struct Seg {
        Vi x;
        Seg(){x=Vi(4);}
        Seg(Vi _x) : x(_x){} 
    };
    int n,m;
    vector<Seg> s;
    Seg merge(Seg b,Seg c) {
        Seg a;
        Vi d(8);
        REP(i,4) d[i]=b.x[i],d[i+4]=c.x[i];
        oparr(d)
        REP1(i,7) d[i]+=d[i-1];
        int mn=0,id=0;
        REP(i,8) {
            if(d[i]<mn) {
                mn=d[i];
                id=i;
            }
        }
        int mx1=0,mx2=0;
        if(id==0) mx1=0;
        else mx1=*max_element(d.begin(),d.begin()+id);
        if(id==7) mx2=0;
        else mx2=*max_element(d.begin()+id+1,d.end());
        oparr(d)op(id)op(mx1)ope(mx2)
        a.x={mx1,mn-mx1,mx2-mn,d.back()-mx2};
        chmin(a.x[0],m)
        chmin(a.x[2],m)
        return a;
    }
    void pull(Seg &a,Seg &b,Seg &c) {
        a=merge(b,c);
    }
    void build(int w,int l,int r,Vi &a) {
        if(l==r) {
            if(a[l]<0) s[w].x={0,a[l],0,0};
            else s[w].x={a[l],0,0,0};
            return;
        }
        int m=l+r>>1;
        build(w<<1,l,m,a);
        build(w<<1|1,m+1,r,a);
        // op(l)ope(r)
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void init(int _n,int _m,vector<int> &a) {
        n=_n,m=_m;
        s=vector<Seg>(n<<2);
        build(1,0,n-1,a);
    }
    void _ud(int w,int l,int r,int u,int v) {
        if(l==r) {
            if(v<0) s[w].x={0,v,0,0};
            else s[w].x={v,0,0,0};
            return;
        }
        int m=l+r>>1;
        if(u<=m) _ud(w<<1,l,m,u,v);
        else _ud(w<<1|1,m+1,r,u,v);
        pull(s[w],s[w<<1],s[w<<1|1]);
    }
    void ud(int u,int v) {
        _ud(1,0,n-1,u,v);
    }
    Seg _qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return Seg({0,0,0,0});
        int m=l+r>>1;
        return merge(_qu(w<<1,l,m,ql,qr),_qu(w<<1|1,m+1,r,ql,qr));
    }
    int qu(int l,int r,int y) {
        // op(_qu(1,0,n-1,l,r).u1);
        // op(_qu(1,0,n-1,l,r).d);
        // ope(_qu(1,0,n-1,l,r).u2);
        // op(merge({0,y},_qu(1,0,n-1,l,r)).f);
        // ope(merge({0,y},_qu(1,0,n-1,l,r)).s);
        Seg ret0=_qu(1,0,n-1,l,r);
        oparr(ret0.x)
        Seg ret=merge(Seg({y,0,0,0}),ret0);
        oparr(ret.x)
        return ret.x[0]+ret.x[1];
    }
}seg;
signed main() {
    IOS(); 
    int n,m,q;
    cin>>n>>q>>m;
    Vi a(n);
    REP(i,n) cin>>a[i],a[i]=-a[i];
    seg.init(n,m,a);
    REP(i,q) {
        int opt;
        cin>>opt;
        if(opt==1) {
            int p,x;
            cin>>p>>x,p--;
            seg.ud(p,x);
        }
        else {
            int l,r,y;
            cin>>l>>r>>y,l--,r--,y=min(y,m);
            cout<<seg.qu(l,r,y)<<'\n';
        }
        // REP1(i,10) cout<<seg.s[i].f<<' ';entr
        // REP1(i,10) cout<<seg.s[i].s<<' ';entr entr
    }
    return 0;
}