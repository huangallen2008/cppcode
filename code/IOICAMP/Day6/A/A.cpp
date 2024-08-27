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
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int mod=998244353;
const int maxn=1e6+5;
const int inf=(1ll<<62);
const int maxV=1e9+5;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
int mysqrt(int n) {
    int l=0,r=maxV,m;
    while(l<r) {
        m=(l+r+1)/2;
        if(m*m>n) r=m-1;
        else l=m;
    }
    return l;
}
//
//bool check() {
//    REP(i,maxn) {
//        int k=rd(1,(int)1e18);
//        int a=mysqrt(k),b=sqrt(k);
//        if(a!=b) {
//            cout<<"!!!!!!!! ";
//            op(k)op(a)ope(b)
//        }
//    }
//}
//
int nsc(int sc,int a) {
    if(sc>a) return sc-((int)mysqrt(sc-a));
    return sc+((int)mysqrt(a-sc));
}
signed main() {
    IOS();
//    check();
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> a(n+1),b(n+1);
    REP1(i,n) cin>>a[i];
    REP1(i,n) cin>>b[i];
    vector<vector<int>> dp(n+1,vector<int>(k+1));
    REP(i,k+1) dp[0][i]=x;
    REP1(i,n) {
        REP(j,k+1) {
            dp[i][j]=nsc(dp[i-1][j],a[i]);
            if(j>0) dp[i][j]=max(dp[i][j],nsc(dp[i-1][j-1],b[i]));
        }
    }
    cout<<dp[n][k]<<'\n';
    return 0;
}
