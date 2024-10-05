#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
<<<<<<< HEAD
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
const int maxn=2e5+5;
const int inf=(1ll<<62);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rd(int l,int r) {
    return uniform_int_distribution<int>(l,r)(rng);
}
=======
const int inf=(1ll<<62);
const int maxn=6e5+5;
const int mod=1e9+7;
>>>>>>> 0b1a1b11a3c05bbc53306c9c4fc912c08c4ad5ba
struct edge {
    int x1,y1,x2,y2;
};
int x0;
int n,m;
vector<edge> edges;
void f(int a,int b,int c,int d) {
<<<<<<< HEAD
    if(x0+a&&x0+b&&x0+c&&x0+d)edges.pb({x0+a,x0+b,x0+c,x0+d});
=======
    edges.pb({x0+a,x0+b,x0+c,x0+d});
>>>>>>> 0b1a1b11a3c05bbc53306c9c4fc912c08c4ad5ba
}
//u
bool sa(edge a,edge b) {
    if(a.x1==b.x1&&a.x2==b.x2&&a.y1==b.y1&&a.y2==b.y2) return 1;
    return 0;
}
bool ine(int x1,int y1,int x2,int y2) {
    for(int i=0;i<edges.size();i++) if(sa(edges[i],{x1,y1,x2,y2})||sa(edges[i],{x2,y2,x1,y1})) return 1;
    return 0;
}

int ok() {
    vector<vector<int>> d(n+1,vector<int>(m+1));
    d[1][1]=1;
    REP1(i,n) {
        REP1(j,m) {
            if(i>1&&!ine(i,j,i-1,j)) d[i][j]+=d[i-1][j];
            if(j>1&&!ine(i,j-1,i,j)) d[i][j]+=d[i][j-1];
        }
    }
<<<<<<< HEAD
    REP1(i,n) {
        cout<<"  ";REP1(j,m) {
            cout<<"0 ";
            if(ine(i,j,i,j+1)) cout<<"| ";
            else cout<<"  ";
        }entr
        REP1(j,m) {
            if(ine(i,j,i+1,j)) cout<<"----";
            else cout<<"    ";
        }
        entr
    }
    return d[n][m];
}

void solve(int t) {
    edges.clear();
    // int t;
    // cin>>t;
=======
    return d[n][m];
}

//u
signed main()
{
    IOS();
    int t;
    cin>>t;
>>>>>>> 0b1a1b11a3c05bbc53306c9c4fc912c08c4ad5ba
    int t1=t;
    vector<int> a;
    while(t>0) {
        a.pb(t%20);
        t/=20;
    }
    REP(i,a.size()-1) {
        x0=i*3+1;
        if(i>0) {
            f(1,-1,1,0);
            f(2,-1,2,0);
            f(3,-1,3,0);
            f(-1,1,0,1);
            f(-1,2,0,2);
            f(-1,3,0,3);
            f(-1,4,0,4);
            f(4,-1,5,-1);
            f(-1,5,-1,6);
        }
        f(2,3,2,4);
        f(1,4,2,4);
        f(4,0,5,0);
        f(4,1,5,1);
        f(0,5,0,6);
        f(1,5,1,6);
        if(a[i]<10) f(3,2,4,2);
        else a[i]-=10;
        if(a[i]<8) f(1,3,1,4);
        else a[i]-=4;
        if(a[i]<4) f(3,1,4,1);
        else a[i]-=4;
        if(a[i]<2) f(0,3,0,4);
        else a[i]-=2;
        if(a[i]==0) f(3,0,4,0);
    }
    n=a.size()*3+3;
    m=a.size()*3+3;
    x0=a.size()*3-2;
    int y=a.back();
    if(x0>1) {
        f(1,-1,1,0);
        f(2,-1,2,0);
        f(3,-1,3,0);
        f(4,-1,4,0);
        f(-1,1,0,1);
        f(-1,2,0,2);
        f(-1,3,0,3);
        f(-1,4,0,4);
    }
    f(1,1,2,1);
    f(1,2,2,2);
    f(1,3,2,3);
    f(1,4,2,4);
    f(3,1,4,1);
    f(3,2,4,2);
    f(3,3,4,3);
    f(3,4,4,4);
    if(y==19) {
        n++;
        if(x0>0) f(5,-1,5,0);
        f(5,1,6,1);
        f(5,2,6,2);
        f(5,3,6,3);
        f(5,4,6,4);
    }
    else {
        if(y<18) {
            int r=max(y-13,(int)0);
            f(0,r,0,r+1);
        }
        if(y<13) {
            int r=max(y-8,(int)0);
            f(2,r,2,r+1);
        }
        if(y<8) {
            int r=max(y-3,(int)0);
            f(4,r,4,r+1);
        }
    }
    if(y==2) f(3,0,4,0);
    if(y==1) f(1,0,2,0);
    cout<<n<<" "<<m<<"\n";
    cout<<edges.size()<<"\n";
    for(auto [x1,y1,x2,y2]:edges) cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
<<<<<<< HEAD
    
    // int tt=ok();
    // if(tt!=t1) {
    //     cerr<<t<<" "<<t1<<" "<<tt<<endl;
    //     cerr<<"no!!!!!"<<endl;
    // }
    // else cerr<<"yes"<<endl;
}
signed main()
{
    IOS();
    // freopen("out.txt","w",stdout);
    // int T=10000;
    // cin>>T;
    // while(T--){
    //     int rn=rd(1000000,1e18);
    //     solve(rn);
    // }
    int T;
    cin>>T;
    // assert(T!=19);
    // while(cin>>R) {
        solve(T);
    // }
=======
/*
    int tt=ok();
    cout<<t1<<" "<<tt<<endl;
    if(tt==t1) cout<<"yes!!"<<endl;
    else cout<<"no!!!!!"<<endl;


>>>>>>> 0b1a1b11a3c05bbc53306c9c4fc912c08c4ad5ba
    /*
    vector<vector<int>> r(10,vector<int>(10));
    for(auto [x1,y1,x2,y2]:edges) {
        r[x1][y1]++;
        r[x2][y2]++;
    }
    REP(i,10) {
        REP(j,10)cout<<r[i][j]<<" ";cout<<endl;
    }*/
    return 0;
}
