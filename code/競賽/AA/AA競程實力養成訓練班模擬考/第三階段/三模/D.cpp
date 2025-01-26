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
const int maxn=5;
const int maxb=64;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int q,v;
    cin>>q>>v;
    if(v&1) {
        REP(i,q) cout<<"Impossible\n";
        return 0;
    }
    v/=2;
    vector<vector<bool>> dp(v+1,vector<bool>(v+1));
    vector<Vi> la(v+1,Vi(v+1));
    dp[0][0]=1;
    REP1(i,v) {
        REP1(j,v) {
            REP1(k,12) {
                if(i<(1<<k)) break;
                if(dp[i-(1<<k)][j-k]) {
                    la[i][j]=k;
                    dp[i][j]=1;
                }
            }
            // if(dp[i-1][j-1]) {
            //     la[i][j]=0;
            //     dp[i][j]=1;
            // }else if((~i&1)&&dp[i>>1][j]) {
            //     la[i][j]=1;
            //     dp[i][j]=1;
            // }
        }
    }
    REP(i,q) {
        int n;
        cin>>n;
        if(n>v||!dp[v][n]) {
            cout<<"Impossible\n";
            continue;
        }
        Vi an;
        int ni=v,nj=n,now=1;
        while(ni>0) {
            int t=la[ni][nj];
            ni-=1<<t,nj-=t;
            an.pb(t);
        }
        REP(j,an.size()) {
            REP(k,an[j]) cout<<2<<"*"[k==an[j]-1];
            cout<<"+\n"[j==an.size()-1];
        }
    }
    return 0;
}