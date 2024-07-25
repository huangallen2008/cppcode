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
    bool ok=1;
    int s,e,b,k;
    cin>>s>>e>>b>>k;
    for(int i=s;i<=e;i++) {
        if(i%b==0||i%10==b||((int)(i/10)%10==b&&i>=10)||((int)(i/100)==b&&i>=100)) k--;
        if(k==0) {
            cout<<i<<endl;
            ok=0;
            break;
        }
    }
    if(ok) cout<<"-1\n";
    return 0;
}
