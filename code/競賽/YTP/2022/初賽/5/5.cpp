#include<bits/stdc++.h>
using namespace std;
int T,x,y,z,n,q,ps=-1,l=0,r=-1,h[500001]={};
vector<int> p,a[500001];
main() {
    for(int i=2;i<500000;i++) {
        if(a[i].size()) continue;
        for(int j=i;j<=500000;j+=i) a[j].push_back(i);
    }
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>T;
    while(T--) {
        cin>>n>>q;
        for(int i=0;i<n;i++) {
            cin>>x;
            p.push_back(x);
        }
        for(int i=0;i<q;i++) {
            cin>>x>>y>>z;
            x+=ps; y+=ps;
            for(int j=r+1;j<=y;j++) {
                for(int k=0;k<a[p[j]].size();k++) h[a[p[j]][k]]++;
            }
            for(int j=l;j<x;j++) {
                for(int k=0;k<a[p[j]].size();k++) h[a[p[j]][k]]--;
            }
            r=y;
            l=x;
            cout<<h[z]<<"\n";
        }
        ps+=n;
    }
    return 0;
}
