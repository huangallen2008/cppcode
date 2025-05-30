#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
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
const int mod=1e9+7;
const int maxn=5;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1),id(n+1);
    REP1(i,n) cin>>a[i],id[a[i]]=i;
    vector<bool> used(n+1);
    REP1(i,n) {
        vector<int> mx(n+1,-inf),mn(n+1,inf);
        for(int j=i;j<=n;j++) {
            mx[j]=max(mx[j-1],a[j]);
            mn[j]=min(mn[j-1],a[j]);
        }
        // oparr(a)oparr(mx)oparr(mn)
        REP1(j,n) {
            if(used[j]) continue;
            if(mn[id[j]]>=j-k&&mx[id[j]]<=j+k) {
                used[j]=1;
                for(int l=id[j]-1;l>=i;l--) {
                    swap(a[l],a[l+1]);
                    swap(id[a[l]],id[a[l+1]]);
                }
                break;
            }
        }
    }
    REP1(i,n) cout<<a[i]<<' ';
    cout<<'\n';
    return 0;
}