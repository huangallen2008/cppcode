#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,popcnt")
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
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(allen,(x).size()) cout<<x[allen]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
bool check(int n,vector<int> &a,vector<int> &b,int k) {
    vector<int> c(n);
    REP(i,n) c[i]=a[i]^k;
    sort(ALL(c));
    REP(i,n) if(c[i]!=b[i]) return 0;
    return 1;
}
signed main() {
    IOS();
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    REP(i,n) cin>>a[i];
    REP(i,n) cin>>b[i];
    sort(ALL(a));
    sort(ALL(b));
    vector<int> an;
    REP(i,n) {
        int k=a[0]^b[i];
        if(check(n,a,b,k)) an.pb(k);
    }
    sort(ALL(an));
    int nn=an.size();
    an.pb(inf);
    vector<int> an2;
    REP(i,nn) if(an[i]!=an[i+1]) an2.pb(an[i]);
    cout<<an2.size()<<'\n';
    for(int &x:an2) cout<<x<<'\n';
    return 0;
}