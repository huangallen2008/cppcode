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
const int inf=(1ll<<62)-1;
const int maxn=2e5+5;
const int mod=1e9+7;
int n;
string a,b;
vector<int> c(11),an;
bool f(int u) {
    if(u>=n) return 0;
    int t=b[u]-'0';
    if(c[t]==0) {
        while(t<10) {
            if(c[t]>0) break;
            t++;
        }
        if(t==10) return 0;
        else {
            c[t]--;
            an.pb(t);
            return 1;
        }
    }
    else {
        c[t]--;
        an.pb(t);
        bool ok=f(u+1);
        if(ok) return 1;
        else {
            an.pop_back();
            c[t]++;
            t++;
            while(t<10&&c[t]==0) {
                if(c[t]>0) break;
                t++;
            }
            if(t==10) return 0;
            else {
                c[t]--;
                an.pb(t);
                return 1;
            }
        }
    }
}
signed main()
{
    IOS();
    cin>>a>>b;
    n=a.size();
    REP(i,n) c[a[i]-'0']++;
    bool ok=f(0);
    if(ok) {
        REP(i,an.size()) cout<<an[i];
        REP1(i,9) REP(j,c[i]) cout<<i;
        cout<<"\n";
    }
    else cout<<"QQ\n";
    return 0;
}
