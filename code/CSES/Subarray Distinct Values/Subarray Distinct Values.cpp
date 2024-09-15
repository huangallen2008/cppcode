#include<bits/stdc++.h>
using namespace std;
int n,k,c=0;
long long an=0,l=0,r=0;
map<int,int> m;
main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    while(l<n) {
        while(r<n && c+(m[a[r]]==0)<=k) {
            c+=(m[a[r]]==0);
            m[a[r]]++;
            r++;
        }
        an+=r-l;
        c-=(m[a[l]]==1);
        m[a[l++]]--;
    }
    cout<<an<<"\n";
    return 0;
}
