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
    int n;
    int x;
    cin>>n;
    vector<int> v(n),a,b;
    REP(i,n) {
        cin>>v[i];
    }
    REP(i,n) {
        cin>>x;
        if(x>v[i]) b.pb(i);
        else a.pb(i);
    }
    if(a.size()==0) cout<<"-1";
    for(int x:a) cout<<x+1<<" ";
    cout<<endl;
    if(b.size()==0) cout<<"-1";
    for(int x:b) cout<<x+1<<" ";
    cout<<endl;
    return 0;
}
