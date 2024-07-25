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
    int n,s,f;
    int x;
    int an=0;
    cin>>n>>s>>f;
    int c=0;
    int cn=0;
    vector<pair<bool,int>> v(1e4+5,{0,-1});
    REP(i,n) {
        cin>>x;
        if(!an) {
            if(v[x].f) {
                if(x==f&&c+1==s) {
                    an=v[x].s;
                    continue;
                }
                cn++;
                v[x].f=0;
            }
            else {
                v[x]={1,i+1-cn};
            }
            if(x==f) c++;
            if(c==s) an=i+1-cn;
        }
    }
    cout<<an<<endl;
    return 0;
}
