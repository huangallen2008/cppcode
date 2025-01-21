#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
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
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int mod=998244353;
const int maxn=1e6+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) {
            r*=x;
            r%=mod;
        }
        x*=x;
        x%=mod;
        p>>=1;
    }
    return r;
}
int inv(int x) {
    return pw(x,mod-2);
}
signed main() {//1-base
    IOS();
    int n;
    cin>>n;
    vector<int> fac(n+1),infac(n+1),in(n+1);
    fac[0]=1;infac[0]=1;
    REP1(i,n) fac[i]=(fac[i-1]*i)%mod;
    REP1(i,n) in[i]=inv(i);
    REP1(i,n) infac[i]=(infac[i-1]*in[i])%mod;
    vector<int> cnt(n+1);
    REP(i,n) {
        int x;
        cin>>x;
        if(x==-1) cnt[0]++;
        else cnt[x]++;
    }
    int kcnt=0;
    int an=1;
    REP1(i,n) {
        if(cnt[i]>i) {
            cout<<"0\n";
            return 0;
        }
    }
    REP1(i,n) {
        if(cnt[i]>0) {
//                op(i)
            kcnt+=i;
            an=(((an*fac[i-1])%mod)*infac[i-cnt[i]])%mod;
        }
    }
    if(kcnt>n) {
        cout<<"0\n";
        return 0;
    }
//    ope(kcnt)ope(an)
    int nn=n-kcnt;
    vector<int> v;
    REP1(i,nn) {
        if(cnt[i]==0) {
            v.pb(i);
        }
    }

    vector<vector<int>> dp(n+1,vector<int>(n+1));
    REP(i,n+1) dp[i][0]=1;
    REP1(i,n) {
        for(int j=1;j<=n;j++) {
            if(cnt[i]==0&&j-i>=0)dp[i][j]=(dp[i][j]+(dp[i-1][j-i])*in[i])%mod;
            dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
//            cout<<dp[i][j]<<' ';
        }
//        cout<<'\n';
    }
//    oparr(cnt)
//    op(nn)ope(an)oparr(v)
//    oparr(dp)
//    ope((dp[n][nn]*fac[cnt[0]])%mod)
    an=(((an*dp[n][nn])%mod)*fac[cnt[0]])%mod;
    cout<<an<<'\n';
    return 0;
}
