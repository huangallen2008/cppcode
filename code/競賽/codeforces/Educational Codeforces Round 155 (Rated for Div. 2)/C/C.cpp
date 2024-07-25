#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,(n)+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<63)-1;
const int maxn=2e5+5;
const int mod=998244353;
vector<int> f(maxn);
void solve() {
    string s;
    cin>>s;
    int n=s.size();
    int c=1;
    int an1=0,an2=1;
    for(int i=1;i<n;i++) {
        if(s[i]==s[i-1]) {
            c++;
            if(i==n-1) {
                an1+=c-1;
                an2=(an2*f[c])%mod;
            }
        }
        else {
            an1+=c-1;
            an2=(an2*f[c])%mod;
            c=1;
        }
    }
    cout<<an1<<" "<<an2<<"\n";
}
signed main() {
    IOS();
    f[0]=1;
    for(int i=1;i<maxn;i++) f[i]=(f[i-1]*i)%mod;
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
