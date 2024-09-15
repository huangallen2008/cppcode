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
const int maxn=1e4+5;
int n,m,q,a,b;
int p[maxn]={};
int find(int u) {
    if(p[u]==u) return u;
    return p[p[u]]=find(p[u]);
}
void merge(int u,int v) {
    int x=find(u),y=find(v);
    if(x!=y) {
        p[x]=p[y];
    }
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>m>>q;
    REP1(i,n) {
        p[i]=i;
    }
    REP(i,m) {
        cin>>a>>b;
        merge(a,b);
    }
    REP(i,q) {
        cin>>a>>b;
        if(find(a)==find(b)) cout<<":)\n";
        else cout<<":(\n";
    }
    return 0;
}
