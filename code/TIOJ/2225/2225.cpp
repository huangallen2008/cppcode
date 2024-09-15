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
const int mod=1e9+7;
int f(string s) {
    int r=0;
    REP(i,SZ(s)) r=r|(1<<(s[i]-'a'));
    return r;
}
signed main()
{
    IOS();
    int n;
    string s;
    cin>>n>>s;
    int x=f(s);
    vector<int> a(n);
    REP(i,n) {
        cin>>s;
        a[i]=f(s);
    }
    vector<int> an(4);
    int t=0;
    int p5=2;
    REP(i,n) {
        if(x==a[i]) continue;
        int r=(x&a[i]);
        if(r==0) an[0]++;
        else if(r==x) an[1]++;
        else if(r==a[i]) an[2]++;
        else {
            an[3]++;
            if(!t) t=r;
            else if(t!=r&&t!=(x&~r)) p5=0;
        }
    }
    REP(i,4) cout<<an[i]<<" ";
    cout<<p5<<"\n";
    return 0;
}
