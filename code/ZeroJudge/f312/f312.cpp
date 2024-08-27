#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a1,b1,c1,a2,b2,c2,n,an=INT_MIN;
	cin>>a1>>b1>>c1>>a2>>b2>>c2>>n;
	for(int i=0;i<=n;i++)
        if(a1*i*i+b1*i+c1+a2*(n-i)*(n-i)+b2*(n-i)+c2>an)
            an=a1*i*i+b1*i+c1+a2*(n-i)*(n-i)+b2*(n-i)+c2;
    cout<<an;
    return 0;
}
