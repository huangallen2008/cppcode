#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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
const ll inf=(1ll<<63)-1;
const int maxn=1e5+5;
const ll mod=1e9+7;
int n0,n2;
int c0=inf,c1;
vector<int> a1,a2;
bool b1=1,b2=1;
signed main() {
    IOS();
    cin>>n0>>n2;
    REP(i,n2/11+1) {
        if((n2-11*i)%2==0) {
            c0=(n2+11*i)/2;
            c1=(n2-11*i)/2;
            break;
        }
    }
    if(c0==inf) {
        cout<<-1<<"\n";
    }
    else {
        REP(i,n0+n2) {
            if(i%2) {
                if(i/2<c1) a1.pb(2);
                else a1.pb(0);
            }
            else {
                if(i/2<c0) a1.pb(2);
                else a1.pb(0);
            }
        }
        REP(i,n0+n2) {
            if(i%2) {
                if(i/2<c1) a2.pb(2);
                else a2.pb(0);
            }
            else {
                if(i/2<c0) a2.pb(2);
                else a2.pb(0);
            }
        }
        a2=a1;
        reverse(ALL(a2));
        RREP(i,n0+n2-2) {
            if(a1[i]==2&&a1[i+2]==0) {
                swap(a1[i],a1[i+2]);
                b1=0
                break;
            }
        }
        RREP(i,n0+n2-2) {
            if(a2[i]==0&&a2[i+2]==2) {
                swap(a2[i],a2[i+2]);
                b2=0
                break;
            }
        }
        REP(i,n0+n2) cout<<a1[i];cout<<"\n";
        REP(i,n0+n2) cout<<a2[i];cout<<"\n";
    }
    return 0;
}
