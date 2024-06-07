#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#ifdef LOCAL
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=998244353;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<int> t(3);
    vector<vector<int>> s(3,vector<int>(n));
    REP(i,3) {
        cin>>t[i];
        REP(j,n) cin>>s[i][j];
    }
    int N=1e6;
    REP(i,n) s[0][i]*=t[1]*t[2]*N;
    REP(i,n) s[1][i]*=t[0]*t[2]*N;
    REP(i,n) s[2][i]*=t[0]*t[1]*N;
    int prod=t[0]*t[1]*t[2]*3;
    int q;
    cin>>q;
    vector<int> v;
    REP(i,n)
        REP(j,n)
            v.pb(s[1][i]+s[2][j]);
    sort(ALL(v));
    REP(i,q) {
        int an=0,p;
        cin>>p;
        p*=prod;
        int lp=p-(prod>>1),rp=p+(1+prod>>1);
        REP(j,n) {
           int l=lower_bound(ALL(v),lp-s[0][j])-v.begin(),r=lower_bound(ALL(v),rp-s[0][j])-v.begin();
           an+=r-l;
        }
        cout<<an<<'\n';
    }
    return 0;
}
