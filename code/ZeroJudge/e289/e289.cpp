#include<bits/stdc++.h>
using namespace std;
int m,n,r=0,c=0,an=0;
vector<double> a(200000),t;
int mp[200000]={};
main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>m>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    t=a;
    sort(a,a+n);
    for(int i=0;i<n;i++) {
        t[i]=lower_bound(a,a+n,t[i])-a;
        if(i>=m) {
            mp[t[i-m]]--;
            c-=(mp[t[i-m]]==0);
        }
        mp[t[i]]++;
        c+=(mp[t[i]]==1);
        if(c==m) an++;
    }
    cout<<an<<"\n";
    return 0;
}
