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
const int inf=(1ll<<62)-1;
const int maxn=2e5+5;
const int mod=1e9+7;
signed main()
{
    IOS();
    int n,m;
    cin>>n>>m;
    vector<priority_queue<int>> a(m+1);
    REP(i,n) {
        int w,c;
        cin>>w>>c;
        if(w>m) continue;
        a[w].push(c);
    }
    REP(i,m) {
        while(a[i].size()) {
            int u=a[i].top();
            a[i].pop();
            if(a[i].size()) {
                u+=a[i].top();
                a[i].pop();
            }
            a[i+1].push(u);
        }
    }
    int an=0;
    while(a[m].size()) {
        an=max(an,a[m].top());
        a[m].pop();
    }
    cout<<an<<"\n";
    return 0;
}
