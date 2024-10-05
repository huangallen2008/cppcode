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
const int maxn=10000;
const int inf=(1ll<<50);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();
    int n;
    cin>>n;
    int N=n*(n-1)>>1;
    vector<int> b(N);
    REP(i,N) cin>>b[i];
    sort(ALL(b));
    REP1(r,N-1) {
        if((b[r]+b[0]-b[1])&1) continue;
        int a0=b[0]-(b[r]+b[0]-b[1]>>1);
        vector<int> a(n);
        a[0]=a0;
        multiset<int> s;
        for(int &x:b) s.insert(x);
        int it=1;
        bool ok=1;
        while(it<n) {
            auto mn=*s.begin();
            a[it]=mn-a0;
            REP(i,it) {
                int sum=a[i]+a[it];
                if(s.find(sum)==s.end()) {
                    ok=0;
                    break;
                }
                s.erase(s.find(sum));
            }
            // oparr(a)oparr(s)
            it++;
            if(!ok) break;
        }
        // entr
        if(!ok) continue;
        REP(i,n) cout<<a[i]<<' ';
        cout<<'\n';
        break;
    }
    return 0;
}