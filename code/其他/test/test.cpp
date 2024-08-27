#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,sse4,bmi,popcnt")
// #define int long long
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
// string dp0[maxn],dp1[maxn];
#define pipic pair<int,pair<int,char>>
#define int16 uint16_t
int16 dp[maxn][maxn];
// pipic max(string a,string b) { if(a.size()<b.size()) return b; return a; }
int16 mx(int16 a,int16 b) { if((a&1023)>(b&1023)) return a;return b; }
int16 pot(int x,int y,char z) {
    return x+(y<<10)+((z-'0')<<12);
}
pipic top(int16 x) {
    // ope(x)ope(x>>12)
    return {x&1023,{(x>>10)&3,'0'+(int)(x>>12)}};
}
int16 ud(int d0,char c) { auto d=top(d0); return pot(d.f+2,2,c); }
signed main() {
    IOS();
    string s;
    cin>>s;
    int n=s.size();
    vector<int> cnt(10);
    REP(i,n) {
        cnt[s[i]-'0']++;
    }
    REP(i,10) {
        if(cnt[i]>=1000) {
            REP(j,1000) cout<<i;
            cout<<'\n';
            return 0;
        }
    }
    // vector<pipii> dp0(n),dp1(n); 
    pii id={n,0};
    REP(i,n) dp[1][i]=pot(1,2,s[i]);
    bool ok=0;
    for(int l=2;l<=n;l++) {
        REP(i,n-l+1) {
            dp[l][i]=mx(pot(dp[l-1][i]&1023,0,'0'),pot(dp[l-1][i+1]&1023,1,'0'));
            if(s[i]==s[i+l-1]) dp[l][i]=mx(dp[l][i],ud(dp[l-2][i+1],s[i]));
            if(top(dp[l][i]).f>=1000) {
                id={l,i};
                ok=1;
                break;
            }
            // op(l)op(i)ope(top(dp[l][i]).f)
        }
        if(ok) break;
    }
    pii id0=id;
    string an="";
    while(id.f>0) {
        auto t=top(dp[id.f][id.s]);
        // op(dp[id.f][id.s])op(id.f)op(id.s)op(t.f)op(t.s.f)op((int)t.s.s)
        // bitset<16> b;ope(b=dp[id.f][id.s])
        // entr
        if(id.f==1) {
            an+=t.s.s;
            break;
        }
        // ope(an)
        if(t.s.f==2) {
            an+=t.s.s;
            id={id.f-2,id.s+1};
        }
        else if(t.s.f==0) {
            id={id.f-1,id.s};
        }
        else id={id.f-1,id.s+1};
    }
    string ans=an;
    if(top(dp[id0.f][id0.s]).f&1) an.pop_back();
    reverse(ALL(an));
    ans+=an;
    cout<<ans<<'\n';
    return 0;
}