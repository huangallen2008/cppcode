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
const int inf=(1ll<<62);
const int maxn=1e5+5;
const int mod=1e9+9;
signed main()
{
    IOS();
    int n;
    cin>>n;
    if(n%2==1) {
        if(n<=11) cout<<"-1\n";
        else {
            int a=(n-11)/2,b=n-a;
            cout<<913;
            REP(i,n-13) cout<<1;
            cout<<"\n";
        }
    }
    else {
        REP(i,n) cout<<"1";
        cout<<"\n";
    }
    return 0;
}
