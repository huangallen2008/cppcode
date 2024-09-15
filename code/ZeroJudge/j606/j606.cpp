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
int k,q,r;
vector<int> e;
vector<string> an;
void f(string &a) {
    string b(k,' ');
    REP(i,k) b[e[i]-1]=a[i];
    a=b;
    REP(i,r) an[i]+=b[i];
}
signed main()
{
    IOS();
    cin>>k>>q>>r;
    e=vector<int>(k);
    an=vector<string>(r,"");
    string p;
    cin>>p;
    REP(i,q) {
        REP(j,k) cin>>e[j];
        f(p);
    }
    REP(i,r) cout<<an[i]<<endl;
    return 0;
}
