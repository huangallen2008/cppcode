#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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
const ll inf=(1ll<<63)-1;
const int maxn=1e5+5;
const ll mod=1e9+7;
int n;
string s;
bool ok(int x,int y) {
    if(x<0||y<0||x>2) return 0;
    if(x==0&&y>9) return 0;
    if(x==1&&y>8) return 0;
    if(x==2&&y>6) return 0;
    return 1;
}
int ti(char c) { return c-'A'; }
//vector<string> mp={"QWSZ","VGHN","XDFV","SERFCX","WSDR","RDCVGT","TFVBHY","YGBNJU","UJKO","UHNMKI","IJMLO","OKP","JNK","BHJM","IKLP","OL","AW","EDFT","WAZXDE","RFGY","YHJI","CFGB","QASE","ZSDC","TGHU","ASX"};
vector<string> mp={"QWERTYUIOP",
                    "ASDFGHJKL",
                    "ZXCVBNM"};
vector<pii> di={{0,1},{0,-1},{-1,0},{-1,1},{1,-1},{1,0}};
vector<vector<int>> v(26,vector<int>(26));
signed main() {
    IOS();
    REP(t,26) {
        queue<pii> q;
        int c;
        if(t>18) { q.push({2,t-19}); c=ti(mp[2][t-19]); }
        else if(t>9) { q.push({1,t-10}); c=ti(mp[1][t-10]); }
        else { q.push({0,t}); c=ti(mp[0][t]); }
//        cout<<c<<"\n";
        while(SZ(q)) {
            int x=q.front().f,y=q.front().s;
            q.pop();
            REP(i,SZ(di)) {
                int xx=x+di[i].f,yy=y+di[i].s;
                if(!ok(xx,yy)) continue;
                if(v[c][ti(mp[xx][yy])]) continue;
                q.push({xx,yy});
                v[c][ti(mp[xx][yy])]=v[c][ti(mp[x][y])]+1;
            }
        }
    }
    cin>>n>>s;
    s=" "+s;
//    cout<<"  ";
//    REP(i,26) cout<<(char)('A'+i)<<" ";cout<<"\n";
//    REP(i,26) {
//        cout<<(char)('A'+i)<<" ";
//        REP(j,26) cout<<v[i][j]<<" ";cout<<"\n";
//    }
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(26,vector<int>(26)));
    REP(i,26) REP(j,26) dp[n][i][j]=0;
    RREP(i,n) {
        REP(j,26) {
            REP(k,26) {
                if(i==0) dp[i][j][k]=0;
                int id=ti(s[i+1]);
                dp[i][j][k]=min(dp[i+1][id][k]+v[j][id],dp[i+1][j][id]+v[k][id]);
            }
        }
    }
    cout<<dp[0][ti('F')][ti('J')]<<"\n";
    return 0;
}
