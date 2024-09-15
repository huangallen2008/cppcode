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
bool so(pii a,pii b) {
    return a.f>b.f;
}
signed main() {
    IOS();
    int n,s;
    cin>>n>>s;
    int m=n;
    n--;
//    int an=s/m;
    vector<pii> d(n+1);
    vector<int> d2(n+1),od(n+1);
    REP1(i,n) cin>>d[i].f;
    REP1(i,n) d[i].s=i;
    REP1(i,n) od[i]=d[i].f;
    sort(d.begin()+1,d.end(),so);
    vector<int> dd(n+1);
    REP1(i,n) dd[i]=d[i].f;
    REP1(i,n) d2[i]=MD(dd[i]*2,m);
    int sum=0;
    REP1(i,n) sum+=dd[i];
    int st=MD(sum,m),t=MD(s,m);
    vector<vector<bool>> dp(n+1,vector<bool>(m));
    dp[0][st]=1;
    REP1(i,n) {
        REP(j,m) {
            dp[i][j]=dp[i-1][j];
            int k=MD(j+d2[i],m);
            dp[i][j]=dp[i][j]||dp[i-1][k];
        }
    }
//    REP1(i,n) {
//        REP(j,m) cout<<dp[i][j]<<' ';entr
//
//    }
//    op(st)ope(t)
    if(!dp[n][t]) {
        cout<<"-1\n";
        return 0;
    }
    vector<bool> use(n+1,1);
    int now=t;

//    REP1(i,n) cout<<d[i].s<<' ';entr
    RREP1(i,n) {
        int k=MD(now+d2[i],m);
        if(!dp[i-1][now]) {
            now=k;
            use[d[i].s]=0;
        }
    }
    vector<int> a(n+2);
    REP1(i,n) {
        if(use[i]) a[i]=od[i];
        else a[i]=-od[i];
    }
//    oparr(a)
    int asum=0;
    REP1(i,n+1) asum+=a[i];
//    ope(asum)
    int an=(s-asum)/m;
    REP1(i,n+1) {
        if(an+a[i]<0) {
            cout<<"-1\n";
            return 0;
        }
    }
//    if(asum!=s) {
//        cout<<"-1\n";
//        return 0;
//    }
    REP1(i,n+1) cout<<an+a[i]<<' ';
    cout<<'\n';
    return 0;
}
