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
#define Graph vector<vector<int>>
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define START clock_t start,end;start=clock();ifstream cin;ofstream cout;
#define END end=clock();cout.close();std::cout<<fixed<<setprecision(3)<<"time:"<<double(end-start)/CLOCKS_PER_SEC<<"s\n";
//#define cin in
const int inf=(1ll<<62);
const int maxn=2e5+5;
const int mod=1e9+7;
struct T {
    int i,r,c,w;
};
struct com {
    bool operator()(T a,T b) {
        if(a.w==b.w) return a.i>b.i;
        return a.w<b.w;
    }
};
signed main() {
    IOS();
    int n,m;
    cin>>n>>m;
    vector<vector<T>> v(m);
    REP(i,n) {
        int l,r,c,w;
        cin>>l>>r>>c>>w;
        l--,r--;
        v[l].pb({i,r,c,w});
    }
    priority_queue<T,vector<T>,com> pq;
    REP(i,m) {
        int b;
        cin>>b;
        int an=0;
        for(auto p:v[i]) pq.push(p);
        while(pq.size()) {
            auto [k,r,c,w]=pq.top();
            pq.pop();
            if(i>r) continue;
            if(c>b) {
                an+=b*w;
                pq.push({k,r,c-b,w});
                break;
            }
            else {
                an+=c*w;
                b-=c;
            }
        }
        cout<<an<<" ";
    }
    cout<<"\n";
    return 0;
}
