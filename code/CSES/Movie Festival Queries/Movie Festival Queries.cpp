#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
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
signed main() {
    IOS();
    int n,q;
    cin>>n>>q;
    vector<pii> a0(n);
    REP(i,n) cin>>a0[i].f>>a0[i].s;
    sort(ALL(a0),[&](pii a,pii b) { if(a.s==b.s) return a.f>b.f; return a.s<b.s; });
    vector<pii> a;
    REP(i,n) {
        if(a.size()&&a0[i].f<=a.back().f) continue;
        a.pb(a0[i]);
    }
    n=a.size();
    vector<int> nxt(n+1);
    int r=0;
    REP(i,n) {
        while(r<n&&a[r].f<a[i].s) r++;
        nxt[i]=r;
    }
    nxt[n]=n;
    vector<vector<int>> st(20,vector<int>(n+1));
    REP(i,n+1) st[0][i]=nxt[i];
    REP1(i,19) {
        REP(j,n+1) {
            st[i][j]=st[i-1][st[i-1][j]];
        }
    }
    REP(i,q) {
        int l,r;
        cin>>l>>r;
        int it_l=lower_bound(ALL(a),make_pair(l,(int)0))-a.begin();\
        if(a[it_l].s>r) {
            cout<<"0\n";
            continue;
        }
        int now=it_l,an=0;
        RREP(j,20) {
            if(st[j][now]<n&&a[st[j][now]].s<=r) now=st[j][now],an|=1<<j;
        }
        cout<<an+1<<'\n';
    }
    return 0;
}