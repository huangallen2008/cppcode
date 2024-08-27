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
void solve() {
    int n,l,r,s;
    cin>>n>>l>>r>>s;
    l--,r--;
    int len=r-l+1;
    int mnv=len*(len+1)>>1,mxv=len*(n+n-len+1)>>1;
    if(mnv>s||s>mxv) {
        cout<<"-1\n";
        return;
    }
    vector<int> an(n);
    int res=s-mnv;
    for(int i=l;i<=r;i++) an[i]=r-i+1;
    for(int i=l;i<=r;i++) {
        int nw=n+l-i;
        if(nw-an[i]>=res) {
            an[i]+=res;
            break;
        }
        else {
            res-=nw-an[i];
            an[i]=nw;
        }
    }
    bitset<505> used;
    for(int i=l;i<=r;i++) used[an[i]]=1;
    int it=1;
    REP(i,n) {
        if(l<=i&&i<=r) continue;
        while(used[it]) it++;
        an[i]=it;
        used[it]=1;
    }
    REP(i,n) cout<<an[i]<<' ';
    cout<<'\n';
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}