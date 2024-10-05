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
int n,t,v;
signed main()
{
    IOS();
    int al=0,aw=0;
    cin>>n>>t>>v;
    vector<int> w(n),l(n),a(10001);
    REP(i,n) cin>>w[i]>>l[i];
    REP(i,n) al+=l[i];
    REP(i,n) aw+=w[i];
    REP(i,n) {
        for(int j=aw;j>=w[i];j--) {
            a[j]=max(a[j],a[j-w[i]]+l[i]);
        }
    }
    int an=inf;
    REP(i,aw+1) {
        a[i]=al-a[i]+max(i-t,(int)0)*v;
        an=min(an,a[i]);
    }
    cout<<an<<endl;
    return 0;
}
