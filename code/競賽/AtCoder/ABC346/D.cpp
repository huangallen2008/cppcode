#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops")
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
const int maxn=255;
const int maxv=1e5+5;
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
    vector<bool> s(n+1);
    REP1(i,n) {char c;cin>>c;s[i]=c=='1';}
    vector<int> a(n+1);
    REP1(i,n) cin>>a[i];
    vector<int> p1(n+1),p0(n+1),s1(n+2),s0(n+2);
    REP1(i,n) {
        p1[i]=p0[i-1]+(s[i]?0:a[i]);
        p0[i]=p1[i-1]+(s[i]?a[i]:0);
    }
    RREP1(i,n) {
        s1[i]=s0[i+1]+(s[i]?0:a[i]);
        s0[i]=s1[i+1]+(s[i]?a[i]:0);
    }
//    oparr(p0)oparr(p1)
    int an=inf;//min(p1[n],p0[n]);
//    ope(an)
    REP1(i,n-1) {
        an=min(an,min(p0[i]+s0[i+1],p1[i]+s1[i+1]));
    }
//    vector<int> dp00(n+1),dp01(n+1),dp10(n+1),dp11(n+1);//{same,ith}
//    REP1(i,n) {
//        dp00[i]=dp01[i-1];
//        dp01[i]=dp00[i-1];
////        dp10[i]=dp11[i-1];
////        dp11[i]=dp10[i-1];
//        dp10[i]=min(dp11[i-1],dp00[i-1]);
//        dp11[i]=min(dp10[i-1],dp01[i-1]);
//        if(s[i]) {
//            dp00[i]+=a[i];
//            dp10[i]+=a[i];
//        }
//        else {
//            dp01[i]+=a[i];
//            dp11[i]+=a[i];
//        }
//    }
//    int an=min(dp10[n],dp11[n]);
    cout<<an<<'\n';
    return 0;
}
