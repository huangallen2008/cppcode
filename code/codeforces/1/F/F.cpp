#include<bits/stdc++.h>
using namespace std;
int s[]
main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int T,n,m,a[200001],b[200001],l,r,s[200001]={},l=0,o=0,f=0;
    cin>>T;
    while(T--) {
        map<int,int> m;
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i=0;i<n;i++) if(a[i]==b[i]) s[i]=1;
        for(int i=0;i<m;i++) {
            cin>>l>>r;
            m[l-1]++;
            m[r-1]--;
        }
        while(l<n) {
            if(a[l]) {
                while(a[l]) { l++; }
            }
            if(l<n && )
        }
    }
    return 0;
}
