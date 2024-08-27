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
const int maxn=(1<<20);
const int maxv=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
const int rdm=rd(1<<30,1ll<<33);
struct chash {
    int operator()(const int x) const {
        return x^rdm;
    }
};
//shuffle(a,a+n,rng)
int d1[maxn],d2[maxn],a[41];
signed main() {
    IOS();
    int n,x;
    cin>>n>>x;
    REP(i,n) cin>>a[i];
    int n2=n>>1,nn=n-n2;
    int pn2=1<<n2,pnn=1<<nn;
    d1[0]=0,d2[0]=0;
    for(int i=1;i<pnn;i++) {
        int si=i&-i;
        d1[i]=d1[i^si]+a[__lg(si)];
    }
    for(int i=1;i<pn2;i++) {
        int si=i&-i;
        d2[i]=d2[i^si]+a[nn+__lg(si)];
    }
    unordered_map<int,int,chash> mp;

    REP(i,pn2) mp[d2[i]]++;
    int an=0;
    REP(i,pnn) if(mp.count(x-d1[i])) an+=mp[x-d1[i]];
    cout<<an<<'\n';
    return 0;
}
