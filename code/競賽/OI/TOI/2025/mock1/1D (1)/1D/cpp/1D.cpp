#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define pb push_back
#define pii pair<int,int>
#define Vi vector<int>
#define Vpii vector<pii>
#define f first 
#define s second 
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)((x).size()))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define Graph vector<Vi>
#define Graphw vector<Vpii>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#ifdef LOCAL
#define op(x) cerr<<(#x)<<"="<<(x)<<", ";
#define ope(x) cerr<<(#x)<<"="<<(x)<<endl;
#define oparr(x) {for(auto allen:(x)) cerr<<(allen)<<' ';cout<<endl;}
#define entr cout<<endl;
#else 
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename S,typename T> 
ostream& operator<<(ostream& os,pair<S,T> p) {
    return os<<'{'<<p.first<<','<<p.s<<"}";
}
template<typename S> 
ostream& operator<<(ostream& os,vector<S> p) {
    for(auto x:p) os<<x<<' ';
    os<<'\n';
    return os;
}
const int inf=(1ll<<29);
signed maximum_length(const std::vector<signed> &UX, const std::vector<signed> &UY, 
                   const std::vector<signed> &DX, const std::vector<signed> &DY) {
    int n = UX.size() / 2;
    int m = DX.size() / 2;
    // Vpii a(n*2);
    Vi ux(n*2),uy(n*2),dx(m*2),dy(m<<1);
    REP(i,m*2) dx[i]=DX[i],dy[i]=DY[i];
    REP(i,n*2) ux[i]=UX[i],uy[i]=UY[i];
    // Vpii b(m*2);
    if(n>m) {
        swap(n,m);
        swap(ux,dx);
        swap(uy,dy);
    }
    int umxy=*max_element(ALL(uy)),dmxy=-*min_element(ALL(dy));
    int umnx=ux[0],umxx=ux.back();
    int dmnx=dx[0],dmxx=dx.back();
    int un=umxx-umnx,dn=dmxx-dmnx;
    Vpii a(n+1),b(m+1);
    a[n]={umxx-umnx,-inf};
    b[m]={dmxx-dmnx,-inf};
    REP(i,n) {
        a[i]={ux[i<<1]-umnx,umxy-uy[i<<1]};
    }
    REP(i,m) {
        b[i]={dx[i<<1]-dmnx,dmxy+dy[i<<1]};
    }
    Vpii b0=b;
    auto cal=[&](int dd) ->int{
        // if(dd!=-3) return 0;
        // oparr(a)oparr(bb)
        Vpii b=b0;
        REP(i,m+1) b[i].f-=dd;
        Vi tx;
        int av=-inf,bv=-inf,ita=0,itb=0;
        Vi ax,bx;
        // auto magic=[&](bool x) ->bool { if(x) ope("!!!!!!!!!!") return x; };
        while(1){
            if(ita==n+1&&itb==m+1) break;
            // op(i)ope(N)
            // op(ita)op(itb)op(n+1)ope(m+1)op(itb==m+1)op(ita!=n+1)op(a[ita].f)ope(bb[itb].f)
            if(itb==m+1||(ita!=n+1&&(a[ita].f<b[itb].f))) {
                // ope("aaaaaaaaaaaaaaaaaaaaaaaa")
                // ope(ita)
                tx.pb(a[ita].f);
                av=a[ita++].s;
            }else if(ita==n+1||a[ita].f>b[itb].f){
                // ope("bbbbbbbbbbbbbbbbbbbbbbbb")
                // ope(itb)
                tx.pb(b[itb].f);
                bv=b[itb++].s;
            }else {
                // op(a[ita].f)ope(bb[itb].f)
                // ope("cccccccccccccccccccccccc")
                // op(ita)ope(itb)
                tx.pb(a[ita].f);
                av=a[ita++].s;
                bv=b[itb++].s;
            }
            ax.pb(av);
            bx.pb(bv);
        }
        int N=tx.size();
        oparr(tx)oparr(ax)oparr(bx)
        int mx=0,an=0;
        REP(i,N-1) chmax(mx,ax[i]+bx[i]);
        ope(mx)
        REP(i,N-1) if(ax[i]+bx[i]==mx) an+=tx[i+1]-tx[i];
        op(dd)ope(an)
        // REP(i,m+1) b[i].f++;
        return an;
    };
    int an=0;
    for(int dd=-dn-1;dd<=un+1;dd++) chmax(an,cal(dd));
    return an;
}
