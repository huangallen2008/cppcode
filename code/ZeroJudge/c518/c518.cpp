#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const ll inf=(1ll<<63)-1;
const int maxn=2e5+5;
const ll mod=1e9+7;
string a,s,t;
vector<vector<int>> c(62);
int id(char c) {
    if(isdigit(c)) return c-'0';
    if(isupper(c)) return c-'A'+10;
    return c-'a'+36;
}
int itc(int x) {
    if(x<10) return '0'+x;
    if(x<36) return 'A'+x-10;
    return 'a'+x-36;
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    cin>>a>>s>>t;
    REP(i,62) c[i].pb(i);
    REP(i,m) {
        int x=id(s[i]),y=id(t[i]);
        RREP(j,c[x].size()) {
            c[y].pb(c[x][j]);
            c[x].pop_back();
        }
    }
    vector<int> t(62);
    REP(i,62) {
        for(int v:c[i]) t[v]=i;
    }
    REP(i,n) cout<<(char)itc(t[id(a[i])]);
    cout<<"\n";
    return 0;
}
