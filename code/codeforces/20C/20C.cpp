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
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int, int>
#define pdd pair<double ,double>
#define pcc pair<char, char>
#define IOS() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mx(a,b) a=max(a,b)
#define mn(a,b) a=min(a,b)
const ll inf = 1ll<<60;
const int iinf=2147483647;
const ll maxn=1e5+5;
#define ai array<int,3>
int n,m,x,y,z;
int tt;
vector<int> an;
vector<pii> v[maxn];
pii a[maxn]={};
main()
{
    IOS();
    cin>>n>>m;
    priority_queue<ai,vector<ai>,greater<ai>> pq;
    REP(i,n) {
        a[i+1]={inf,-1};
    }
    a[1].f=0;
    REP(i,m) {
        cin>>x>>y>>z;
        v[x].pb({y,z});
        v[y].pb({x,z});
    }
    REP(i,SZ(v[1])) {
        pq.push({v[1][i].s,v[1][i].f,1});
    }
    while(SZ(pq)) {
        ai t=pq.top();
        pq.pop();
        if(t[0]<a[t[1]].f) {
            a[t[1]]={t[0],t[2]};
            REP(i,SZ(v[t[1]])) {
                pq.push({t[0]+v[t[1]][i].s,v[t[1]][i].f,t[1]});
            }
        }
    }
    if(a[n].s>0) {
        tt=n;
        while(tt>0) {
            an.pb(tt);
            tt=a[tt].s;
        }
        RREP(i,SZ(an)) {
            cout<<an[i]<<" ";
        }
    }
    else cout<<"-1";
    cout<<"\n";
    return 0;
}
