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
const int maxn=1e5+5;
const int mod=1e9+7;
string s;
pii f(int u) {
    int ni=0,ai=0,an=1,mn=inf,mx=-inf;
    while(1) {
        if(isdigit(s[u])) ni=ni*10+(s[u]-'0');
        else if(s[u]=='+') {
            ai+=ni;
            ni=0;
        }
        else if(s[u]=='*') {
            an*=ai+ni;
            ai=0; ni=0;
        }
        else if(s[u]==',') {
            an*=ai+ni;
            mx=max(mx,an);
            mn=min(mn,an);
            an=1; ai=0; ni=0;
        }
        else if(s[u]==')') break;
        else {
            pii p=f(u+2);
            ni=p.f;
            u=p.s;
        }
        u++;
    }
    an*=ai+ni;
    mx=max(mx,an);
    mn=min(mn,an);
    return {mx-mn,u};
}
signed main()
{
    IOS();
    cin>>s;
    s+=",0)";
    cout<<f(0).f<<endl;
    return 0;
}
