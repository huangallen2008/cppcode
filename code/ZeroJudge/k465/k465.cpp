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
struct node {
    int cnt=0;
    vector<node*> c;
    node() {
        cnt=0;
        c=vector<node*>(26,nullptr);
    }
};
node a;
signed main()
{
    IOS();
    int n;
    cin>>n;
    vector<string> v(n);
    REP(i,n) cin>>v[i];
    REP(i,n) {
        node *t=&a;
        for(char x:v[i]) {
            if(t->c[x-'A']==nullptr)
                t->c[x-'A']=new node();
            t->c[x-'A']->cnt++;
            t=t->c[x-'A'];
        }
    }
    REP(i,n) {
        int an=0;
        node *t=&a;
        for(char x:v[i]) {
            an+=(t->c[x-'A']->cnt)-1;
            t=t->c[x-'A'];
        }
        cout<<an<<"\n";
    }
    return 0;
}
