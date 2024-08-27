#include<bits/stdc++.h>
using namespace std;
int n,m;
double an=1;
vector<vector<pair<int,int>>> a(17,vector<pair<int,int>>(17,{0,0}));
double co(pair<int,int> a,pair<int,int> b,pair<int,int> c) {
    double an=0;
    if(a.first==b.first) an++;
    if(a.first==c.first) an++;
    if(a.first==b.second) an++;
    if(a.first==c.second) an++;
    if(a.second==b.first) an++;
    if(a.second==c.first) an++;
    if(a.second==b.second) an++;
    if(a.second==c.second) an++;
    return an;
}
double f(double x) {
    if(x==0) return 8;
    if(x==1) return 6;
    if(x==2) return 4;
    if(x==3) return 3;
    if(x==4) return 2;
}
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin>>a[i][j].first>>a[i][j].second;
            an*=f(co(a[i][j],a[i-1][j],a[i][j-1]))/(double)4;
            cout<<co(a[i][j],a[i-1][j],a[i][j-1])<<"\n";
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) cout<<a[i][j].first<<" "<<a[i][j].second<<"\n";cout<<"\n";
    }
    cout<<(long long)an%(long long)m<<"\n";
    return 0;
}
