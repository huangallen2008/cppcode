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
const int maxn=2e5+5;
const int inf=(1ll<<30);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int col(char c) {
    if(c=='R') return 0;
    if(c=='G') return 1;
    if(c=='B') return 2;
    if(c=='Y') return 3;
}
void solve() {
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    REP(i,n) {
        string s;
        cin>>s;
        v[i]|=(1<<col(s[0]))|(1<<col(s[1]));
    }
    // oparr(v)
    vector<int> in;
    int lv=-1;
    REP(i,n) {
        int val=min(v[i],v[i]^15);
        if(val!=lv) {
            in.pb(i);
            lv=val;
        }
        // op(i)ope(val)
    }
    // oparr(in)
    while(q--) {
        int x,y;
        cin>>x>>y;
        x--,y--;
        if((v[x]&v[y])!=0) {
            cout<<abs(x-y)<<'\n';
            continue;
        }
        if(x>y) swap(x,y);
        int li=upper_bound(ALL(in),x)-in.begin();
        int ri=upper_bound(ALL(in),y)-in.begin();
        if(li!=ri) {
            cout<<abs(x-y)<<'\n';
            continue;
        }
        // op(li)ope(ri)
        int ll=-inf,rr=inf;
        if(li>1)ll=in[li-1]-1;
        // oparr(in)
        if(ri<in.size()) rr=in[ri];
        // op(ll)op(rr)
        int an=min((x-ll)*2+y-x,(rr-y)*2+y-x);
        if(an>=n*3) cout<<"-1\n";
        else cout<<an<<'\n';
    }
}
signed main() {
    IOS();
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}
