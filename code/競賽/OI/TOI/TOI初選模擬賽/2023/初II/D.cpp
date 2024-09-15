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
#define MD(x,M) (((x)%(M)+(M))%(M))
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(i,(x).size()) cout<<x[i]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=2e5+5;
const int maxv=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
int n,c;
int f(int s) {
    if(s<0) return abs(s);
    int k=s%c;
    return min(k,c-k);
}
int f2(int s) {
    if(s<0) return s;
    int k=s%c;
    if(k<c-k) return k;
    else return k-c;
}
signed main() {
    IOS();
    cin>>n>>c;
    vector<int> a(n+1),ps(n+1);
    REP1(i,n) cin>>a[i];
    REP1(i,n) ps[i]=ps[i-1]+a[i];
    int x=ps[n]%c;
    vector<int> dp0(n+1),dp1(n+1);
    REP1(i,n) {
        dp0[i]=dp0[i-1]+f(ps[i-1]);
        dp1[i]=min(dp1[i-1]+f(ps[i-1]-x),dp0[i-1]+f(ps[i-1]));
    }
//    oparr(dp0)
//    oparr(dp1)
    int id=0;
    RREP1(i,n) {
        if(dp1[i]==dp0[i-1]+f(ps[i-1])) {
            id=i;
            break;
        }
    }
//    ope(id)
    vector<int> an=a;
    REP1(i,n) {
        if(i==1) continue;
        if(i<=id) {
            int ret=f2(ps[i-1]);
            an[i-1]-=ret;
            an[i]+=ret;
        }
        else {
            int ret=f2(ps[i-1]-x);
            an[i-1]-=ret;
            an[i]+=ret;
        }
    }
    //oparr(an)
    int ans=dp1[n];
    cout<<ans<<'\n';
    REP1(i,n) cout<<an[i]<<' ';
    cout<<'\n';
    return 0;
}
