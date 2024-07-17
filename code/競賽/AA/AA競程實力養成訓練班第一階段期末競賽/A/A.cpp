#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3,unroll-loops,fast-math")
// #pragma GCC target("avx2,bmi,popcnt")
#define int long long
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<=(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define RREP1(i,n) for(int i=(n);i>=1;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) (int)((x).size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define pipii pair<int,pii>
#define Graph vector<vector<int>>
#define Graphw vector<vector<pii>>
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define md(x) (((x)%(mod)+(mod))%(mod))
#define MD(x,M) (((x)%(M)+(M))%(M))
#define ld long double
#define pdd pair<ld,ld>
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define addmod(x,y) x=((x+(y))%mod)
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";for(auto &allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=1e4+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
int dirtoi(char d) {
    if(d=='R') return 0;
    if(d=='U') return 1;
    if(d=='L') return 2;
    return 3;
}
vector<pii> dir={{0,1},{-1,0},{0,-1},{1,0}};
struct so {
    bool operator()(pii a,pii b) {
        if(a.f==b.f) return a.s>b.s;
        else return a.f>b.f;
    }
};
struct ag {
    int t,x,y,dir,id;
    char c;
};
bool so_ag(ag a,ag b){
    if(a.t==b.t) return a.id<b.id;
    return a.t<b.t;
}
int r,c,n;
bool ok(int x,int y) {
    if(x<0||x>=r||y<0||y>=c) return 0;
    return 1;
}
signed main() {
    IOS();
    cin>>r>>c>>n;
    vector<vector<char>> m(r,vector<char>(c,'#'));
    priority_queue<pii,vector<pii>,so> pq;
    vector<ag> a(n);
    vector<char> ch(n);
    vector<int> d(n);
    vector<int> nx(n);
    vector<int> ny(n);
    REP(i,n) {
        char dd;
        cin>>a[i].x>>a[i].y>>a[i].t>>dd>>a[i].c;
        a[i].x--,a[i].y--;
        a[i].id=i;
        ch[i]=a[i].c;
        a[i].dir=dirtoi(dd);
        d[i]=a[i].dir;
        nx[i]=a[i].x,ny[i]=a[i].y;
    }
    int it=0;
    sort(ALL(a),so_ag);
    int nt=0;
    while(1) {
        if(pq.empty()) {
            if(it==n) break;
            nt=a[it].t;
        }
        else nt=pq.top().f;
        while(it<n&&a[it].t==nt) {
            auto [t,x,y,d,id,c]=a[it++];
            if(m[x][y]!='#') continue;
            pq.push({t,id});
        }
        while(pq.size()&&pq.top().f==nt) {
            auto [t,id]=pq.top();
            pq.pop();
            int x=nx[id],y=ny[id],di=d[id];
            char c=ch[id];
            if(m[x][y]!='#') continue;
            m[x][y]=c;
            int xx=x+dir[di].f,yy=y+dir[di].s;\
            if(!ok(xx,yy)) continue;
            if(m[xx][yy]!='#') continue;
            nx[id]=xx,ny[id]=yy;
            pq.push({t+1,id});
        }
    }
    REP(i,r) {
        REP(j,c) cout<<m[i][j];
        cout<<'\n';
    }
    return 0;
}