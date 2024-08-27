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
const int inf=(1ll<<62);
const int maxn=1e6+5;
const int mod=1e9+7;
vector<int> p(maxn),sz(maxn,1);
int find(int u) {
    if(p[u]==u) return u;
    return p[u]=find(p[u]);
}
void merge(int a,int b) {
    int x=find(a),y=find(b);
    if(x==y) return;
    p[x]=y;
    sz[y]+=sz[x];
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    REP(i,n*m) p[i]=i;
    vector<vector<int>> a(n,vector<int>(m));
    bool ok=0;
    REP(i,n) {
        REP(j,m) {
            char c;
            cin>>c;//udlr 8421
            if(c=='X') a[i][j]=15;
            if(c=='H') a[i][j]=3;
            if(c=='I') a[i][j]=12;
            if(c=='L') a[i][j]=9;
            if(c=='F') a[i][j]=5;
            if(c=='J') a[i][j]=10;
            if(c=='7') a[i][j]=6;
            if(c=='0') a[i][j]=0;
            if(c!='0') ok=1;
            if(i>0) if((a[i-1][j]&4)>0&&(a[i][j]&8)>0) merge(i*m+j,(i-1)*m+j);
            if(j>0) if((a[i][j-1]&1)>0&&(a[i][j]&2)>0) merge(i*m+j,i*m+(j-1));
        }
    }
    if(!ok) {
        cout<<0<<"\n";
    }
    else {
        int an=0;
        REP(i,n*m) an=max(an,sz[i]);
        cout<<an<<"\n";
    }
    return 0;
}
