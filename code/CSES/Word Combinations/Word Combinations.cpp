#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
#pragma GCC target("avx2,bmi,popcnt")
//#define int long long
#define ll long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define md(x) ((x)%mod+mod)%mod
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<endl;
#define entr cout<<endl;
const int inf=(1ll<<62);
const int maxn=5e3+5;
const int maxk=1e5+5;
const int mod=1e9+7;
ll p26[maxn],ps[maxn],dp[maxn];
pair<ll,int> v[maxk];
signed main() {
    IOS();
    string s;
    cin>>s;
    int n=s.size();
    p26[0]=1;
    REP1(i,n) p26[i]=((p26[i-1]<<4)+(p26[i-1]<<3)+(p26[i-1]<<1))%mod;
    REP1(i,n) ps[i]=(ps[i-1]+(s[i-1]-'a')*p26[i])%mod;
    int k;
    cin>>k;
    int cnt=0;
    REP(i,k) {
        string t;
        cin>>t;
        if(t.size()>n) continue;
        ll l=0;
        REP(j,t.size()) l=(l+(t[j]-'a')*p26[j+1])%mod;
        v[cnt++]={l,t.size()};
    }
    dp[0]=1;
    REP1(i,n) {
        REP(j,cnt) {
            if(v[j].s>i) continue;
            int l=i-v[j].s;
            if((ps[i]-ps[l]-v[j].f*p26[l])%mod==0) dp[i]=(dp[i]+dp[l])%mod;
        }
    }
    cout<<md(dp[n])<<'\n';
    return 0;
}