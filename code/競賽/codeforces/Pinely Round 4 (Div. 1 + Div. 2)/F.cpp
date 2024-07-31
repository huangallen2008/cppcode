#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
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
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
bool okt(int a,int b,int c) {
    return a+b>c&&a+c>b&&c+b>a;
}
void solve() {
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    REP(i,n) cin>>a[i];
    vector<vector<int>> t={{0,1,2,3,4,5},{0,1,3,2,4,5},{0,1,4,2,3,5},{0,1,5,2,3,4},{0,2,3,1,4,5},{0,2,4,1,3,5},{0,2,5,1,3,4},{0,3,4,1,2,5},{0,3,5,1,2,4},{0,4,5,1,2,3}};
    REP(rd,q) {
        int l,r;
        cin>>l>>r;
        l--;
        if(r-l>=50) {
            cout<<"YES\n";
            continue;
        }
        vector<int> v;
        for(int i=l;i<r;i++) v.pb(a[i]);
        sort(ALL(v));
        bool ok=0;
        int len=r-l;
        int cnt=0;
        REP(i,r-l-2) {
            if(okt(v[i],v[i+1],v[i+2])) {
                cnt++,i+=2;
                if(cnt>=2) break;
            }
        }
        if(cnt>=2) {
            cout<<"YES\n";
            continue;
        }
        REP(i,r-l-5) {
            for(auto tt:t) {
                if(v[i+tt[0]]+v[i+tt[1]]>v[i+tt[2]]&&v[i+tt[3]]+v[i+tt[4]]>v[i+tt[5]]) {
                    ok=1;
                    break;
                }
            }
            if(ok) break;
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
signed main() {
    IOS();
    // int T;
    // cin>>T;
    // while(T--) 
        solve();
    return 0;
}