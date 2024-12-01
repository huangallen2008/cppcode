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
const int maxn=5e5+5;
const int maxb=20;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS(); 
    int n;
    int co[2];
    cin>>n>>co[0]>>co[1];
    string s;
    cin>>s;
    s+='.';
    n++;
    Vi cnt(n);
    Vi dp(2);
    int fir=-1;
    auto hco=[&](char a,char b) {
        return (a=='K'&&b=='D')||(a=='D'&&b=='K');
    };
    REP(i,n) {
        if(i>=2) {
            if(hco(s[i],s[i-2])&&s[i-1]!='.') cnt[i]=cnt[i-2]+1;
        }
        if(s[i]=='.') {
            if(i==0) continue;
            Vi ndp(2);
            ndp[0]=cnt[i]*co[0]+cnt[i-1]*co[1];
            ndp[1]=cnt[i]*co[1]+cnt[i-1]*co[0];
            if(fir!=-1) {
                int dif=((i-fir)&1)^1;
                ndp[0]+=min(dp[0^dif]+co[0^dif]*hco(s[fir],s[fir-2]),dp[1^dif]);
                ndp[1]+=min(dp[1^dif]+co[1^dif]*hco(s[fir],s[fir-2]),dp[0^dif]);
            }
            op(i)oparr(cnt)oparr(dp)oparr(ndp)entr
            swap(ndp,dp);
            fir=i+1;
        }
    }
    oparr(cnt)
    int an=min(dp[0],dp[1]);
    cout<<an<<'\n';
    return 0;
}