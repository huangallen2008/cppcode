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
const int inf=(1ll<<62)-1;
const int maxn=2e5+5;
const int mod=1e9+7;
string pl(string a,string b) {
    int x=a.size(),y=b.size();
    string c="";
    int ne=0;
    REP(i,max(x,y)) {
        int t=ne;
        if(i<x) t+=a[x-i-1]-'0';
        if(i<y) t+=b[y-i-1]-'0';
        ne=t/10;
        c=(char)('0'+t%10)+c;
    }
    if(ne>0) c=(char)('0'+ne)+c;
    return c;
}
string mi(string a,string b) {
    int x=a.size(),y=b.size();
    int ne=0;
    string c="";
    REP(i,x) {
        int t=(a[x-i-1]-'0')-ne;
        ne=0;
        if(i<y) t-=(b[y-i-1]-'0');
        if(t<0) {
            ne=1;
            t+=10;
        }
        c=(char)('0'+t)+c;
    }
    string d="";
    bool is0=0;
    REP(i,c.size()) {
        if(c[i]!='0') is0=1;
        if(is0) d+=c[i];
    }
    if(d.size()==0) return "0";
    return d;
}
signed main()
{
    IOS();
    int n,m,d;
    cin>>n>>m>>d;
    vector<string> dp(n+1);
    vector<bool> b(n,0);
    string p;
    REP(i,d) {
        int x;
        cin>>x;
        b[x]=1;
    }
    dp[0]="1";
    p="1";
    REP1(i,n) {
        if(b[i]) dp[i]="0";
        else dp[i]=p;
        p=pl(p,dp[i]);
        if(i>=m) p=mi(p,dp[i-m]);
    }
    cout<<dp[n]<<"\n";
    return 0;
}
