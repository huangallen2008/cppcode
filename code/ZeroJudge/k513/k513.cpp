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
signed main()
{
    IOS();
    int s,m,l,n;
    cin>>s>>m>>l>>n;
    vector<int> x(n),a(3);
    REP(i,n) cin>>x[i];
    REP(i,n) {
        if(x[i]<200) a[0]++;
        else if(x[i]>=500) a[2]++;
        else a[1]++;
    }
    int an=0;
    if(s<a[0]) {
        an+=s;
        a[0]-=s;
        s=0;
        if(m<a[0]) {
            an+=m;
            a[0]-=m;
            m=0;
            if(l<a[0]) {
                an+=l;
                a[0]-=l;
                l=0;
            } else {
                an+=a[0];
                l-=a[0];
                a[0]=0;
            }
        } else {
            an+=a[0];
            m-=a[0];
            a[0]=0;
        }
    } else {
        an+=a[0];
        s-=a[0];
        a[0]=0;
    }
    if(m<a[1]) {
        an+=m;
        a[1]-=m;
        m=0;
        if(l<a[1]) {
            an+=l;
            a[1]-=l;
            l=0;
        } else {
            an+=a[1];
            l-=a[1];
            a[1]=0;
        }
    } else {
        an+=a[1];
        m-=a[1];
        a[1]=0;
    }
    if(l<a[2]) {
        an+=l;
        a[2]-=l;
        l=0;
    } else {
        an+=a[2];
        l-=a[2];
        a[2]=0;
    }
    cout<<an<<"\n";
    return 0;
}
