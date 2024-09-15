#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,popcnt")
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
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
bool check(int n,int p,int m) {
    if((p+m+n)&1) return 0;
    int x=(p+m-n)>>1,y=(p-m+n)>>1;
    cout<<x+1<<' '<<y+1<<'\n';
    return 1;
}
void solve() {
    int n,m;
    cin>>n>>m;
    int pmx=-inf,pmn=inf,mmx=-inf,mmn=inf;
    pii p1,p2,p3,p4;
    REP(i,n) {
        string s;
        cin>>s;
        REP(j,m) {
            if(s[j]=='B') {
                if(i+j>pmx) {
                    pmx=i+j;
                    p1={i,j};
                }
                if(i+j<pmn) {
                    pmn=i+j;
                    p2={i,j};
                }
                if(i-j>mmx) {
                    mmx=i-j;
                    p3={i,j};
                }
                if(i-j<mmn) {
                    mmn=i-j;
                    p4={i,j};
                }
            }
        }
    }
    vector<pii> imp={p1,p2,p3,p4};
    pii an={0,0};
    int now=inf;
    REP(i,n) {
        REP(j,m) {
            int dis=0;
            for(auto [x,y]:imp) dis=max(dis,abs(x-i)+abs(y-j));
            if(dis<now) {
                now=dis;
                an={i,j};
            }
        }
    }
    cout<<an.f+1<<' '<<an.s+1<<'\n';
    // ope(now)
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}