#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
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
#define Vpii vector<pii>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) {cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;}
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
template<typename T1,typename T2>
istream& operator>>(istream& os,pair<T1,T2> &p) { return os>>p.f>>p.s; }
template<typename S>
ostream& operator<<(ostream& os,vector<S> p) { for(auto allen:p) os<<allen<<' ';return os<<'\n'; }
template<typename S>
istream& operator>>(istream& os,vector<S> &p) { for(auto &allen:p) os>>allen;return os; }
template<typename T1,typename T2>
pair<T1,T2> operator+(pair<T1,T2> p1,pair<T1,T2> p2) { return pair<T1,T2>(p1.f+p2.f,p1.s+p2.s); }
const int mod=998244353;
// const int maxn=5;
const int maxv=1e6+5;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
struct SEG_mx {
    int n;
    Vi s;
    void init(int _n,int init_val=-inf) {
        n=_n;
        s=Vi(n<<2,init_val);
    }
    void _ud(int w,int l,int r,int u,int v) {
        if(l==r) {
            chmax(s[w],v);
            return ;
        }
        int m=l+r>>1;
        if(u<=m) _ud(w<<1,l,m,u,v);
        else _ud(w<<1|1,m+1,r,u,v);
        s[w]=max(s[w<<1],s[w<<1|1]);
    }
    void ud(int u,int v) {
        _ud(1,0,n-1,u,v);
    }
    int _qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return -inf;
        int m=l+r>>1;
        return max(_qu(w<<1,l,m,ql,qr),_qu(w<<1|1,m+1,r,ql,qr));
    }
    int qu(int l,int r) {
        return _qu(1,0,n-1,l,r);
    }
};
struct SEG_mn {
    int n;
    Vi s;
    void init(int _n,int init_val=inf) {
        n=_n;
        s=Vi(n<<2,init_val);
    }
    void _ud(int w,int l,int r,int u,int v) {
        if(l==r) {
            chmin(s[w],v);
            return ;
        }
        int m=l+r>>1;
        if(u<=m) _ud(w<<1,l,m,u,v);
        else _ud(w<<1|1,m+1,r,u,v);
        s[w]=min(s[w<<1],s[w<<1|1]);
    }
    void ud(int u,int v) {
        _ud(1,0,n-1,u,v);
    }
    int _qu(int w,int l,int r,int ql,int qr) {
        if(ql<=l&&r<=qr) return s[w];
        if(ql>r||qr<l) return inf;
        int m=l+r>>1;
        return min(_qu(w<<1,l,m,ql,qr),_qu(w<<1|1,m+1,r,ql,qr));
    }
    int qu(int l,int r) {
        return _qu(1,0,n-1,l,r);
    }
};
struct po {
    int x,y;
};
signed main() {
    IOS();
    int n,t;
    cin>>n>>t;
    int x,y;
    cin>>x>>y;
    vector<vector<po>> a(t);
    REP(i,n) {
        int tt,_x,_y;
        cin>>tt>>_x>>_y;
        a[tt].pb({_x,_y});
    }
    int ix=x,iy=y,ox=x,oy=y,iox=x,ioy=y,oix=x,oiy=y;
    SEG_mx segox,segoy;
    SEG_mn segix,segiy;
    segox.init(maxv);
    segix.init(maxv);
    segoy.init(maxv);
    segiy.init(maxv);
    segox.ud(x,y);
    segix.ud(x,y);
    segoy.ud(y,x);
    segiy.ud(y,x);
    REP(i,t) {
        for(auto [xx,yy]:a[i]) {
            segox.ud(xx,yy);
            segix.ud(xx,yy);
            segoy.ud(yy,xx);
            segiy.ud(yy,xx);
        }
        int v1,v2;
        while(ox!=(v1=segoy.qu(0,oy))||oy!=(v2=segox.qu(0,ox))) {
            ox=v1,oy=v2;
        }
        while(ix!=(v1=segiy.qu(iy,maxv))||iy!=(v2=segix.qu(ix,maxv))) {
            ix=v1,iy=v2;
        }
        while(iox!=(v1=segiy.qu(ioy,maxv))||ioy!=(v2=segox.qu(0,iox))) {
            iox=v1,ioy=v2;
        }
        while(oix!=(v1=segoy.qu(0,oiy))||oiy!=(v2=segix.qu(oix,maxv))) {
            oix=v1,oiy=v2;
        }
        op(ix)op(iy)op(ox)ope(oy)
        int an=min({x+y-ix-iy+sqrt(SQ(ix)+SQ(iy)),ox-x+oy-y+sqrt(SQ(ox)+SQ(oy))
        });
        cout<<an<<'\n';
    }
    return 0;
}