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
const int mod=1e9+7;
const int maxn=2e3+5;
const int maxv=4e3+5;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n; 
    cin>>n;
    vector<Vi> a(maxv);
    REP(i,n) {
        int l,r;
        cin>>l>>r;
        a[r].pb(l);
    }
    REP(i,maxv) sort(ALL(a[i]));
    vector<Vi> dp0(maxv,Vi(maxv));
    vector<Vi> dp1(maxv,Vi(maxv));
    REP(i,maxv) {
        REP(j,maxv) {
            if(i==j) {
                dp0[i][j]=dp1[i][j]=1;
                continue;
            }
            if(i<j) {
                dp1[i][j]=dp1[i][j-1];
                for(int l:a[j]) {
                    if(l<=i) addmod(dp1[i][j],dp0[i][l-1]);
                    else addmod(dp1[i][j],dp1[i][l-1]);
                }
            }else {
                dp0[i][j]=dp0[i-1][j];
                for(int l:a[i]) {
                    if(l<=j) addmod(dp0[i][j],dp1[l-1][j]);
                    else addmod(dp0[i][j],dp0[l-1][j]);
                    if(i==3&&j==0) {
                        op(l)op(j)ope(dp0[i][j])
                    }
                }
            }
        }
    }
    int an=0;
    REP(i,8) {
        REP(j,8) cout<<dp0[i][j]<<' ';
        cout<<'\n';
    }entr
    REP(i,8) {
        REP(j,8) cout<<dp1[i][j]<<' ';
        cout<<'\n';
    }
    REP(i,maxv) {
        for(int l:a[i]) {
            op(l)op(i)ope(dp1[l-1][i-1])
            addmod(an,dp1[l-1][i-1]);
        }
        // REP(j,a[i].size()) {
        //     REP(k,j) {
        //         op(a[i][j])op(a[i][k])op(i)ope(dp1[a[i][k]-1][a[i][j]-1])
        //         addmod(an,dp1[a[i][k]-1][a[i][j]-1]);
        //     }
        // }
    }
    cout<<an<<'\n';
    return 0;
}