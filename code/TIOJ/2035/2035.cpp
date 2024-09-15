#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+7;
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) r*=x;
        x*=x;
        p>>=1;
    }
    return r;
}
signed main()
{
    IOS();
    int b;
    string s;
    cin>>b>>s;
    int r1=0,r2=0;
    REP(i,s.size()) {
        int u=s[i]-'0';
        r1+=u*pw(b,s.size()-i-1);
        r2+=pw(u,s.size());
    }
    if(r1==r2) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}