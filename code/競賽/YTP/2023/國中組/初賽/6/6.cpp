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
const int inf=(1ll<<62);
const int maxn=2e5+5;
const int mod=1e9+9;
vector<int> a;
struct seg {
    int c=1,f=1;
};
vector<seg> s(maxn*4);
void b(int w,int l,int r) {
    s[w]={1,1};
    if(l==r) {
        return;
    }
    int m=(l+r)/2;
    b(w*2,l,m);
    b(w*2+1,m+1,r);
}
void uf(int w,int l,int r,int ul,int ur,int v) {
    if(l<=ul&&ur<=r) {
        if(s[w].c>1) {
            s[w*2].c=s[w*2].f*s[w*2].c*s[w].c;
            s[w*2].f=1;
            s[w*2+1].c=s[w*2+1].f*s[w*2+1].c*s[w].c;
            s[w*2+1].f=1;
            s[w].c=1;
        }
        s[w].f*=v;
        return;
    }
    if(l>ur||r<ul) return;
    int m=(l+r)/2;
    uf(w*2,l,m,ul,ur,v);
    uf(w*2+1,m+1,r,ul,ur,v);
}
void uc(int w,int l,int r,int ul,int ur,int v) {
    if(l<=ul&&ur<=r) {
        if(s[w].f>1) {
            s[w*2].f=s[w*2].f*s[w*2].c*s[w].f;
            s[w*2].c=1;
            s[w*2+1].f=s[w*2+1].f*s[w*2+1].c*s[w].f;
            s[w*2+1].c=1;
            s[w].f=1;
        }
        s[w].c*=v;
        return;
    }
    if(l>ur||r<ul) return;
    int m=(l+r)/2;
    uc(w*2,l,m,ul,ur,v);
    uc(w*2+1,m+1,r,ul,ur,v);
}
int qu(int w,int l,int r,int k) {
    if(l==r) {
        if(s[w].f>1) return a[k]/s[w].f;
        else if(s[w].c>1) return (a[k]+s[w].c-1)/s[w].c;
        else return a[k];
    }
    int m=(l+r)/2;
    if(s[w].f>1) {
        s[w*2].f=s[w*2].f*s[w*2].c*s[w].f;
        s[w*2].c=1;
        s[w*2+1].f=s[w*2+1].f*s[w*2+1].c*s[w].f;
        s[w*2+1].c=1;
        s[w].f=1;
    }
    if(s[w].c>1) {
        s[w*2].c=s[w*2].f*s[w*2].c*s[w].c;
        s[w*2].f=1;
        s[w*2+1].c=s[w*2+1].f*s[w*2+1].c*s[w].c;
        s[w*2+1].f=1;
        s[w].c=1;
    }
    if(k<=m) return qu(w*2,l,m,k);
    else return qu(w*2+1,m+1,r,k);
}
signed main()
{
    IOS();
    int n,q;
    cin>>n>>q;
    a=vector<int>(n);
    REP(i,n) cin>>a[i];
    b(1,0,n-1);
    REP(i,q) {
        char c;
        cin>>c;
        if(c=='f') {
            int x,y,z;
            cin>>x>>y>>z;
            x--,y--;
            uf(1,0,n-1,x,y,z);
        }
        else if(c=='c') {
            int x,y,z;
            cin>>x>>y>>z;
            x--,y--;
            uc(1,0,n-1,x,y,z);
        }
        else {
            int x;
            cin>>x;
            x--;
            cout<<qu(1,0,n-1,x)<<"\n";
        }
    }
    return 0;
}
