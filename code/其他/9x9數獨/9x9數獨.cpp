#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
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
const int maxn=2e5+5;
const ll mod=1e9+7;
int wv(int i,int j) {
    return ((int)(i/3))*3+(int)(j/3);
}
bool ok=1;
vector<vector<bool>> r(10,vector<bool>(10)),c(10,vector<bool>(10)),v(10,vector<bool>(10));
vector<vector<int>> m(10,vector<int>(10)),an(10,vector<int>(10));
bool d(int u) {
    if(u==81) {
        return 1;
    }
    int x=u/9,y=u%9;
    if(m[x][y]>0) {
        bool b=d(u+1);
        if(b) {
            an[x][y]=m[x][y];
            return 1;
        }
        return 0;
    }
    REP1(i,9) {
        if(r[i][x]||c[i][y]||v[i][wv(x,y)]) continue;
        r[i][x]=1,c[i][y]=1,v[i][wv(x,y)]=1;
        bool b=d(u+1);
        if(b) {
            an[x][y]=i;
            return 1;
        }
        r[i][x]=0,c[i][y]=0,v[i][wv(x,y)]=0;
    }
    return 0;
}
signed main() {
    IOS();
    REP(i,9) {
        REP(j,9) {
            char ch;
            cin>>ch;
            m[i][j]=ch-'0';
            if(r[m[i][j]][i]||c[m[i][j]][j]||v[m[i][j]][wv(i,j)]) ok=0;
            if(m[i][j]>0) {
                r[m[i][j]][i]=1;
                c[m[i][j]][j]=1;
                v[m[i][j]][wv(i,j)]=1;
            }
        }
    }

    if(ok) {
        int r=d(0);
        if(r) {
            REP(i,9) {
                REP(j,9) cout<<an[i][j]<<" ";
                cout<<"\n";
            }
        }
        else cout<<"no answer!\n";
    }
    else cout<<"no answer!\n";
    /*

    if(ok) {
        int r=d(0);
        if(r) {
            REP(i,9) {
                if(i%3==0) {
                    cout<<" ";
                    REP(j,10) cout<<"¡X";cout<<"\n";
                }
                REP(j,9) {
                    if(j%3==0) cout<<"¡U";
                    else cout<<" ";
                    cout<<an[i][j]<<"";
                }
                cout<<"¡U\n";
            }
            cout<<" ";
            REP(i,10) cout<<"¡X";cout<<"\n";
        }
        else cout<<"no answer!\n";
    }
    else cout<<"no answer!\n";

    */
    return 0;
}
/*
000000000
000000000
000000000
000000000
000000000
000000000
000000000
000000000
000000000
*/
