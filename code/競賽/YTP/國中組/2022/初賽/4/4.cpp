#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define int double
#define FOR(i,a,b) for (int i = (a); i<(b); i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for (int i=(n)-1; i>=0; i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int, int>
#define MD(x,m) ((x)%(m)+(m))%(m)
#define md(x) MD(x,mod)
#define lbs(x,y) *lower_bound(ALL(x),y)
#define lb(x,y) lower_bound(ALL(x),y)-x.begin()
#define ubs(x,y) *upper_bound(ALL(x),y)
#define ub(x,y) upper_bound(ALL(x),y)-x.begin()
#define IOS() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const ll inf = 1ll<<62;
const int iinf=2147483647;
const ll mod = 1e9+9;
const ll maxn=1e5+5;
const double PI=acos(-1);
ll pw(ll x, ll p, ll m=mod){
    ll ret=1;
    while (p>0){
        if (p&1){
            ret*=x;
            ret%=m;
        }
        x*=x;
        x%=m;
        p>>=1;
    }
    return ret;
}
#define db double
int n,h,k;
int jg,jo,jm;
int gc=0,oc=0,mc=0;
double d;
int vi,ci=0;
double ki;
int x,y;
int ad=0;
int cr=0;
int an=0;
int mxc=0;
db td=0;
vector<int> p,c,adk;
string ps,cs;
main() {
    cout<<fixed<<setprecision(2);
    IOS();
    cin>>n>>h>>d>>k;
    p=vector<int>(n);
    adk=vector<int>(n+1);
    c=vector<int>(h);
    REP(i,n) cin>>p[i];
    cin>>ps;
    REP(i,h) cin>>c[i];
    cin>>cs;
    REP(I,k) {
        cin>>x>>y;
        int lid=lb(p,x),rid=ub(p,y);
        adk[lid]+=1;
        adk[rid]-=1;
    }
    jg=49.5-3*d;
    jo=79.5-8*(d-5);
    if(d<=5) jm=94.5-8*(d-5);
    else jm=94.5-5*(d-5);
    REP(i,n) {
        ki=1;
        ad+=adk[i];
        if(ad>0) ki+=0.2;
        vi=0;
        int id=lower_bound(c.begin()+cr,c.end(),p[i]-jm)-c.begin();
        if(cr>=h) {
            mc++; vi=0; ci=0;
        }
        else if(c[id]<=p[i]+jm) {
            int dis=abs(p[i]-c[id]);
            if(ps[i]!=cs[id]) {
                mc++; vi=0; ci=0;
            }else if(dis<=jg) {
                gc++; vi=300; ci++;
            }else if(dis<=jo) {
                oc++; vi=150; ci++;
            }else {
                mc++; vi=0; ci=0;
            }
            cr=id+1;
        }
        else {
            mc++; vi=0; ci=0;
        }
        an+=(vi+min((int)(max(ci-1,(int)0)/10),(int)10)*80)*ki;
        mxc=max(mxc,ci);
    }
    td=(gc+0.5*(db)oc)/n*100.0;
    cout<<an<<'\n';
    cout<<gc<<' '<<oc<<' '<<mc<<'\n';
    cout<<td<<"\n";
    cout<<mxc<<'\n';
    return 0;
}
