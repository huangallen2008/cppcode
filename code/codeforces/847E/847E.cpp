#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
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
const int mod=998244353;
const int maxn=3e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n;
vector<int> p,a;
bool check(int m) {
    int ac=0;
    REP(i,p.size()) {
        int end;
        if(p[i]>a[ac]+m) return 0;
        if(p[i]>a[ac]) end=max(p[i]+m-(p[i]-a[ac])*2,p[i]+(m-(p[i]-a[ac]))/2);
        else end=p[i]+m;
        while(ac<a.size()&&a[ac]<=end) ac++;
        if(ac==a.size()) return 1;
    }
    return 0;
}
signed main() {
    IOS();
    cin>>n;
    string s;
    cin>>s;
    REP(i,n) {
        if(s[i]=='P') p.pb(i);
        else if(s[i]=='*') a.pb(i);
    }
    int l=1,r=n*2,m;
    while(l<r) {
        m=l+r>>1;
        if(check(m)) r=m;
        else l=m+1;
    }
    cout<<l<<'\n';
    return 0;
}