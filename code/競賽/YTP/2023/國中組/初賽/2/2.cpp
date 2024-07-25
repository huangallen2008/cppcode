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
    vector<vector<int>> a(n,vector<int>(3));
    vector<int> b(3);
    REP(i,n) {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        sort(ALL(a[i]));
    }
    cin>>b[0]>>b[1]>>b[2];
    sort(ALL(b));
    int an=0;
    REP(i,n) {
        if(b[0]<=a[i][0]&&b[1]<=a[i][1]&&b[2]<=a[i][2]) an++;
    }
    cout<<an<<"\n";
    return 0;
}
