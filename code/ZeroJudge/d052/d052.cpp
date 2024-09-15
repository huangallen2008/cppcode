#include<bits/stdc++.h>
using namespace std;
main()
{
    int T;
    cin>>T;
    for(int c=0;c<T;c++) {
        int n,a[4005]={};
        cin>>n;
        vector<int> v;
        for(int i=n-1;i>=0;i--) {
            cin>>a[i];
            a[n*2-i-1]=a[i];
        }
        for(int i=0;i<n*2;i++) {
            int x=a[i];
            if(i==0)
                v.push_back(x);
            else {
                if(x>v[v.size()-1])
                    v.push_back(x);
                else
                    v[lower_bound(v.begin(),v.end(),x)-v.begin()]=x;
            }
        }
        cout<<v.size()<<"\n";
    }
    return 0;
}
