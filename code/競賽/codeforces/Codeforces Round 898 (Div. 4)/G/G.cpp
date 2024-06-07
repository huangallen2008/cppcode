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
const int mod=1e9+7;
void solve() {
    string s;
    cin>>s;
    int n=s.size();
    bool ok=0;
    if(s[0]=='B'||s[n-1]=='B') ok=1;
    REP1(i,n) {
        if(s[i]=='B'&&s[i-1]=='B') ok=1;
    }
    int mn=inf,r=0,an=0;
    REP(i,n) {
        if(s[i]=='A') {
            r++;
            if(i==n-1) mn=min(mn,r);
        }
        else {
            mn=min(mn,r);
            r=0;
        }
        an+=(s[i]=='A');
    }
    if(an==0) cout<<"0\n";
    else if(an==n) cout<<"0\n";
    else if(ok) cout<<an<<"\n";
    else cout<<an-mn<<"\n";
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
