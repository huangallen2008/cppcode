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
#define MD(x,M) (((x)%(M)+(M))%(M))
#ifdef LOCAL
#define op(x) cout<<(#x)<<"="<<(x)<<", ";
#define ope(x) cout<<(#x)<<"="<<(x)<<endl;
#define oparr(x) cout<<(#x)<<":";REP(i,(x).size()) cout<<x[i]<<" ";cout<<" size="<<(x).size()<<endl;
#define entr cout<<endl;
#else
#define op(x) ;
#define ope(x) ;
#define oparr(x) ;
#define entr ;
#endif
const int mod=1e9+7;
const int maxn=2e5+5;
const int maxv=1e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
//shuffle(a,a+n,rng)
int h,m,q;
void upd(int x,int y,vector<int> &d) {
    vector<int> v={x%10,x/10,y%10,(y/10)%10,y/100};
    sort(ALL(v));
    do{
        int h2=v[0]*10+v[1],m2=v[2]*100+v[3]*10+v[4];
        if(h2>=h||m2>=m) continue;
        int time=MD(m*(h2-x)+(m2-y),m*h);
        d[time]++;
    }while(next_permutation(ALL(v)));
}
signed main() {
    IOS();
    cin>>h>>m>>q;
    vector<int> d(h*m);
    REP(x,h) {
        REP(y,m) {
            upd(x,y,d);
        }
    }
    REP(i,q) {
        int h1,m1,h2,m2;
        char sth;
        cin>>h1>>sth>>m1>>h2>>sth>>m2;
        int dis=MD((h1-h2)*m+(m1-m2),m*h);
        int an=d[dis];
        cout<<an<<'\n';
    }
    return 0;
}
