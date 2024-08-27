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
const int inf=(1ll<<63)-1;
const int maxn=1e5+5;
const int mod=1e9+7;
string s;
int n;
vector<int> a;
struct T {
    int v=0,n1=-1,n2=0;
};
T f(int u,int lo) {
//    cout<<"["<<u<<endl;
    T an;
    int l=-1;
    while(u<a.size()) {
        if(a[u]>=10) {
            if(l!=-1) an.v+=abs(l-a[u]);
            l=a[u];
            if(an.n1==-1) an.n1=a[u];
            an.n2=a[u];
        }
        else if(a[u]>=0) {
            int c=1;
            int x=u;
            while(c>0) {
                x++;
                if(a[x]>=0&&a[x]<10) c++;
                if(a[x]==-1) c--;
            }
            T p=f(u+1,a[u]);
            an.v+=p.v;
            if(l!=-1) an.v+=abs(l-p.n1);
            l=p.n2;
            u=x;
            if(an.n1==-1) an.n1=p.n1;
            an.n2=p.n2;
        }
        else {
            an.v=an.v*lo+abs(an.n1-an.n2)*(lo-1);
//            cout<<an.v<<"]\n";
            return an;
        }
        u++;
    }
    an.v=an.v*lo+abs(an.n1-an.n2)*(lo-1);
//    cout<<an.v<<"]\n";
    return an;
}
signed main()
{
    IOS();
    cin>>s;
    n=s.size();
    REP(i,n) {
        if(s[i]=='T') {
            a.pb((s[i+1]-'0')*10+(s[i+2]-'0'));
            i+=2;
        }
        else if(s[i]=='L') {
            a.pb(s[i+1]-'0');
            i++;
        }
        else a.pb(-1);
    }
    T an=f(0,1);
    cout<<an.v+abs(an.n1-10)<<"\n";
    return 0;
}
