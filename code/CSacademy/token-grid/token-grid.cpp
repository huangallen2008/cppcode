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
const int mod=1e9+7;
const int maxn=5;
const int maxb=64;
const int inf=1e9;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n,m;
Vi trans(Vi v,int type=1) {
    REP(i,n) {
        REP(j,1<<n) if(j>>i&1) {
            addmod(v[j],v[j^(1<<i)]*type);
        }
    }
    return v;
}
Vi merge(Vi a,Vi b) {
    REP(i,1<<n) a[i]=(a[i]*b[i])%mod;
    return a; 
}
signed main() {
    IOS();
    cin>>n>>m;
    vector<Vi> a(m,Vi(n));
    REP(i,n) {
        REP(j,m) {
            char c;
            cin>>c;
            if(c!='.') a[j][i]=c-'a';
        }
    }
    Vi dp(1<<n,1);
    int all=(1<<n)-1;
    REP(i,m) {
        Vi d(1<<n);
        int now=0,sum=n;
        Vi nv(n,1);
        auto upd=[&](int u) {
            // op(u)
            if(now>>u&1) {
                nv[u]>>=1;
                addmod(sum,-nv[u]);
            }else {
                addmod(sum,nv[u]);
                nv[u]<<=1;
            }
            now^=1<<u;
        };
        d[0]=1;
        for(int j=1;j<1<<n;j++) {
            REP(k,n) {
                if(j>>k&1) {
                    upd(k);
                    break;
                }
                else {
                    upd(k);
                }
            }
            op(j)ope(now)
            d[j]=sum-n+1;
        }
        dp=merge(dp,d);
        oparr(d)oparr(dp)
    }
    dp=trans(dp,-1);
    Vi an(n+1);
    REP(i,1<<n) {
        addmod(an[n-__builtin_popcount(i)],dp[i]);
    }
    REP(i,n+1) cout<<an[i]<<' ';
    cout<<'\n';
    return 0;
}