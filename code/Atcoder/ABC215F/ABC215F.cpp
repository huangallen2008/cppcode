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
const int maxv=1e9+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int n;
vector<pii> a;
vector<int> smn,smx;
bool check(int d) {
    int r=0;
    REP(l,n) {
        while(r<n&&a[r].f-a[l].f<d) r++;
        if(r==n) break;
        if(max(abs(a[l].s-smn[r]),abs(a[l].s-smx[r]))>=d) return 1;
    }
    return 0;
}
signed main() {
    IOS();
    cin>>n;
    a=vector<pii>(n);
    smx=vector<int>(n+1);
    smn=vector<int>(n+1,inf);
    REP(i,n) cin>>a[i].f>>a[i].s;
    sort(ALL(a));
    RREP(i,n) {
        smn[i]=min(smn[i+1],a[i].s);
        smx[i]=max(smx[i+1],a[i].s);
    }
    int l=0,r=maxv,m;
    while(l<r) {//last m : check(m)==1
        m=l+r+1>>1;
        if(check(m)) l=m;
        else r=m-1;
    }
    cout<<l<<'\n';
    return 0;
}