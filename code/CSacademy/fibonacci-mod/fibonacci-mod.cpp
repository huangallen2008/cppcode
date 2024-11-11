#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
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
int mod;
// const int mod=1e9+7;
const int maxmod=(1<<30)+5;
const int maxn=5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#define mat vector<Vi>
mat operator*(mat a,mat b) {
    int n=a.size(),m=b.size(),k=b[0].size();
    mat c(n,Vi(k));
    REP(i,n) REP(j,m) REP(l,k) (c[i][l]+=a[i][j]*b[j][l])%=mod;
    // REP(i,n) REP(j,k) cout<<c[i][j]<<' ';entr
    return c;
}
mat pw(mat x,int p) {
    int n=x.size();
    mat r(n,Vi(n));
    REP(i,n) r[i][i]=1;
    while(p>0) {
        if(p&1) r=r*x;
        x=x*x;
        p>>=1;
    }
    return r;
}
struct mhash {
    int operator()(const mat a) const{
        return a[0][0]*maxmod+a[0][1];
    }
};
void solve() {
    int a,b;
    cin>>mod>>a>>b;
    mat x={{0,1}},y={{a,b}},r={{0,1},{1,1}};
    int sm=sqrt(6*mod)+5;
    unordered_map<mat,int,mhash> mp;
    mat t=y;
    REP1(i,sm) {
        t=t*r;
        mp[t]=i;
        // op(i)oparr(t[0])
    }
    // entr
    mat bigr=pw(r,sm);
    t=x;
    int an=-1;
    REP(i,sm) {
        // op(i*sm)oparr(t[0])
        if(mp.find(t)!=mp.end()) {
            an=i*sm-mp[t];
            break;
        }
        t=t*bigr;
    }
    if(an==-1) {
        cout<<"-1\n";
    }
    else if(x*pw(r,an)==y) {
        cout<<an<<'\n';
    }
    else {

    }
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve(); 
    return 0;
}