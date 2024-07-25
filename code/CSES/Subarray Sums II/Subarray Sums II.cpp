#include<bits/stdc++.h>
using namespace std;
int n,k,a;
long long s=0,an=0;
map<long long,int> b;
main()
{
    cin>>n>>k;
    vector<long long> s(n);
    b[0]=1;
    for(int i=0;i<n;i++) {
        cin>>a;
        s[i]=(i==0?0:s[i-1])+a;
        an+=b[s[i]-k];
        b[s[i]]++;
    }
    cout<<an<<"\n";
    return 0;
}
