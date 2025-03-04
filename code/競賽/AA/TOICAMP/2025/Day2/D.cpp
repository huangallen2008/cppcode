#include<bits/stdc++.h>
using namespace std;
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,sse4,bmi2,popcnt")
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
#define Vi vector<int>
#define Vpii vector<pii>
#ifdef LOCAL_
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) {cout<<(#x)<<":";for(auto allen:(x)) cout<<allen<<" ";cout<<" size="<<(x).size()<<endl;}
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
template<typename T1,typename T2>
ostream& operator<<(ostream& os,pair<T1,T2> p) { return os<<'{'<<p.f<<','<<p.s<<'}'; }
template<typename T1,typename T2>
istream& operator>>(istream& os,pair<T1,T2> &p) { return os>>p.f>>p.s; }
template<typename S>
ostream& operator<<(ostream& os,vector<S> p) { for(auto allen:p) os<<allen<<' ';return os<<'\n'; }
template<typename S>
istream& operator>>(istream& os,vector<S> &p) { for(auto &allen:p) os>>allen;return os; }
template<typename T1,typename T2>
pair<T1,T2> operator+(pair<T1,T2> p1,pair<T1,T2> p2) { return pair<T1,T2>(p1.f+p2.f,p1.s+p2.s); }
const int mod=998244353;
const int maxn=5;
const int maxb=64;
const int inf=1ll<<60;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
signed main() {
    IOS();    
    int n,_;
    cin>>n>>_;
    vector<Vi> a(n,Vi(3));
    a.pb({});
    REP(i,n) REP(j,3) cin>>a[i][j];
    set<int> rest;
    vector<set<pii>> ai(n+1);
    REP(i,n) REP(j,3) ai[a[i][j]].insert({i,j});
    int nid=n;
    REP(i,n) rest.insert(i);
    Vpii an;
    REP(___,n-1) {
        for(int i:rest) {
            set<pii> id0=ai[a[i][2]];
            Vpii id;
            for(auto [x,y]:id0) id.pb({x,y});
            sort(ALL(id),[&](pii a,pii b) { return a.s>b.s; });
            if(id[1].s==0) continue;
            multiset<int> q;
            auto move=[&](int x,int y) {
                if(x==y)return;
                an.pb({x,y});
                int val=a[x].back();
                ai[val].erase({x,SZ(a[x])-1});
                a[y].pb(val);
                ai[val].insert({y,SZ(a[y])-1});
                a[x].pop_back();
                q.insert(x);
            };
            move(id[0].f,nid);
            int ssz=SZ(a[id[1].f]);
            auto diff=[&](int x) ->int{
                if(*q.begin()==x) return *q.rbegin();
                else return *q.begin();
            };
            REP(j,ssz-1-id[1].s) {
                int val=diff(id[1].f);
                move(id[1].f,val);
                q.erase(q.find(val));
            } 
            move(id[1].f,nid);
            int sz=a[id[2].f].size();
            RREP(j,sz) {
                if(j==id[2].s) {
                    move(id[2].f,nid);
                }else {
                    int val=diff(id[2].f);
                    move(id[2].f,val);
                    q.erase(q.find(val));
                }
            } 
            nid=id[2].f;
            rest.erase(id[2].f);
            break;
        }
    }
    cout<<SZ(an)<<'\n';
    for(auto [x,y]:an) cout<<x+1<<' '<<y+1<<'\n';
    return 0;
}