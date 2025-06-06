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
const int maxv=1e6+5;
const int maxn=1e3+5;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    #ifdef LOCAL
        // freopen("in.txt","r",stdin);
    #endif
    int q,v;
    cin>>q>>v;
    vector<bitset<maxv>> dp(maxn+1);
    // vector<vector<bool>> dp(v+1,vector<bool>(v+1));
    // vector<Vi> la(v+1,Vi(v+1));
    dp[0][0]=1;
    REP1(i,maxn) {
        for(int j=1;j<=20&&j<=i;j++) {
            dp[i]|=dp[i-j]<<(1<<j);
        }
    }
    REP(i,q) {
        int n;
        cin>>n;
        if(!dp[n][v]) {
            cout<<"Impossible\n";
            continue;
        }
        Vi an;
        int ni=n,nj=v;
        while(ni>0) {
            for(int k=1;k<=20&&k<=ni&&(1<<k)<=nj;k++) if(dp[ni-k][nj-(1<<k)]) {
                an.pb(k);
                ni-=k,nj-=1<<k;
            }
        }
        REP(j,an.size()) {
            REP(k,an[j]) {
                cout<<2;if(k!=an[j]-1) cout<<"*";
            }
            cout<<"+\n"[j==an.size()-1];
        }
    }
    return 0;
}