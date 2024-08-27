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
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const ll inf=(1ll<<63)-1;
const int maxn=2e5+5;
const ll mod=1e9+7;
struct N {
    int t,x,y;
};
int h,w;
bool ok(int x,int y) {
    if(x<0||y<0||x>=h||y>=w) return 0;
    return 1;
}
int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
signed main() {
    IOS();
    cin>>h>>w;
    vector<vector<bool>> m(h,vector<bool>(w));
    Graph o(h,vector<int>(w,inf));
    REP(i,h) {
        REP(j,w) {
            char x;
            cin>>x;
            if(x=='.') m[i][j]=1;
        }
    }
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    priority_queue<pipii,vector<pipii>,greater<pipii>> q;
    REP(i,n) {
        cin>>a[i]>>b[i];
        a[i]--,b[i]--;
        q.push({i,{a[i],b[i]}});
        o[a[i]][b[i]]=min(o[a[i]][b[i]],i);
    }
    REP(i,n) {
        int x=q.top().s.f,y=q.top().s.s,t=q.top().f;
        q.pop();
        if(t>=n-1) continue;
        REP(di,4) {
            int xx,yy;
            xx=x+d[di][0],yy=y+d[di][1];
            if(!ok(xx,yy)||!m[xx][yy]||o[xx][yy]<=t) continue;
            o[xx][yy]=t+1;
            q.push({t+1,{xx,yy}});
        }
    }
    vector<int> c(n);
    REP(i,h) {
        REP(j,w) {
            if(o[i][j]>=n) continue;
            c[o[i][j]]++;
            cout<<i<<" "<<j<<"\n";
        }
    }
    int p=0;
    REP(i,n) {
        p+=c[i];
        cout<<p<<"\n";
    }
    return 0;
}
/*
5 5
.....
.....
.....
.....
.....
3
3 3
3 3
3 3

5 5
..0..
.0.0.
..0..
.....
.....
2
2 3
2 3
*/
