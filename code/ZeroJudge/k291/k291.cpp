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
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<63)-1;
const int maxn=1e6+5;
const int mod=1e9+7;
vector<int> v;
int n;
signed main()
{
    IOS();
    cin>>n;
    v=vector<int>(n);
    REP(i,n) cin>>v[i];
    vector<int> px(n);
    px[0]=v[0];
    REP1(i,n-1) px[i]=max(px[i-1],v[i]);
    int mn=v[n-1];
    int an=1;
    RREP(i,n-1) {
        if(px[i]<=mn) {
            an++;
            mn=v[i];
        }
        else mn=min(mn,v[i]);
    }
    cout<<an<<endl;
    return 0;
}
