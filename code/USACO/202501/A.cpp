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
int x,y;
struct po {
    int x1,y1;
    int cal() {
        return abs(x-x1)+abs(y-y1)+sqrt(SQ(x1)+SQ(y1));;
    }
    // bool operator<(const po b) {
    //     return cal()>b.cal();
    // }
};
struct srt {
    bool operator()(po a,po b) {
        return a.cal()>b.cal();
    }
};
signed main() {
    IOS();
    int n,t;
    cin>>n>>t;
    cin>>x>>y;
    priority_queue<po,vector<po>,srt> pq;
    vector<vector<po>> a(t);
    REP(i,n) {
        int tt,_x,_y;
        cin>>tt>>_x>>_y;
        a[tt].pb({_x,_y});
    }
    int ix=x,iy=y,ox=x,oy=y;
    int ix2=maxv,iy2=y,ox2=0,oy2=y;
    // iox=x,ioy=y,oix=x,oiy=y;
    SEG_mx segox,segoy;
    SEG_mn segix,segiy;
    segox.init(maxv);
    segix.init(maxv);
    segoy.init(maxv);
    segiy.init(maxv);
    // segox.ud(x,y);
    // segix.ud(x,y);
    // segoy.ud(y,x);
    // segiy.ud(y,x);
    auto good=[&](int l,int r,int v) {
        if(v<=l) return l;
        if(v>=r) return r;
        return v;
    };
    REP(i,t) {
        for(auto [_x,_y]:a[i]) {
    ope("ok")
            int xx=_x,xy=_y,nx=_x,ny=_y;
            int v1,v2;
            while(xx<(v1=segoy.qu(0,xy))||xy<(v2=segox.qu(0,xx))) {
                chmax(xx,v1);
                chmax(xy,v2);
            }
            while(nx>(v1=segiy.qu(ny,maxv))||ny>(v2=segix.qu(nx,maxv))) {
                chmin(nx,v1);
                chmin(ny,v2);
            }
            op(nx)op(ny)op(xx)ope(xy)
            segox.ud(nx,xy);
            segox.ud(xx,xy);
            segix.ud(nx,ny);
            segix.ud(xx,ny);
            segoy.ud(ny,xx);
            segoy.ud(xy,xx);
            segiy.ud(ny,nx);
            segiy.ud(xy,nx);
            // ope("ok")
            pq.push({xx,good(segox.qu(0,xx),segix.qu(xx+1,maxv),y)});
            pq.push({nx,good(segox.qu(0,nx-1),segix.qu(nx,maxv),y)});
        }
        // chmax(ox,segoy.qu(0,segox.qu(0,ox)));
        // oy=good(segox.qu(0,ox),segix.qu(ox+1,maxv),y);
        // chmin(ix,segiy.qu(segix.qu(ox,maxv),maxv));
        // // ope(segiy.qu(ix,maxv))
        // iy=good(segox.qu(0,ix-1),segix.qu(ix,maxv),y);
        // int v1,v2;
        // while(ox<(v1=segoy.qu(0,oy))||oy<(v2=segox.qu(0,ox))) {
        //     ox=v1,oy=v2;
        // }
        // while(ix>(v1=segiy.qu(iy,maxv))||iy>(v2=segix.qu(ix,maxv))) {
        //     ix=v1,iy=v2;
        // }
        // while(ox2<(v1=segoy.qu(0,oy2))||oy2<(v2=segox.qu(0,ox2))) {
        //     ox2=v1,oy2=v2;
        // }
        // while(ix2>(v1=segiy.qu(iy2,maxv))||iy2>(v2=segix.qu(ix2,maxv))) {
        //     ix2=v1,iy2=v2;
        // }
        // while(iox!=(v1=segiy.qu(ioy,maxv))||ioy!=(v2=segox.qu(0,iox))) {
        //     iox=v1,ioy=v2;
        // }
        // while(oix!=(v1=segoy.qu(0,oiy))||oiy!=(v2=segix.qu(oix,maxv))) {
        //     oix=v1,oiy=v2;
        // }
        // op(ix)op(iy)op(ox)ope(oy)
        // op(ix2)op(iy2)op(ox2)ope(oy2)
        auto ok=[&](po p) ->bool {
            return p.y1>=segox.qu(0,p.x1-1)&&p.y1<=segix.qu(p.x1+1,maxv);
        };
        while(!ok(pq.top())) pq.pop();
        int an=0;//pq.top().cal();
                    // abs(x-ix2)+abs(y-iy2)+sqrt(SQ(ix2)+SQ(iy2)),abs(ox2-x)+abs(oy2-y)+sqrt(SQ(ox2)+SQ(oy2))});
        cout<<an<<'\n';
    }
    return 0;
}