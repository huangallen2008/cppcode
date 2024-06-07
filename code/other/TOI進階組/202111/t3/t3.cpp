#include<bits/stdc++.h>
using namespace std;
int n,q,s[400005]={},a=0,b=0;
main()
{
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>s[i];
    }
    cin>>q;
    map<int,int> m;
    m[s[0]]++;
    for(int i=0;i<q;i++) {
        int l,r;
        cin>>l>>r;
        if(a>l)
            for(int j=l;j<a;j++)
                m[s[j]]++;
        else
            for(int j=a;j<l;j++)
                m[s[j]]--;
        if(b>r)
            for(int j=r;j<b;j++)
                m[s[j]]=1;
        else
            for(int j=b;j<r;j++)
                m[s[j]]=1;
        cout<<m.size()<<endl;
    }
	return 0;
}
