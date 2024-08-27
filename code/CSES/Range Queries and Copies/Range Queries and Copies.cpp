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
const int maxn=2e5+5;
const int mod=1e9+7;
struct node {
    int su=0;
    int l,r;
    node *lc,*rc;
    void pull() {
        su=lc->su+rc->su;
    }
};
node* build(int l,int r) {
    node* root=new node;
    root->l=l; root->r=r;
    if(l==r) return root;
    int m=(l+r)/2;
    root->lc=build(l,m);
    root->rc=build(m+1,r);
    return root;
}
node* ud(node* _root ,int p,int v) {
    node* root=new node(*_root);
    if(root->l==root->r) {
        root->su=v;
        return root;
    }
    int m=(root->l+root->r)/2;
    if(p<=m) {
        root->lc=ud(root->lc,p,v);
    }else {
        root->rc=ud(root->rc,p,v);
    }
    root->pull();
    return root;
}
int qu(node* root,int ql,int qr) {
    if(ql<=root->l&&root->r<=qr) return root->su;
    if(ql>root->r||qr<root->l) return 0;
    return qu(root->lc,ql,qr)+qu(root->rc,ql,qr);
}
signed main()
{
    IOS();
    int n,q;
    cin>>n>>q;
    vector<node*> root(2);
    root[1]=build(1,n);
    vector<int> a(n+1);
    REP1(i,n) cin>>a[i];
    REP1(i,n) root[1]=ud(root[1],i,a[i]);
    REP(i,q) {
        int cmd;
        cin>>cmd;
        if(cmd==1) {
            int k,p,x;
            cin>>k>>p>>x;
            root[k]=ud(root[k],p,x);
        }else if(cmd==2) {
            int k,l,r;
            cin>>k>>l>>r;
            cout<<qu(root[k],l,r)<<'\n';
        }else {
            int k;
            cin>>k;
            root.pb(root[k]);
        }
    }
    return 0;
}
