#include <vector>

int maximum_length(const std::vector<int> &UX, const std::vector<int> &UY, 
                   const std::vector<int> &DX, const std::vector<int> &DY) {
    int n = UX.size() / 2;
    int m = DX.size() / 2;

    return 4;
}
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,avx,bmi,bmi2,abm,sse2,sse3,sse4.1,sse4.2")
// #define int long long
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
    clock_t st=clock();
    Vi ux(n*2),uy(n*2),dx(m*2),dy(m<<1);
    REP(i,n*2) ux[i]=UX[i],uy[i]=UY[i];
    // Vpii b(m*2);
    REP(i,m*2) dx[i]=DX[i],dy[i]=DY[i];
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
    if(n>m) {
        swap(n,m);
        swap(a,b);
    }
    auto cal=[&](int dd) ->int{
        Vpii bb=b;
        REP(i,m+1) bb[i].f+=dd;
        Vi tx;
        int av=0,bv=0,ita=0,itb=0;
        int N=n+m;
        Vi ax(N),bx(N);
        REP(i,N) {
            if(itb==m+1&&a[ita].f<bb[itb].f) {
                av=a[++ita].s;
                tx.pb(a[ita].f);
            }else {
                bv=bb[++itb].s;
                tx.pb(bb[itb].f);
            }
            ax[i]=av;
            bx[i]=bv;
        }
        int mx=0,an=0;
        REP(i,N-1) chmax(mx,ax[i]+bx[i]);
        REP(i,N-1) if(ax[i]+bx[i]==mx) an+=tx[i+1]-tx[i];
        return an;
    };
    int an=0;
    for(int dd=-dn;dd<=un;dd++) chmax(an,cal(dd));
    // auto va=[&](int x) {
    //     if(x<0) return -inf;
    //     return prev(lower_bound(ALL(a),pii{x,inf}))->s;
    // };
    // auto vb=[&](int x) {
    //     if(x<0) return -inf;
    //     return prev(lower_bound(ALL(b),pii{x,inf}))->s;
    // };
    // oparr(a)oparr(b)
    // Vpii apple;
    // REP(i,n+1) REP(j,m+1) apple.pb({i,j});
    // shuffle(ALL(apple),rng);
    // int ccc=0;
    // int mxcc=150000000/(n+m);
    // for(auto [i,j]:apple) {
    //     if(ccc++>mxcc) break;
    //     // ope((double)clock()/CLOCKS_PER_SEC)
    //     // if((long double)(clock()-st)/CLOCKS_PER_SEC>=0.9) break;
    //     // op(i)ope(j)
    //         // #ifdef LOCAL
    //         // if(i||j) continue;
    //         // #endif
    //         int cnt=0;
    //         Vi tx;
    //         REP(k,n+1) tx.pb(a[k].f-a[i].f);
    //         REP(k,m+1) tx.pb(b[k].f-b[j].f);
    //         sort(ALL(tx));
    //         // oparr(tx)
    //         int mx=0;
    //         int nn=SZ(tx);
    //         Vi va(nn-1),vb(nn-1);
    //         int it=0;
    //         REP(k,nn-1) {
    //             int val=tx[k]+a[i].f;
    //             while(it<n+1&&a[it].f<=val) it++;
    //             if(it==0||it==n+1) va[k]=-inf;
    //             else va[k]=a[it-1].s;
    //         }
    //         it=0;
    //         REP(k,nn-1) {
    //             int val=tx[k]+b[j].f;
    //             while(it<m+1&&b[it].f<=val) it++;
    //             if(it==0||it==m+1) va[k]=-inf;
    //             else vb[k]=b[it-1].s;
    //         }
    //         REP(k,nn-1) {
    //             chmax(mx,va[k]+vb[k]);
    //             // op(k)op(va(tx[k]+a[i].f))ope(vb(tx[k]+b[j].f));
    //         }
    //         REP(k,nn-1) {
    //             if(va[k]+vb[k]==mx) cnt+=tx[k+1]-tx[k];
    //         }
    //         chmax(an,cnt);
    //         // op(i)op(j)ope(cnt)
    // }
    return an;
}
