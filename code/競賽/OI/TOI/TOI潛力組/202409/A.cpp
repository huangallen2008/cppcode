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
const int mod=1e9+7;
const int maxn=5;
const int maxv=31700;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n,k;
    cin>>n>>k;
    vector<Vi> d(n,Vi(5));
    REP(i,n) {
        REP1(j,4) cin>>d[i][j];
        d[i][0]=i;
    }
    Vi o(k+2);
    o[k+1]=-1;
    REP1(i,k) cin>>o[i];
    vector<pii> so;
    Vi vis(5);
    int id=-1,cnt=1;
    reverse(ALL(o));
    o.pb(-1);
    REP1(i,o.size()-1) {
        if(o[i]==o[i-1]) {
            cnt++;
        }
        else {
            if(id!=-1) {
                if(!vis[id]) {
                    vis[id]=1;
                    if(cnt&1) so.pb({id,1});
                    else so.pb({id,-1});
                }
            }
            cnt=1;
            id=o[i];
        }
    }
    sort(ALL(d),[&](Vi a,Vi b) {
        for(auto [id,f]:so) {
            if(a[id]*f!=b[id]*f) return a[id]*f<b[id]*f;
        }
        return 0;
    });
    REP(i,n) {
        REP1(j,4) cout<<d[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}