#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define op(x) cout<<(#x)<<"="<<x<<", ";
#define ope(x) cout<<(#x)<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int mod=1e9+7;
const int maxn=1e6+5;
const int inf=(1ll<<62);
vector<string> m;
bool ser(int x,int y) {
    if(x<0||x>=m.size()||y<0||y>=m[0].size()) return 1;
    return m[x][y]=='*';
}
signed main() {
    IOS();
    freopen("maze.txt","r",stdin);
    string s;
    while(getline(cin,s)) {
        m.pb(s);
    }
    REP(i,m.size()) {
        REP(j,m[i].size()) {
            if(i%2==0&&j%2==0) {
                cout<<"+";
            }
            else {
                if(m[i][j]=='*') {
                    if(ser(i,j-1)&&ser(i,j+1)) cout<<"-";
                    else cout<<"|";
                }
                else cout<<" ";
            }
        }
        entr
    }
    return 0;
}
