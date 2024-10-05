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
    int T;
    cin>>T;
    while(T--) {
        int an=0;
        vector<vector<int>> a(5,vector<int>(5));
        REP(i,5) {
            int n;
            cin>>n;
            REP(j,n) {
                string s;
                cin>>s;
                if(s[0]=='J') a[i][0]=1;
                if(s[0]=='M') a[i][1]=1;
                if(s[0]=='T') a[i][2]=1;
                if(s[0]=='S') a[i][3]=1;
                if(s[0]=='A') a[i][4]=1;
            }
        }
        REP(c1,5) {
            REP(c2,5) {
                if(c2==c1) continue;
                REP(c3,5) {
                    if(c3==c2||c3==c1) continue;
                    REP(c4,5) {
                        if(c4==c3||c4==c2||c4==c1) continue;
                        REP(c5,5) {
                            if(c5==c4||c5==c3||c5==c2||c5==c1) continue;
                            if(a[0][c1]&&a[1][c2]&&a[2][c3]&&a[3][c4]&&a[4][c5]) an++;
                        }
                    }
                }
            }
        }
        cout<<an<<"\n";
    }
    return 0;
}
