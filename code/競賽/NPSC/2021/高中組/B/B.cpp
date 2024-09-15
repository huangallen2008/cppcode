#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n+1)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)(x.size())
#define SQ(x) (x)*(x)
#define pii pair<int,int>
#define Graph vector<vector<int>>
#define eras(x,v) x.erase(x.find(v))
#define IOS() cin.sync_with_stdio(0),cin.tie(0),cout.tie(0)
const ll inf=(1ll<<63)-1;
const int maxn=1e4+5;
const ll mod=1e9+7;
ll pw(ll x,ll p,ll m=mod) {
    ll r=1;
    while(p>0) {
        if(p&1) {
            r*=x;
            r%=m;
        }
        x*=x;
        x%=m;
        p>>=1;
    }
    return r;
};
ll inv(ll x,ll m=mod) {
    return pw(x,m-2,m);
}
int n;
int sum=0;
int pm=0;
vector<pii> a;
priority_queue<int> sa;
multiset<int> se1,se2;
signed main()
{
    IOS();
    cin>>n;
    a=vector<pii>(n);
    REP(i,n) {
        cin>>a[i].s;
        sum+=a[i].s;
        se2.insert(a[i].s);
    }
    REP(i,n) {
        cin>>a[i].f;
    }
    sort(ALL(a));
    int c=0;
    REP(i,n) {
        while(a[c].f==i) sa.push(a[c++].s);
        if(sa.size()) {
            if(se1.count(sa.top())>=1) {
                eras(se1,sa.top());//se1.erase(se1.find(sa.top()));
                se1.insert(*se2.begin());
                pm+=*se2.begin()-sa.top();
                eras(se2,*se2.begin());//se2.erase(se2.find(*se2.begin()));
            }
            else {
                eras(se2,sa.top());//se2.erase(sa.top());
            }
            sa.pop();
        }
        else {
            se1.insert(*se2.begin());
            pm+=*se2.begin();
            eras(se2,*se2.begin());//se2.erase(se2.find(*se2.begin()));
        }
        cout<<sum-pm<<(i==n-1?"\n":" ");
    }
    return 0;
}
