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
signed main()
{
    IOS();
    int n,l;
    cin>>n>>l;
    vector<int> c(n+2),h(n+2);
    vector<int> pre(n+2),nxt(n+2);
    h[0]=inf; h[n+1]=inf;
    c[0]=0;   c[n+1]=l;
    REP1(i,n) cin>>c[i];
    REP1(i,n) cin>>h[i];
    REP1(i,n+1) pre[i]=i-1;
    REP(i,n+1) nxt[i]=i+1;
    queue<int> q;
    REP1(i,n) if(c[i]-c[i-1]>=h[i]||c[i+1]-c[i]>=h[i]) q.push(i);
    pii an={0,0};
    while(q.size()) {
        int x=q.front();
        q.pop();
        if(x==0||x==n+1) continue;
        if(c[x]-c[pre[x]]>=h[x]||c[nxt[x]]-c[x]>=h[x]) {
            an.f++;
            an.s=max(an.s,h[x]);
            h[x]=inf;
            q.push(pre[x]);
            q.push(nxt[x]);
            nxt[pre[x]]=nxt[x];
            pre[nxt[x]]=pre[x];
        }
    }
    cout<<an.f<<"\n"<<an.s<<"\n";
    return 0;
}
