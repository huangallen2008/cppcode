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
bool sw=0;
vector<pii> v;
signed main() {
    IOS();
    cin>>n>>m;
    if(n>m) {
        swap(n,m);
        sw=1;
    }
    if(n==2) {
        if(m<5) cout<<"-1\n";
        else {
            for(int i=2;i<m;i++) {
                v.pb({0,i});
                v.pb({1,i-2});
            }
            v.pb({0,0});
            v.pb({1,m-2});
            v.pb({0,1});
            v.pb({1,m-1});
            v.pb({0,2});
        }
    }
    else {
        if(n==3&&m==3) cout<<"-1\n";
        else {
            REP(i,m-2) {
                REP(j,n) {
                    if(j%2) v.pb({j,i+2});
                    else v.pb({j,i});
                }
            }
            REP(rd,2) {
                int rd1=rd;
                if(n==m&&(n%2)==1) rd1=(rd1+1)%2;
                REP(i,n) {
                    if(i%2) v.pb({i,rd1});
                    else v.pb({i,m+rd1-2});
                }
            }
            v.pb({0,0});
        }
    }
    for(auto [x,y]:v) {
        if(sw) swap(x,y);
        cout<<x+1<<" "<<y+1<<"\n";
    }
    int lx=v[0].f,ly=v[0].s;
    bool fi=1,ok=1;
    for(auto [x,y]:v) {
        if(fi) {fi=0;continue;}
        if(x==lx||y==ly||abs(x-lx)==abs(y-ly)) {
            ok=0;
            cout<<"nono";
            cout<<x<<" "<<y<<"\n";
            break;
        }
        lx=x;ly=y;
    }

    return 0;
}
