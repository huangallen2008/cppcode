#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for (int i = (a); i<(b); i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for (int i=(n)-1; i>=0; i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
const int maxn=1e6+5;
int n,m,q,a,b,an=0,c=1;
int p[maxn]={};
int s[maxn]={};
int find(int u) {
    if(p[u]==u) return u;
    return p[p[u]]=find(p[u]);
}
void merge(int u,int v) {
    int x=find(u),y=find(v);
    if(x!=y) {
        p[x]=y;
        s[y]+=s[x];
        an=max(an,s[y]);
    }
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    while(cin>>n>>m) {
        an=1;
        REP(i,n) {
            p[i]=i;
            s[i]=1;
        }
        REP(i,m) {
            cin>>a>>b;
            merge(a,b);
        }
        cout<<an<<"\n";
    }
    return 0;
}
