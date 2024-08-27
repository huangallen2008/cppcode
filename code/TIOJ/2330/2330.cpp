#include<bits/stdc++.h>
using namespace std;
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
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) ((x%(mod)+(mod))%(mod))
#define op(x) cout<<#x<<"="<<x<<", ";
#define ope(x) cout<<#x<<"="<<x<<endl;
#define oparr(x) cout<<#x<<":";REP(i,x.size()) cout<<x[i]<<" ";cout<<" size="<<x.size()<<endl;
#define entr cout<<endl;
const int inf=(int)9e18;
const int maxn=1e5+5;
const int mod=1e9+7;
struct S {
    int dis,cost,hid;
};
bool so(S a,S b) {
    if(a.dis==b.dis) {
        if(a.cost==b.cost) {
            return a.hid<b.hid;
        }
        else return a.cost<b.cost;
    }
    else return a.dis<b.dis;
}
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<pii> ms(m),ho(n);
    vector<int> cost(n);
    vector<S> a;
    REP(i,n) cin>>ho[i].f>>ho[i].s>>cost[i];
    REP(i,m) cin>>ms[i].f>>ms[i].s;
    REP(i,n) {
        int dis=inf;
        REP(j,m) {
            dis=min(dis,SQ(ho[i].f-ms[j].f)+SQ(ho[i].s-ms[j].s));
        }
        a.pb({dis,cost[i],i+1});
    }
    sort(ALL(a),so);
    REP(i,n) cout<<a[i].hid<<'\n';
    return 0;
}
