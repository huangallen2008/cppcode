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
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<62);
const int maxn=2e5+5;
const int mod=1e9+7;
int pw(int x,int p) {
    int r=1;
    while(p>0) {
        if(p&1) {
            r*=x;
            r%=mod;
        }
        x*=x;
        x%=mod;
        p>>=1;
    }
    return r;
}
bool so(int a,int b) {
    return a>b;
}
void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pii>> p(n+1);
    REP(i,m) {
        int l,r;
        cin>>l>>r;
        p[l].pb({r+1,i});
    }
    int an=0,pl=0;
    vector<int> c1(m+1);
    map<int,int> c2;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    REP1(i,n) {
//    cout<<"ok"<<endl;
        REP(j,p[i].size()) pq.push(p[i][j]);
        while(pq.size()&&pq.top().f<=i) pq.pop();
        if(pq.size()==0) {
            pl++;
        }
        if(pq.size()==1) {
            c1[pq.top().s]++;
        }
    }
    while(pq.size()) pq.pop();
    REP1(i,n) {
        REP(j,p[i].size()) pq.push(p[i][j]);
        while(pq.size()&&pq.top().f<=i) pq.pop();
        if(pq.size()==2) {
            pii t=pq.top();
            pq.pop();
            int x=t.s,y=pq.top().s;
            int tt=min(x,y)*m+max(x,y);
            c2[tt]++;
            an=max(an,c2[tt]+c1[x]+c1[y]);
            pq.push(t);
        }
    }
    sort(ALL(c1),so);
    an=max(an,c1[0]+c1[1]);
    cout<<an+pl<<"\n";
}
signed main() {
    IOS();
    int T;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}
/*
6
2 3 2
1 2
1 2
1 1
5 3 2
1 3
2 4
3 5
10 6 2
1 5
6 10
2 2
3 7
5 8
1 4
100 6 2
1 100
1 100
1 100
1 100
1 100
1 100
1000 2 2
1 1
1 1
20 5 2
9 20
3 3
10 11
11 13
6 18

*/
