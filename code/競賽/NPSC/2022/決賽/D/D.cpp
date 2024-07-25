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
int n,m;
int x,y;
vector<int> p(maxn),c(maxn);
vector<int> an;
bool ok=1;
signed main()
{
    IOS();
    cin>>n>>m;
    REP1(i,n) p[i]=i;
    REP1(i,n) c[i]=i;
    REP(i,m) {
        cin>>x>>y;
        if((p[x]!=x&&p[x]!=y)||(c[y]!=y&&c[y]!=x)||ok==0) {
            ok=0;
        }
        else {//1 x y 2 -> 1 y x 2   p:xy2 yx2 c:1xy 1yx
            p[x]=y;
            c[y]=x;
            int v1=c[x],v2=x,v3=y,v4=p[y];
            bool xc=1,yp=1;
            if(v1==x) xc=0;
            if(v4==y) yp=0;
            if(xc) {
                p[v1]=v3;
                c[v3]=v1;
            }
            else c[v3]=v3;
            p[v3]=v2;
            c[v2]=v3;
            if(yp) {
                p[v2]=v4;
                c[v4]=v2;
            }
            else p[v2]=v2;
        }
    }
    int cnt=0;
    REP1(i,n) {
        if(c[i]==i) {
            x=i;
            while(p[x]!=x) {
                an.pb(x);
                x=p[x];
                if(cnt++>=n) {
                    ok=0;
                    break;
                }
            }
            an.pb(x);
            if(cnt++>=n) {
                ok=0;
                break;
            }
        }
        if(!ok) break;
    }
    //REP(i,n) cout<<an[i]<<" ";cout<<"\n\n";
    if(ok) {
        cout<<"Yes\n";
        REP(i,n) cout<<an[i]<<(i<n?' ':'\n');
    }
    else cout<<"No\n";
    return 0;
}
/*
4 2
2 3
1 4

4 2
2 3
2 3


*/
