#include<bits/stdc++.h>
using namespace std;
main()
{
    int m,an=0;
    string a[50005]={};
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>a[i];
    sort(a,a+m);
    unordered_set<string> u(a,a+m);
    for(int i=0;i<m;i++) {
        for(int w=1;w*2<a[i].size();w++) {
            string f=a[i].substr(0,w),l=a[i].substr(a[i].size()-w);
            if(f==l) {
                string t=a[i].substr(w,a[i].size()-w*2);
                if(u.count(t)) an++;
            }
        }
    }
    cout<<an<<"\n";
    return 0;
}
