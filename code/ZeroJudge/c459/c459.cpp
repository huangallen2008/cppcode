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
const int inf=(1ll<<63)-1;
const int maxn=2e5+5;
const int mod=1e9+7;
int pw(int x,int p) {
    if(p==0) return 1;
    return pw(x,p-1)*x;
}
signed main()
{
    IOS();
    int b;
    string s;
    cin>>b>>s;
    int n=s.size();
    int t=0;
    REP(i,n) t+=pw(b,n-i-1)*(s[i]-'0');
    int r=0;
    REP(i,n) r+=pw(s[i]-'0',n);
    if(t==r) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
