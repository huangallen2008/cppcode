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
const int maxn=5e4+5;
int n,m,q,a,b,an=0,c=1;
int p[maxn]={};
int find(int u) {
    if(p[u]==u) return u;
    return p[p[u]]=find(p[u]);
}
void merge(int u,int v) {
    int x=find(u),y=find(v);
    if(x!=y) {
        p[x]=p[y];
        an--;
    }
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    while(cin>>n>>m) {
        if(n==0) break;
        an=n;
        REP1(i,n) {
            p[i]=i;
        }
        REP(i,m) {
            cin>>a>>b;
            merge(a,b);
        }
        cout<<"Case "<<c++<<": "<<an<<"\n";
    }
    return 0;
}
