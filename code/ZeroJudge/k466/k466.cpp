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
    int x,l;
    int n,m;
    cin>>n>>m;
    pii a={-1,-1},b={-1,-1};
    vector<pii> v(n);
    REP(i,n) {
        cin>>l;
        REP(j,m-1) {
            cin>>x;
            if(x>l) v[i].f+=x-l;
            else v[i].s+=l-x;
            l=x;
        }
        if(v[i].f>a.f) a={v[i].f,i};
        if(v[i].s>b.f) b={v[i].s,i};
    }
    cout<<a.s+1<<endl<<b.s+1<<endl;
    return 0;
}
