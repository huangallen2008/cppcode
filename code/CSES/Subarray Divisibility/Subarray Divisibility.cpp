#include<bits/stdc++.h>
using namespace std;
int n,a;
long long s=0,an=0;
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n;
    cin>>n;
    vector<long long> b(n);
    b[0]=1;
    for(int i=0;i<n;i++) {
        cin>>a;
        s+=a;
        b[(s%n+n)%n]++;
    }
    for(int i=0;i<n;i++) an+=b[i]*(b[i]-1)/2;
    cout<<an<<"\n";
    return 0;
}
