#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int inf=(1ll<<63)-1;
const int mod=1e9+7;
const int maxn=2e5+5;
int m,n,k;
int c=0;
int an1=0,an2=0,qn=0;
vector<int> p,s;
vector<pii> d={{0,1},{1,0},{0,-1},{-1,0}};
Graph g;
int find(int u) {
    if(p[u]==u) return u;
    return p[u]=find(p[u]);
}
void merge(int x,int y) {
    int a=find(x),b=find(y);
    if(x!=y) {
        p[a]=b;
        s[b]+=s[a];
        qn=max(qn,s[b]);
        s[a]=0;
    }
}
int id(int i,int j) { return i*n+j; }
bool ok(int a,int b) {
    if(a<0||a>=m||b<0||b>=n) return 0;
    return 1;
}
signed main() {
    IOS();
    cin>>m>>n>>k;
    g=Graph(m,vector<int>(n,1));
    p=vector<int>(m*n);
    s=vector<int>(m*n);
    REP(i,m*n) p[i]=i;
    REP(i,m) {
        REP(j,n) {
            cin>>g[i][j];
            if(g[i][j]==0) {
                s[id(i,j)]=1;
                qn=max(qn,(int)1);
                c++;
                if(i>0&&g[i-1][j]==0) {
                    if(find(id(i,j))!=find(id(i-1,j))) {
                        c--;
                        merge(id(i,j),id(i-1,j));
//                        qn=max(qn,s[id(i-1,j)]);
                    }
                }
                if(j>0&&g[i][j-1]==0) {
                    if(find(id(i,j))!=find(id(i,j-1))) {
                        c--;
                        merge(id(i,j),id(i,j-1));
//                        qn=max(qn,s[id(i,j-1)]);
                    }
                }
            }
        }
    }
//    cout<<"  "<<qn<<" "<<c<<endl;
    an2+=qn;
    an1+=c;
    REP(i,k) {
        int x,y;
        cin>>x>>y;
        x--; y--;
        g[x][y]=0;
        s[id(x,y)]=1;
        c++;
        REP(di,4) {
            int xx=x+d[di].f,yy=y+d[di].s;
            if(ok(xx,yy)) {
                if(g[xx][yy]==0) {
                    if(find(id(x,y))!=find(id(xx,yy))) {
                        c--;
                        merge(id(x,y),id(xx,yy));
//                        qn=max(qn,s[id(xx,yy)]);
                    }
                }
            }
        }
        an2+=qn;
        an1+=c;
//        cout<<"  "<<qn<<" "<<c<<endl;
    }
    cout<<an1<<endl<<an2<<endl;
    return 0;
}
