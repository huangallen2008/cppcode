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
#define SZ(x) ((int)((x).size()))
#define SQ(x) ((x)*(x))
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
const int maxn=2e5+5;
const int maxb=20;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int l,n,T;
    cin>>l>>n>>T;
    Vpii a(n);
    REP(i,n) cin>>a[i];
    Vi vsum,vdif;
    vsum.pb(-inf),vdif.pb(-inf);
    REP(i,n) vsum.pb(a[i].f+a[i].s),vdif.pb(a[i].f-a[i].s);
    sort(ALL(vsum));
    sort(ALL(vdif));
    for(auto ms:vsum) {
        for(auto md:vdif) {
            Vpii v[2][2];
            for(auto [x,y]:a) {
                v[x+y>ms][x-y>md].pb({x,y});
            }
            sort(ALL(v[0][1]));
            sort(ALL(v[1][0]));
            sort(ALL(v[0][0]),[&](pii a,pii b) { return a.s<b.s; });
            sort(ALL(v[1][1]),[&](pii a,pii b) { return a.s<b.s; });
            Vi pv[2][2][2];
            REP(i,2) REP(j,2) pv[i][j][0]=pv[i][j][1]=Vi(SZ(v[i][j])+1);
            REP(k,SZ(v[0][0])) pv[0][0][0][k+1]=v[0][0][k].f+v[0][0][k].s;
            REP(k,SZ(v[0][0])) pv[0][0][1][k+1]=v[0][0][k].f+l-v[0][0][k].s;
            REP(k,SZ(v[1][0])) pv[1][0][0][k+1]=v[1][0][k].f+l-v[1][0][k].s;
            REP(k,SZ(v[1][0])) pv[1][0][1][k+1]=l-v[1][0][k].f+l-v[1][0][k].s;
            REP(k,SZ(v[1][1])) pv[1][1][0][k+1]=l-v[1][1][k].f+l-v[1][1][k].s;
            REP(k,SZ(v[1][1])) pv[1][1][1][k+1]=l-v[1][1][k].f+v[1][1][k].s;
            REP(k,SZ(v[0][1])) pv[0][1][0][k+1]=l-v[0][1][k].f+v[0][1][k].s;
            REP(k,SZ(v[0][1])) pv[0][1][1][k+1]=v[0][1][k].f+v[0][1][k].s;
            REP(i,2) REP(j,2) REP(tt,2) REP1(k,SZ(pv[i][j][tt])-1) pv[i][j][tt][k]+=pv[i][j][tt][k-1];
            bool ok=1;
            REP(i1,SZ(pv[0][0][0])) {
                Vi tt(4);
                tt[0]+=pv[0][0][0][i1];
                tt[1]+=pv[0][0][1].back()-pv[0][0][1][i1];
                if(tt[0]>T||tt[1]>T) {ok=0;break;}
                int i2=upper_bound(ALL(pv[1][0][0]),T-tt[1])-pv[1][0][0].begin()-1;
                tt[1]+=pv[1][0][0][i2];
                tt[2]+=pv[1][0][1].back()-pv[1][0][1][i2];
                if(tt[1]>T||tt[2]>T) {ok=0;break;}
                int i3=upper_bound(ALL(pv[1][1][0]),T-tt[2])-pv[1][1][0].begin()-1;
                tt[2]+=pv[1][1][0][i3];
                tt[3]+=pv[1][1][1].back()-pv[1][1][1][i3];
                if(tt[2]>T||tt[3]>T) {ok=0;break;}
                int i4=upper_bound(ALL(pv[0][1][0]),T-tt[3])-pv[0][1][0].begin()-1;
                tt[3]+=pv[0][1][0][i4];
                tt[0]+=pv[0][1][1].back()-pv[1][1][1][i4];
                if(tt[4]>T||tt[3]>T) {ok=0;break;}
                op(i1)op(i2)op(i3)op(i4)oparr(tt)
                oparr(v[0][0])
                oparr(v[1][0])
                oparr(v[1][1])
                oparr(v[0][1])
            }
            if(ok) {
                cout<<"Yes\n";
                return 0;
            }
        }
    }
    cout<<"No\n";
    return 0;
}
