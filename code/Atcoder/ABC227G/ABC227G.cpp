#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
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
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &mken:(x)) cout<<mken<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=998244353;
const int maxn=1e6+1;
const int maxv=31700;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
bitset<maxn> isp;
signed main() {
    IOS();
    isp.set();
    isp[0]=isp[1]=0;
    for(int i=2;i<maxn;i++) {
        if(isp[i]) {
            for(int j=i+i;j<maxn;j+=i) isp[j]=0;
        }
    }
    Vi prime;
    REP(i,maxn) if(isp[i]) prime.pb(i);
    int n;
    int k;
    Vi cnt(maxn);
    cin>>n>>k;
    Vi a(k),b(k);
    REP(i,k) a[i]=n-i;
    REP(i,k) b[i]=i+1;
    for(int p:prime) {
        for(int i=n%p;i<k;i+=p) {
            while(a[i]%p==0) {
                a[i]/=p;
                cnt[p]++;
            }
        }
        for(int i=p-1;i<k;i+=p) {
            while(b[i]%p==0) {
                b[i]/=p;
                cnt[p]--;
            }
        }
    }
    map<int,int> mp;
    REP(i,k) if(a[i]>1) mp[a[i]]++;
    int an=1;
    REP(i,maxn) if(cnt[i]) an=an*(cnt[i]+1)%mod;
    for(auto &[x,y]:mp) {
        an=an*(y+1)%mod;
    }
    cout<<an<<'\n';
    return 0;
}