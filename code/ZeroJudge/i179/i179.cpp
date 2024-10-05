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
vector<int> p,s,s1;
int find(int u) {
    if(p[u]==u) return u;
    return p[u]=find(p[u]);
}
void merge(int a,int b) {
    int x=find(a),y=find(b);
    if(x==y) return;
    p[x]=y;
    s[y]+=s[x];
    s1[y]+=s1[x];
}
signed main()
{
    IOS();
    int m,n,t;
    cin>>m>>n>>t;
    p=vector<int>(m+n);
    s=vector<int>(m+n,1);
    s1=vector<int>(m+n);
    REP(i,m+n) p[i]=i;
    REP(i,m) s1[i]=1;
    REP(i,t) {
        int x,y;
        cin>>x>>y;
        merge(x,y+m);
    }
    int an=0;
    REP(i,n+m) if(p[i]==i) an+=max(s[i]-s1[i],s1[i]);
    cout<<an<<"\n";
    return 0;
}
