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
const int maxn=1e7+1;
const int maxv=1e6+5;
const int inf=1e9+1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
#ifdef LOCAL
#define GC _getchar_nolock()
#define PC _putchar_nolock
#else 
#define GC getchar_unlocked()
#define PC putchar_unlocked
#endif
bool ok(char c1,char c2) {
    int t=(c1-'0')*10+(c2-'0');
    if(1<=t&&t<=26&&c1!='0') return 1;
    return 0;
}
void solve(int C) {
    cout<<"Case #"<<C<<": ";
    string s;
    cin>>s;
    int k;
    cin>>k;
    k--;
    int n=s.size();
    int cnt=0;
    //n=1
    if(s.back()=='?') {
        if(s[n-2]=='?') {
            int rr=k%15;
            k/=15;
            if(rr>5) {
                s[n-2]='1';
                s[n-1]='0'+15-rr;
            }
            else {
                s[n-2]='2';
                s[n-1]='0'+6-rr;
            }
        }
        else {
            int t=s[n-2]-'0';
            if(t!=2) {
                s[n-1]='9'-k%9;
                k/=9;
            }
            if(t==2) {
                s[n-1]='6'-k%6;
                k/=6;
            }
        }
    }
    RREP(i,n-1) {
        if(s[i]=='?'&&s[i+1]!='?'&&s[i+1]-'0'>6) s[i]='1';
    }
    RREP(i,n-1) {
        if(s[i]=='?') s[i]='2'-((k>>cnt++)&1);
    }
    cout<<s<<' ';
    s="$"+s;
    Vi dp(n+1);
    dp[0]=1;
    REP1(i,n) {
        if(ok(s[i-1],s[i])) dp[i]=(dp[i]+dp[i-2])%mod;
        if(s[i]!='0')dp[i]=(dp[i]+dp[i-1])%mod;
    }
    // entr
    // oparr(dp)
    cout<<dp[n]<<'\n';
    // entr
}
signed main() {
    IOS(); 

    #ifdef LOCAL_
        freopen("vin.txt","r",stdin);
        freopen("vout.txt","w",stdout);
    #endif
    int T;
    cin>>T;
    REP1(t,T) solve(t);
    return 0;
}