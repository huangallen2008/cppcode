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
#define ppi pair<pii,int>
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
const int mod=1e9+7;
const int maxn=2e5+5;
const int maxv=105;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#define pdd pair<ld,ld>
#define Vpd vector<pdd>
#define Vld vector<ld>
ld rhe(ld f){
    const ld r = round(f);
    const ld d = r - f;
    if ((d != 0.5f) && (d != -0.5f))return r;
    if (fmod(r, 2.0) == 0.0)return r;
    return f - d;
}
signed main() {
    IOS();
    fesetround(FE_TONEAREST);
    int n;
    cin>>n;
    Vi a(n);
    REP(i,n) cin>>a[i];
    vector<Vpd> dp(maxv,Vpd(n+1));
    REP(i,maxv) dp[i][0]={0,1};
    auto upd=[&](pdd &a,pdd b) ->void{
        if(b.s==0) return;
        a={(a.f*a.s+b.f*b.s)/(a.s+b.s),a.s+b.s};
    };
    auto trans=[&](int v) {
        vector<Vpd> ndp(maxv,Vpd(n+1));
        REP1(i,maxv-1) {
            REP(j,n) {
                if(i<=v) upd(ndp[i][j],{dp[i][j].f+j,dp[i][j].s/v});
                upd(ndp[i][j],{dp[i][j].f,dp[i][j].s*(min(i,v)-(i<=v))/v});
                upd(ndp[i][j+1],{dp[i][j].f,dp[i][j].s*(v-min(i,v))/v});
            }
        }
        swap(dp,ndp);
    };
    REP(i,n) trans(a[i]);
    ld an=0;
    REP1(i,maxv-1) REP(j,n+1) an+=dp[i][j].f*dp[i][j].s;
    // auto rhe=[&](ld &an)->void {
    //     an+=1e-18;
    //     cout<<fixed<<setprecision(20) <<an<<'\n';
    //     int tt=an*1e7;
    //     // ope(tt)
    //     if(tt%10==5 && (~(int)(tt/10)&1))
    //         an-=1e-7;
    // };
    cout<<fixed<<setprecision(20)<<an;
    // // an=(int)(an*(ld)1e8)/1e8;
    // an=rint(an*(ld)1e6)/1e6;
    an=rhe(an*1e6)/1e6;
    cout<<fixed<<setprecision(6)<<an<<'\n';
    return 0;
}
